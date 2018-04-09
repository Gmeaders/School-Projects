#include <stdlib.h>
#include <stdio.h>
#include "mylist.h"

// allocate dynamic memory for a new list
list_t *new_list(void)
{
	
	return (list_t *)calloc(1, sizeof(list_t));

}

// create a new node and append it to the tail of the list
void append_back(list_t *list, int data)
{
	node_t *current_node = list->head;
	node_t *new_node = (node_t *)calloc(1, sizeof(node_t));
	new_node->data = data;

	if(list->head == NULL)
	{
		list-> head = new_node;
	}
	else
	{
		while(current_node != NULL && current_node -> next != NULL)
		{
			current_node = current_node -> next;
		}
	current_node->next = new_node;
	}
	
}

// create a new node and prepend it to the head of the list
void append_front(list_t *list, int data)
{
	node_t *new_node;
	new_node = (node_t *)calloc(1, sizeof(node_t));

	new_node->next = list->head;
	list->head = new_node;
	new_node->data = data;
	

}

// remove the tail node from the list
// return the data stored in the removed node
int remove_back(list_t *list)
{
	// delcare local variables
	int data = -1;
	node_t *current_node = list->head;
	node_t *previous_node;
	
	// find the second-to-last node
	while (current_node != NULL && current_node->next != NULL)
	{
		previous_node = current_node;
		current_node = current_node->next;
	}
	
	// did we find the second-to-last node?
	if (previous_node != NULL && current_node != NULL)
	{
		// set the second-to-last node to be the tail
		previous_node->next = NULL;
		
		// save the data and delete the old tail
		data = current_node->data;
		free(current_node);
	}
	else if (current_node != NULL)
	{
		data = current_node->data;
		list->head = NULL;
		free(current_node);
	}

	return data;
}

// remove the head node from the list
// return the data stored in the removed node
int remove_front(list_t *list)
{
	int val;
	node_t *current = list->head;	
	val = list -> head -> data;
	list -> head = list -> head -> next;
	free(current);
	return val;
}

// return the data contained in the node specified by index
int get_data_at(list_t *list, int index)
{

	int i;
	node_t *current_node = list->head;
	

	for (i = 1; current_node != NULL && i <= index; ++i)
	{
		current_node = current_node->next;
	}

	i = current_node ->data;
	return i;
}

// insert a new node containing the specified data into the list
// the index of the new node should be what is specified by the index parameter
void insert_at(list_t *list, int index, int data)
{
	// delcare local variables
	int i;
	node_t *current_node = list->head;
	node_t *new_node = (node_t *)calloc(1, sizeof(node_t));
	new_node->data = data;
	

	// find the node previous to the insertion index
	for (i = 1; current_node != NULL && i < index; ++i)
	{
		current_node = current_node->next;
	}
	
	// are we inserting at the head?
	if (index == 0)
	{
		new_node->next = list->head;
		list->head = new_node;
	}
	// did we find the previous node?
	else if (current_node != NULL)
	{
		new_node->next = current_node->next;
		current_node->next = new_node;
	}
	// invalid index... cannot insert... just deallocate the new node
	else
	{
		free(new_node);
	}
}

// remove the node at the specified index
// return the data stored in the removed node
int remove_at(list_t *list, int index)
{
	// declare local variables
	int i, data;
	node_t *current_node = list->head;
	node_t *previous_node;
	
	// find the node to remove
	for (i = 0; current_node != NULL && i < index; ++i)
	{
		previous_node = current_node;
		current_node = current_node->next;
	}
	
	// did we find the node to remove as well as the previous node?
	if (previous_node != NULL && current_node != NULL)
	{
		previous_node->next = current_node->next;
		
		// save the data and deallocate the node
		data = current_node->data;
		free(current_node);
	}
	// is this the first node (i.e., the head)?
	else if (current_node != NULL)
	{
		list->head = current_node->next;
		
		// save the data and deallocate the node
		data = current_node->data;
		free(current_node);
	}
	
	return data;
}

// print the list to standard output
void print(list_t *list)
{
	node_t *current_node = list->head;
	int first = 1;
	while (current_node != NULL)
	{
		if (first)
		{
			printf("[ %d", current_node->data);
			first = 0;
		}
		else
		{
			printf(", %d", current_node->data);
		}
		current_node = current_node->next;
	}
	
	if (first)
	{
		printf("[ ]\n");
	}
	else
	{
		printf(" ]\n");
	}
}
