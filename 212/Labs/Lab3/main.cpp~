#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int b = 1500; //Started with b at 100 and went up by 100 until i found the fastest, after 1500 it started to slow down a little bit each time


struct Node{
  double x;
  double y;
  Node *next;
  Node(double ecks, double why, Node *n) { x = ecks; y = why; next = n; }
  Node() { x = 1; y = 1; next = NULL; }
};

double distance(double shortest, Node *n1, Node *n2)
{
    
    double x1 = n1->x;
    double y1 = n1->y;
    double x2 = n2->x;
    double y2 = n2->y;
    double sum1 = x1-x2;
    double sum2 = y1-y2;
    sum1 = sum1*sum1;
    sum2 = sum2*sum2;
    double rad = sum1 + sum2;
    double new_dist = sqrt(rad);
    if(new_dist < shortest && new_dist != 0)
    {
        return new_dist;
    }
    return shortest;
}

double search(double shortest, Node ***box, Node *node, int i, int j)
{
    Node *current;
    int m;
    int n;
    for(m = i - 1; m <= i + 1; m++)
    {
        for(n = j - 1; n <= j + 1; n++)
        {
            if( m >= 0 && m < b && n >= 0 && n < b)
            {
                current = box[m][n];
                while(current != NULL)
                {
                   shortest = distance(shortest, node, current);
                   current = current->next;
                }
             }
         }
     }
     return shortest;
}

 
int main(void)
{
     double shortest = 1000;
     Node ***box = new Node**[b];
     for (int i = 0; i < b; i++) {
        box[i] = new Node*[b];
        for (int j = 0; j < b; j++) {
            box[i][j] = NULL;
        }
    }
 
     double x,y;
     int hash1;
     int hash2;
     ifstream fin;
     fin.open("points.txt");
     while(fin>>x>>y){
         hash1 = x * b;
         hash2 = y * b;
         box[hash1][hash2] = new Node(x, y, box[hash1][hash2]);
     }
     fin.close();
     
     for(int c = 0; c < b; c++)
     {
        for(int d = 0; d < b; d++)
        {   
           while(box[c][d])
           {
                shortest = search(shortest, box, box[c][d], c, d);
                box[c][d] = box[c][d]->next;
           }
        }
     }
     
     Node *current;
     for(int d1 = 0; d1 < b; d1++)
     {
        for(int d2 = 0; d2 < b; d2++)
        {
            while(box[d1][d2])
            {
                current = box[d1][d2];
                box[d1][d2] = box[d1][d2]->next;
                delete current;
            }
        }
        delete[] box[d1];
     }
     
     delete[] box;
     cout << "The shortest distance between two points is: " << shortest << endl;
     return 0;
}
      
     
    

