/* Greg Meaders
   9/18/14
   Homework 1
   cpsc212
   stringset.cpp
*/
#include <iostream>
#include <string.h>
#include <assert.h>
#include "stringset.h"

using namespace std;

//Code reused from lab

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
int Stringset::find(string key)
{
  int h = hash(key, size);
  Node *n = table[h];
  while (n != NULL) {
    if (n->key == key) return n->ID;
    n = n->next;
  }
  return -2;
}

/* Inserts a new key.  It is an error if key is already in the set. */
bool Stringset::insert(string key, int val)
{
  if(find(key) != -2)
  {
    return false;
  }  
  num_elems++;

  //Re-sizing the table
  if (num_elems == size) {
    num_elems = 0;
	size = size * 2;
	Node **oldtable;
	oldtable = table;
	table = allocate_table(size);
	for(int i = 0; i < size /2; i++)
	{
		Node *curr = oldtable[i];
		while(curr != NULL)
		{
			insert(curr->key, curr->ID);
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
	table[h] = new Node(key, val, NULL);
  	return true;
  }
  else if(n != NULL)
  {
	while(n->next != NULL)
	{
	  n = n->next;
	}
	n->next = new Node(key, val, NULL);
  	return true;
  }
}

