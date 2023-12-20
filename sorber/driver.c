#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "trie.h"

int main()
{
	trie_t *root = NULL;

	trie_insert(&root, "KIT");
	trie_insert(&root, "CATTLE");
	trie_insert(&root, "KIN");
	trie_insert(&root, "CAT");
	trie_insert(&root, "HAPPY");

	trie_printf(root);

	printf("Search for CATTLE: %d\n", trie_search(root, "CATTLE"));
	printf("Search for CAT: %d\n", trie_search(root, "CAT"));
	printf("Search for KITTEN: %d\n", trie_search(root, "KITTEN"));

	trie_delete_str(&root, "KIN");
	trie_delete_str(&root, "CAT");
	trie_printf(root);

}