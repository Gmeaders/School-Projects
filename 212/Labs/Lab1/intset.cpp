#include <iostream>
#include <assert.h>
#include "intset.h"

using namespace std;

Intset::Intset()
{

  head = new NODE;
  head->next = NULL;
  
}

Intset::~Intset()
{
  delete head; 
}

/* Return true if key is in the set */
bool Intset::find(int key)
{

  NODE *curr = head->next;
  while(curr != NULL)
  {
	if(curr->x == key)
	{
		return true;
	}
	curr = curr->next;
  }
  return false;
}

/* Inserts a new key.  It is an error if key is already in the set. */
void Intset::insert(int key)
{
  assert (!find(key));
  NODE *curr = head->next;
  NODE *insert = new NODE;
  insert->x = key;
  insert->next = NULL;
  NODE *b4 = head;

  if(curr == NULL)
  { 
	head->next = insert;
	return;
  }

  while(curr)
  {
	if((curr->x > key))
	  {
		insert->next = curr;
		b4->next = insert;
		return;
	  }
	else if((curr->x < key) && (curr->next == NULL))
	  {
		insert->next = NULL;
		curr->next = insert;
		return;
	  } 
	b4 = curr;   
	curr = curr->next;
  }
}

/* Removes a key.  It is an error if key isn't in the set */
void Intset::remove(int key)
{

  assert (find(key));
  NODE *curr = head->next;

  while(curr)
  {
	if(curr->x == key)
	{
		NODE *thing = head;
		while(thing)
		{
			if(thing->next == curr)
			{
				curr = thing;
				thing = thing->next;
				curr->next = thing->next;
				delete thing;
			}
			thing = thing->next;
		}
	}
	curr = curr->next;
  }
}
void Intset::print(void)
{
  
  NODE *curr = head->next;
  while(curr != NULL)
  {
	cout<< curr->x << "\n";
	curr = curr->next;
  }
}
