#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "trie.h"

#define NUM_CHARS 256

typedef struct trie_t {
	bool terminal;
	struct trie_t *children[NUM_CHARS];
} trie_t;

trie_t *trie_create_node()
{
	trie_t *new_node = malloc(sizeof *new_node);

	for (int i = 0; i < NUM_CHARS; i++) {
		new_node->children[i] = NULL;
	}

	new_node->terminal = false;

	return new_node;
}

bool trie_insert(trie_t **root, const char *signed_text) 
{
	if (*root == NULL) {
		*root = trie_create_node();
	}

	unsigned char *text = (unsigned char *) signed_text;
	trie_t *temp = *root;

	int length = strlen(signed_text);

	for (int i = 0; i < length; i++) {
		if (temp->children[text[i]] == NULL) {
			// create a new node
			temp->children[text[i]] = trie_create_node();
		}

		temp = temp->children[text[i]];
	}

	if (temp->terminal) {
		return false;
	} else {
		temp->terminal = true;
		return true;
	}
}

static void trie_recursive_printf(trie_t *node, unsigned char *prefix, 
					int length)
{
	// unsigned char new_prefix[length + 2];
	unsigned char *new_pre = malloc((length + 2) * sizeof(unsigned char));
	memcpy(new_pre, prefix, length);
	new_pre[length + 1] = 0;

	if (node->terminal) {
		printf("WORD: %s\n", prefix);
	}

	for (int i = 0; i < NUM_CHARS; i++) {
		if (node->children[i] != NULL) {
			new_pre[length] = i;
			trie_recursive_printf(node->children[i], new_pre, 
						length + 1);
		}
	}
	free(new_pre);
}

void trie_printf(trie_t *root)
{
	if (root == NULL) {
		printf("Trie is empty\n");
	}

	trie_recursive_printf(root, NULL, 0);
}

bool trie_search(trie_t *root, const char *signed_text) 
{
	unsigned char *text = (unsigned char *) signed_text;
	int length = strlen(signed_text);
	trie_t *temp = root;

	for (int i = 0; i < length; i++) {
		if (temp->children[text[i]] == NULL) {
			return false;
		}

		temp = temp->children[text[i]];
	}

	return temp->terminal;
}

static bool trie_node_has_children(trie_t *node) 
{
	if (node == NULL) {
		return false;
	}

	for (int i = 0; i < NUM_CHARS; i++) {
		if (node->children[i] != NULL) {
			// there is at least 1 kid
			return true;
		}
	}
	return false;
}

static trie_t *trie_recursive_delete(trie_t *node, unsigned char *text, 
					bool *deleted)
{
	if (node == NULL) {
		return node;
	}

	if (*text == '\0') {
		if (node->terminal) {
			node->terminal = false;
			*deleted = true;

			if (trie_node_has_children(node) == false) {
				free(node);
				node = NULL;
			}
		}
		return node;
	}

	node->children[text[0]] = trie_recursive_delete(node->children[text[0]]
							, text + 1, deleted);

	if (*deleted && 
		trie_node_has_children(node) == false && 
		node->terminal == false) {
			free(node);
			node = NULL;
	}
	return node;
}

bool trie_delete_str(trie_t **root, const char *signed_text)
{
	unsigned char *text = (unsigned char *) signed_text;
	
	bool result = false;

	if (*root == NULL) {
		return false;
	}

	*root = trie_recursive_delete(*root, text, &result);
	return result;
}
