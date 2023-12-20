#ifndef TRIE_H
#define TRIE_H

typedef struct trie_t trie_t;

/**
 * @brief Create a new node
 */
trie_t *trie_create();

/**
 * @brief Insert a node into trie
 * @param head root node of tree
 * @param string to insert
 * @return void
 */
void trie_insert(trie_t *head, const char *str);

/**
 * @brief Search for a node in the trie
 * @param head root node of tree
 * @param string to search for
 * @return 1 if current node is leaf and end of string is reached, else 0
 */
int trie_search(trie_t *head, const char *str);

/**
 * @brief Check if node has any children
 * @param node node to search for
 * @return return 1 if node has children, else return 0
 */
int trie_children(trie_t *node);

/**
 * @brief Delete a node
 * @param head root node of tree
 * @param string to delete
 * @return 1 for success, else 0
 */
int trie_delete(trie_t **node, const char *str);


// void trie_printf(trie_t *node);

#endif