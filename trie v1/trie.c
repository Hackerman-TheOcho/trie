#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

#define CHAR_SIZE 26

typedef struct trie_t {
    trie_t *character[CHAR_SIZE];
    int is_leaf;
} trie_t;


trie_t *trie_create()
{
	// return a new trie node
        trie_t *node = calloc(1, sizeof(trie_t));
	node->is_leaf = 0;

	for (int i = 0; i < CHAR_SIZE; i++) {
		node->character[i] = NULL;
	}

	return node;
}

void trie_insert(trie_t *head, const char *str)
{
	// insert a string into the trie, start from root node
	trie_t *node = head;
	while (*str) {
		// create new node if path doesn't exist
		if (node->character[*str - 'a'] == NULL) {
			node->character[*str - 'a'] = trie_create();
		}

		// go to next node
		node = node->character[*str - 'a'];

		// next character
		str++;
	}
	// mark current node as a leaf
	node->is_leaf = 1;
}

int trie_search(trie_t *head, const char *str)
{
	// return 0 if trie is empty
	if (head == NULL) {
		return 0;
	}

	trie_t *node = head;
	while (*str) {
		// go to next node
		node = node->character[*str - 'a'];

		// if string is invalid, (reached end of path)
		if (node == NULL) {
			return 0;
		}

		str++;
	}

	// return 1 if current node is a leaf and end of string is reached
	return node->is_leaf;
}

int trie_children(trie_t *node)
{
	// return 0 if node does not exist
	if (node == NULL) {
		return 0;
	}

	for (int i = 0; i < CHAR_SIZE; i++) {
		if (node->character[i]) {
			// child found
			return 1;
		}
	}
	return 0;
}

int trie_delete(trie_t **node, const char *str)
{
	// return 0 if trie is empty
	if (*node == NULL) {
		return 0;
	}

	// iff end of string is not reached
	if (*str) {
		if (*node != NULL && (*node)->character[*str - 'a'] != NULL &&
			trie_delete(&((*node)->character[*str - 'a']), str + 1)
			&& (*node)->is_leaf == 0) {
				if (!trie_children(*node)) {
					free(*node);
					(*node) = NULL;
					return 1;
				} else {
					return 0;
				}
			}
	}

	// if end of string is reached
	if (*str == '\0' && (*node)->is_leaf) {
		if (!trie_children(*node)) {
			free(*node);
			(*node) = NULL;
			return 1;
		} else {
			/*
			 * if current node is leaf and has children
			 * make current node as non-leaf (don't delete)
			 */ 
			(*node)->is_leaf = 0;
			return 0;
		}
	}

	return 0;
}

// static void trie_recursive_printf(trie_t *node, unsigned char *prefix, int length)
// {
// 	unsigned char new_prefix[length + 2];
// 	// unsigned char *new_prefix = malloc((length + 2) * sizeof(unsigned char));
// 	memcpy(new_prefix, prefix, length);
// 	new_prefix[length + 1] = 0;

// 	if (node->is_leaf) {
// 		printf("WORD: %s\n", prefix);
// 	}

// 	for (int i = 0; i < CHAR_SIZE; i++) {
// 		if (node->character[i] != NULL) {
// 			new_prefix[length] = i;
// 			trie_recursive_printf(node->character[i], new_prefix, 
// 						length + 1);
// 		}
// 	}
// 	// free(new_prefix);
// }

// void trie_printf(trie_t *node)
// {
// 	if (node == NULL) {
// 		printf("Trie is empty\n");
// 	}

// 	trie_recursive_printf(node, NULL, 0);
// }



