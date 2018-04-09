#ifndef MYLIST_H
#define MYLIST_H

typedef struct s_node {
	int	data;
	struct s_node *next;
} node_t;

typedef struct s_list {
	node_t *head;
} list_t;

list_t *new_list(void);
void append_back(list_t *list, int data);
void append_front(list_t *list, int data);
int remove_back(list_t *list);
int remove_front(list_t *list);
int get_data_at(list_t *list, int index);
void insert_at(list_t *list, int index, int data);
int remove_at(list_t *list, int index);
void print(list_t *list);

#endif