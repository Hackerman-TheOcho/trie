#include <stdio.h>
#include <stdlib.h>

#include "trie.h"

int main()
{
	trie_t *head = trie_create();

	trie_insert(head, "hello");
	printf("%d ", trie_search(head, "hello"));	// print 1

	trie_insert(head, "helloworld");
	printf("%d ", trie_search(head, "helloworld"));	// print 1

	printf("%d ", trie_search(head, "helll"));	// print 0 (not present)

	trie_insert(head, "hell");
	printf("%d ", trie_search(head, "hell"));	// print 1

	trie_insert(head, "h");
	printf("%d \n", trie_search(head, "h"));	// print 1 + newline

	trie_printf(head);

	trie_delete(&head, "hello");
	printf("%d ", trie_search(head, "hello"));	// print 0 (hello deleted)
	printf("%d ", trie_search(head, "helloworld"));	// print 1
	printf("%d \n", trie_search(head, "hell"));	// print 1 + newline

	trie_delete(&head, "h");
	printf("%d ", trie_search(head, "hh"));		// print 0 (h deleted)
	printf("%d ", trie_search(head, "hell"));	// print 1
	printf("%d \n", trie_search(head, "helloworld"));	// print 1 + newline

	trie_delete(&head, "helloworld");		
	printf("%d ", trie_search(head, "helloworld"));	// print 0
	printf("%d ", trie_search(head, "hell"));	// print 1

	trie_delete(&head, "hell");
	printf("%d \n", trie_search(head, "hell"));	// print 0 + newline

	if (head == NULL) {
		printf("Trie is empty\n");		// trie is empty
	}

	printf("%d \n", trie_search(head, "hell"));	// print 0

	return 0;
}