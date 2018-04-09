#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
using namespace std;

struct Node{
  double x;
  double y;
  Node *next;
  Node(double ecks, double why, Node *n) { x = ecks; y = why; next = n; }
  Node() { x = 0.0; y = 0.0; next = NULL; }
};

class hash
{
    private:

void insert(double x, double y)
{

}
int main(void)
{
    
    ifstream file;
    file.open("points.txt");
    string line;
    if(file.is_open())
    {
        while(getline(file, line))
        {
            double x, y;
            istringstream in(line);
            in >> x;
            in >> y;
        }
     }
     
     int b = 100;
     Node ***box = new Node**[b];
     for (int i = 0; i < b; i++) {
        box[i] = new Node*[b];
        for (int j = 0; j < b; j++) {
            box[i][j] = NULL;
        }
    }
    
}
