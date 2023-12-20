#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct trie_t trie_t;

trie_t *trie_create_node();

bool trie_insert(trie_t **root, const char *signed_text);

void trie_printf(trie_t *root);

bool trie_search(trie_t *root, const char *signed_text);

bool trie_delete_str(trie_t **root, const char *signed_text);

