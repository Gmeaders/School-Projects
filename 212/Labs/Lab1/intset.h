#ifndef INTSET_H /* Prevent multiple inclusion... */
#define INTSET_H


struct NODE{
	int x;
	NODE *next;
};

class Intset {

 private: 
  NODE *head;

 public:
  Intset();
  ~Intset();
  bool find(int key);
  void insert(int key);
  void remove(int key);
  void print(void);
};


#endif
