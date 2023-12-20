#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "trie.h"

int main()
{
	trie_t *root = NULL;

	printf("\n---Create a trie---\n");
	trie_insert(&root, "KIT");
	trie_insert(&root, "CATTLE");
	trie_insert(&root, "KIN");
	trie_insert(&root, "CAT");
	trie_insert(&root, "HAPPY");
	trie_printf(root);

	printf("\n---Search for some words---\n");
	printf("Search for CATTLE: %d\n", trie_search(root, "CATTLE"));
	printf("Search for CAT: %d\n", trie_search(root, "CAT"));
	printf("Search for KITTEN: %d\n", trie_search(root, "KITTEN"));

	printf("\n---Delete some words and re-print---\n");
	trie_delete_str(&root, "KIN");
	trie_delete_str(&root, "CAT");
	trie_printf(root);

	trie_delete_str(&root, "KIT");
	trie_delete_str(&root, "CATTLE");
	trie_delete_str(&root, "HAPPY");

}