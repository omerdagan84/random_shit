#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node { //node structure
     int value;
     struct Node *next;
    struct Node *previous;
} node;

node *list_add ( int value, node *head )
{
	node *list_iterator = head;
	node *new_node;
	new_node = (node *)malloc( sizeof(node) );
	new_node->value = value;
	while ( list_iterator->next != head )
		list_iterator = list_iterator->next;
	/* now the iterator is at the node before the head */
	new_node->next = head;
	new_node->previous = list_iterator;

	head->previous = new_node;
	list_iterator->next = new_node;

}
int main()
{
	node *list_head;
	list_head = (node *)malloc( sizeof(node) );
	list_head->next = list_head;
	list_head->previous = list_head;
	list_head->value = 0;

}
