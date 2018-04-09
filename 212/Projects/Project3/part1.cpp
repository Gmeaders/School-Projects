/* Greg Meaders
   10/28/14
   Homework 3
   cpsc212
   Iterative.cpp
*/
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
const int size = 936;
int *B= new int[size];

struct Edge {
  int destination_index; 
  Edge *next_edge;
  Edge(int val, Edge *n) {
    destination_index = val;
    next_edge = n;
  };
};

struct Point{
    int index;
    int position;
    Edge *edge;
    Point(){index = -1; edge = NULL;};
};

void rev(Point *A, int L, int R){
    
    if(R == L) return;
     
	int temp = A[L].position;
	A[L].position = A[R].position;
	A[R].position = temp;
	
	temp = B[A[L].position];
	B[A[L].position] = B[A[R].position];
	B[A[R].position] = temp;
}

int distance(Point *A)
{
    int dist = 0;
    for(int i = 0; i < size; i++)
    {
        for(Edge *curr = A[i].edge; curr != NULL; curr = curr->next_edge)
        {
            int pew = A[i].position - A[curr->destination_index].position;
            dist += pew * pew;
        }
    }
    return dist/2;
}

int dist2(Point *A, int x, int y)
{
    int dist = 0;
    for(Edge *curr = A[x].edge; curr != NULL; curr = curr->next_edge)
        {
            int pew = (A[x].position - A[curr->destination_index].position);
            dist += pew * pew;
        }
        
    for(Edge *curr = A[y].edge; curr != NULL; curr = curr->next_edge)
        {
            if(curr->destination_index != x)
            {
                int pew = (A[y].position - A[curr->destination_index].position);
                dist += pew * pew;
            }
         }
    return dist;
}

bool refine(Point *A, int &distA)
{
    int dist = distA;   
    for(int i =0; i < size - 1; i++)
    {
            int temp = dist;
            dist -= dist2(A, B[i], B[i+1]);
            rev(A, B[i], B[i+1]);
            dist += dist2(A, B[i], B[i+1]);                      
            if(dist < distA)
            {
             distA = dist; //compare was d
             return true;
            }
            rev(A, B[i], B[i+1]); 
            dist = temp;              
     }
     return false;
}

void jostle(Point *A)
{
    int temp;
    
    for(int i = 1; i < size; i++)
    {
        int random = rand()%i ;
        rev(A, i, random);

    }
}

int main(void)
{
    srand(time(NULL));
    ifstream fin;
    Point *wires = new Point[size];
    int coolarray[size];
    
    for(int i = 0; i < size; i++)
    {
        wires[i].edge = NULL;
        wires[i].index = i;
        coolarray[i] = 0;
    }
    int a, b;
    fin.open("wires.txt");

    while(fin >> a >> b)
    {
        wires[a].position = a;
        wires[a].edge = new Edge(b, wires[a].edge);
        wires[b].position = b;
        wires[b].edge = new Edge(a, wires[b].edge); 
        B[a] = a;
        B[b] = b;
    }
    fin.close();
    int min_dist = distance(wires);
    int times = 0;
    while(min_dist > 1000000)
    {     
        jostle(wires);
        
        int dist = distance(wires);
        while(refine(wires, dist));
        if(dist < min_dist)
        {
            for(int i = 0; i <size; i++)
            {
            coolarray[wires[i].position] = i;
            }
         
         min_dist = dist;
        } 
        
    }
   
   cout << min_dist << endl;
   
   for(int i = 0; i < size; i++)
    {
        cout << coolarray[i] << endl;
    } 
          
          
   return 0;
}

