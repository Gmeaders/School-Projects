#include <iostream>
#include <string.h>
#include <assert.h>
#include "stringset.h"

using namespace std;

/* Return a hash for the string s in the range 0..table_size-1 */
int hash(string s, int table_size)
{
  unsigned int i, h = 0;
  for (i=0; i<s.length(); i++)
    h = (h * 2917 + (unsigned int)s[i]) % table_size;
  return h;
}

/* Allocate a table of pointers to nodes, all initialized to NULL */
Node **allocate_table(int size)
{
  Node **table = new Node *[size];
  for (int i=0; i<size; i++)
    table[i] = NULL;
  return table;
}

Stringset::Stringset()
{
  size = 4; // initial size of table    
  table = allocate_table(size);
  num_elems = 0; 
}

Stringset::~Stringset()
{
  for (int i=0; i<size; i++) {
    while (table[i] != NULL) {
      Node *temp = table[i];
      table[i] = table[i]->next;
      delete temp;
    }
  }
  delete[] table;
}

/* Return true if key is in the set */
bool Stringset::find(string key)
{
  int h = hash(key, size);
  Node *n = table[h];
  while (n != NULL) {
    if (n->key == key) return true;
    n = n->next;
  }
  return false;
}

/* Inserts a new key.  It is an error if key is already in the set. */
void Stringset::insert(string key)
{
  assert (!find(key));
  num_elems++;

  if (num_elems == size) {
	size = size * 2;
	Node **oldtable;
	oldtable = table;
	table = allocate_table(size);
	for(int i = 0; i < size /2; i++)
	{
		Node *curr = oldtable[i];
		while(curr != NULL)
		{
			insert(curr->key);
	  		curr = curr->next;
		}
	}
	for (int i=0; i<size/2; i++) {
    while (oldtable[i] != NULL) {
      Node *temp = oldtable[i];
      oldtable[i] = oldtable[i]->next;
      delete temp;
    }
  }
  delete[] oldtable;
  }

  int h;
  h = hash(key, size);
  Node *n = table[h];
  if(n == NULL)
  { 
	table[h] = new Node(key, NULL);
  	return;
  }
  else if(n != NULL)
  {
	while(n->next != NULL)
	{
	  n = n->next;
	}
	n->next = new Node(key, NULL);
  	return;
  }
}

/* Removes a key.  It is an error if key isn't in the set */
void Stringset::remove(string key)
{
  assert (find(key));
  num_elems--;

  int h;
  h = hash(key, size);
  
  if(table[h]->key == key)
  { 
	Node *temp = table[h];
	table[h] = table[h]->next;
	delete temp;
  	return;
  }
  Node *n = table[h]->next;
  Node *prev = table[h];
  while(n->key != key)
  {
      prev = n;
      n = n->next;
  }
  prev->next = n->next;
  delete n;
  

}

void Stringset::print(void)
{
  for(int i = 0; i < size; i++)
  {
  	Node *curr = table[i];
  	while(curr != NULL)
	{
	  cout<< curr->key << "\n";
	  curr = curr->next;
  	}
  }
}
