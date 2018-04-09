#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct Node {
  char letter; // the character labeling the edge to this node's parent
  int parent;
  Node (char _letter, int _parent) 
  {
     letter = _letter; 
     parent = _parent; 
  }
};

vector<Node> nodes;

void print(int number)
{
    if(number == 0)
        return;
        
        
    print(nodes[number].parent);
    
    if(nodes[number].letter != -1)
    {
        cout << nodes[number].letter;
    }
}
    
int main()
{
 
  nodes.push_back(Node(0,-1));

  int a, b;
  
  while(cin >> a >> b)
  {
    nodes.push_back(Node(b, a));
    print(nodes.size() -1);
  }
  
  return 0;
}
