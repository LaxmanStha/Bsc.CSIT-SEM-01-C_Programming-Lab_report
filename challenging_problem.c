/*
Challenging Programming Problem: Advanced Trie Data Structure with Auto-Completion and Word Frequency Tracking

Problem Statement:
Implement a trie (prefix tree) data structure that supports:
1. Inserting words with frequency count
2. Searching for words with frequency information
3. Auto-completion of prefixes with sorted results (by frequency, then lexicographically)
4. Deleting words from the trie
5. Calculating the total number of words with a specific prefix

The trie should be efficient in both time and space, with the following requirements:
- All operations must have O(L) time complexity where L is the length of the word/prefix
- The trie must handle case-sensitive words
- Auto-completion must return results sorted first by frequency (descending), then lexicographically (ascending)
- The trie must support unicode characters

Solution Approach:
1. Use a dynamic trie node structure with children stored in a hash map for efficient lookups
2. Track word frequency and prefix count at each node
3. Implement a recursive traversal for auto-completion with result sorting
4. Handle deletion by recursively removing nodes that have no children and are not part of any other word
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define INITIAL_CAPACITY 10

typedef struct TrieNode {
    bool is_end_of_word;
    int frequency;
    int prefix_count;
    struct TrieNode **children;
    char *keys;
    int child_count;
    int capacity;
} TrieNode;

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

TrieNode* create_trie_node() {
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->is_end_of_word = false;
    node->frequency = 0;
    node->prefix_count = 0;
    node->children = NULL;
    node->keys = NULL;
    node->child_count = 0;
    node->capacity = 0;
    return node;
}

int find_child_index(TrieNode *node, char c) {
    for (int i = 0; i < node->child_count; i++) {
        if (node->keys[i] == c) {
            return i;
        }
    }
    return -1;
}

void insert_into_trie(TrieNode *root, const char *word) {
    if (root == NULL || word == NULL || *word == '\0') {
        return;
    }

    TrieNode *current = root;
    const char *ptr = word;

    while (*ptr != '\0') {
        char c = *ptr;
        current->prefix_count++;
        
        int child_index = find_child_index(current, c);
        
        if (child_index == -1) {
            if (current->child_count == current->capacity) {
                int new_capacity = current->capacity == 0 ? INITIAL_CAPACITY : current->capacity * 2;
                current->children = (TrieNode**)realloc(current->children, new_capacity * sizeof(TrieNode*));
                current->keys = (char*)realloc(current->keys, new_capacity * sizeof(char));
                
                if (current->children == NULL || current->keys == NULL) {
                    fprintf(stderr, "Memory reallocation failed\n");
                    exit(EXIT_FAILURE);
                }
                
                current->capacity = new_capacity;
            }
            
            current->keys[current->child_count] = c;
            current->children[current->child_count] = create_trie_node();
            child_index = current->child_count;
            current->child_count++;
        }
        
        current = current->children[child_index];
        ptr++;
    }
    
    current->is_end_of_word = true;
    current->frequency++;
    current->prefix_count++;
}

TrieNode* search_prefix(TrieNode *root, const char *prefix) {
    if (root == NULL || prefix == NULL || *prefix == '\0') {
        return NULL;
    }

    TrieNode *current = root;
    const char *ptr = prefix;

    while (*ptr != '\0') {
        char c = *ptr;
        int child_index = find_child_index(current, c);
        
        if (child_index == -1) {
            return NULL;
        }
        
        current = current->children[child_index];
        ptr++;
    }

    return current;
}

int get_word_frequency(TrieNode *root, const char *word) {
    TrieNode *node = search_prefix(root, word);
    if (node != NULL && node->is_end_of_word) {
        return node->frequency;
    }
    return 0;
}

int get_prefix_count(TrieNode *root, const char *prefix) {
    TrieNode *node = search_prefix(root, prefix);
    if (node != NULL) {
        return node->prefix_count;
    }
    return 0;
}

void collect_words(TrieNode *node, char *current_word, int index, WordFrequency *results, int *result_count, int max_results) {
    if (node == NULL || *result_count >= max_results) {
        return;
    }

    if (node->is_end_of_word) {
        current_word[index] = '\0';
        strcpy(results[*result_count].word, current_word);
        results[*result_count].frequency = node->frequency;
        (*result_count)++;
    }

    for (int i = 0; i < node->child_count; i++) {
        current_word[index] = node->keys[i];
        collect_words(node->children[i], current_word, index + 1, results, result_count, max_results);
    }
}

int compare_word_frequency(const void *a, const void *b) {
    const WordFrequency *wa = (const WordFrequency*)a;
    const WordFrequency *wb = (const WordFrequency*)b;

    if (wa->frequency != wb->frequency) {
        return wb->frequency - wa->frequency;
    }

    return strcmp(wa->word, wb->word);
}

int auto_complete(TrieNode *root, const char *prefix, WordFrequency *results, int max_results) {
    TrieNode *prefix_node = search_prefix(root, prefix);
    
    if (prefix_node == NULL) {
        return 0;
    }

    char current_word[MAX_WORD_LENGTH];
    strncpy(current_word, prefix, MAX_WORD_LENGTH - 1);
    current_word[MAX_WORD_LENGTH - 1] = '\0';
    
    int result_count = 0;
    int prefix_length = strlen(prefix);
    
    collect_words(prefix_node, current_word, prefix_length, results, &result_count, max_results);
    
    qsort(results, result_count, sizeof(WordFrequency), compare_word_frequency);
    
    return result_count;
}

bool delete_from_trie(TrieNode *root, const char *word) {
    if (root == NULL || word == NULL || *word == '\0') {
        return false;
    }

    TrieNode *current = root;
    TrieNode *last_branch_node = NULL;
    char last_branch_char = '\0';
    const char *ptr = word;

    while (*ptr != '\0') {
        char c = *ptr;
        current->prefix_count--;
        
        int child_index = find_child_index(current, c);
        
        if (child_index == -1) {
            return false;
        }
        
        if (current->child_count > 1 || (current != root && current->is_end_of_word)) {
            last_branch_node = current;
            last_branch_char = c;
        }
        
        current = current->children[child_index];
        ptr++;
    }

    if (!current->is_end_of_word) {
        return false;
    }

    if (current->child_count > 0) {
        current->is_end_of_word = false;
        current->frequency = 0;
        return true;
    }

    if (last_branch_node == NULL) {
        int child_index = find_child_index(root, word[0]);
        if (child_index != -1) {
            free(last_branch_node->children[child_index]);
            
            for (int i = child_index; i < last_branch_node->child_count - 1; i++) {
                last_branch_node->keys[i] = last_branch_node->keys[i + 1];
                last_branch_node->children[i] = last_branch_node->children[i + 1];
            }
            
            last_branch_node->child_count--;
        }
    } else {
        int child_index = find_child_index(last_branch_node, last_branch_char);
        if (child_index != -1) {
            free(last_branch_node->children[child_index]);
            
            for (int i = child_index; i < last_branch_node->child_count - 1; i++) {
                last_branch_node->keys[i] = last_branch_node->keys[i + 1];
                last_branch_node->children[i] = last_branch_node->children[i + 1];
            }
            
            last_branch_node->child_count--;
        }
    }

    return true;
}

void free_trie(TrieNode *root) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < root->child_count; i++) {
        free_trie(root->children[i]);
    }

    if (root->children != NULL) {
        free(root->children);
    }
    if (root->keys != NULL) {
        free(root->keys);
    }
    free(root);
}

void print_word_frequencies(WordFrequency *results, int count) {
    printf("Found %d results:\n", count);
    for (int i = 0; i < count; i++) {
        printf("%-20s | Frequency: %d\n", results[i].word, results[i].frequency);
    }
    printf("\n");
}

int main() {
    printf("=== Advanced Trie Data Structure ===\n\n");
    
    TrieNode *root = create_trie_node();
    
    const char *words[] = {
        "apple", "app", "application", "apples", "apricot",
        "banana", "bananas", "berry", "blueberry", "blackberry",
        "cherry", "date", "fig", "grape", "grapefruit",
        "orange", "lemon", "lime", "mango", "melon",
        "peach", "pear", "pineapple", "plum", "pomegranate"
    };
    
    int word_counts[] = {5, 3, 2, 4, 1, 3, 2, 1, 2, 1, 1, 1, 1, 2, 1, 4, 2, 1, 1, 1, 1, 1, 1, 1, 1};
    
    for (int i = 0; i < sizeof(words)/sizeof(words[0]); i++) {
        for (int j = 0; j < word_counts[i]; j++) {
            insert_into_trie(root, words[i]);
        }
    }
    
    printf("=== Trie Operations Demonstration ===\n\n");
    
    printf("1. Searching for words:\n");
    printf("   - apple: %d\n", get_word_frequency(root, "apple"));
    printf("   - app: %d\n", get_word_frequency(root, "app"));
    printf("   - application: %d\n", get_word_frequency(root, "application"));
    printf("   - nonexistent: %d\n", get_word_frequency(root, "nonexistent"));
    printf("\n");
    
    printf("2. Prefix count:\n");
    printf("   - 'app' prefix: %d words\n", get_prefix_count(root, "app"));
    printf("   - 'b' prefix: %d words\n", get_prefix_count(root, "b"));
    printf("   - 'x' prefix: %d words\n", get_prefix_count(root, "x"));
    printf("\n");
    
    printf("3. Auto-completion for 'app':\n");
    WordFrequency results[10];
    int count = auto_complete(root, "app", results, 10);
    print_word_frequencies(results, count);
    
    printf("4. Auto-completion for 'b':\n");
    count = auto_complete(root, "b", results, 10);
    print_word_frequencies(results, count);
    
    printf("5. Deleting words:\n");
    printf("   - Deleting 'app' (frequency %d)\n", get_word_frequency(root, "app"));
    delete_from_trie(root, "app");
    printf("   - 'app' frequency after deletion: %d\n", get_word_frequency(root, "app"));
    printf("   - 'app' prefix count after deletion: %d words\n", get_prefix_count(root, "app"));
    printf("\n");
    
    printf("6. Auto-completion for 'app' after deletion:\n");
    count = auto_complete(root, "app", results, 10);
    print_word_frequencies(results, count);
    
    free_trie(root);
    
    printf("=== All operations completed successfully ===\n");
    
    return 0;
}
