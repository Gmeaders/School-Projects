#include <ctime>

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct wire {
  int destination;
  wire *next;
  wire(int end, wire *n) {
    destination = end;
    next = n;
  }
};
struct node {
  int id;
  wire *wires;
  int pos_i;
  int wire_count;
  void add_wire(int end) {
    wires = new wire(end, wires);
    wire_count++;
  }
  node(int val) {
    id = val;
    wires = NULL;
    pos_i = val;
    wire_count = 0;
  }
};
int distance_i(node **network, int size) {
  int total = 0;
  for (int i = 0; i < size; ++i)
    for (wire *w = network[i]->wires; w != NULL; w = w->next) {
      int wire_length = network[w->destination]->pos_i - network[i]->pos_i;
      total += wire_length * wire_length;
    }
  return total >> 1;
}

int main() {
  ifstream in;
  in.open("wires.txt");
  int max_id = 0;
  vector<node *> *v = new vector<node *>();
  int start, end, count = -1;
  while (in >> start >> end) {
    if (!v->size() || start != (*v)[count]->id) {
      v->push_back(new node(start));
      count++;
    }
    (*v)[count]->add_wire(end);
    if (start > max_id) max_id = start;
    if (end > max_id) max_id = end;
  }
  in.close();
  int size = max_id + 1;
  node **network = new node*[size];
  for (int i = 0; i < size; ++i)
    network[i] = new node(i);
  for (unsigned int i = 0; i < v->size(); ++i) {
    while ((*v)[i]->wires != NULL) {
      start = (*v)[i]->id;
      end = (*v)[i]->wires->destination;
      network[start]->add_wire(end);
      network[end]->add_wire(start);
      wire *temp = (*v)[i]->wires;
      (*v)[i]->wires = (*v)[i]->wires->next;
      delete temp;
    }
    delete (*v)[i];
  }
  delete v;
  ifstream order;
  order.open("ordering.txt");
  int your_dist, id;
  order >> your_dist;
  for(int i = 0; i < size; ++i) {
    order >> id;
    network[id]->pos_i = i;
  }
  std::cout << "Your computed distance: " << your_dist << "\n";
  std::cout << "Actual distance: " << distance_i(network, size) << "\n";
}
