/* Greg Meaders
   10/28/14
   Homework 3
   cpsc212
   part2.cpp
*/
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef pair<double, int> Pair;
const int size = 936;

struct Edge {
  int destination_index; 
  Edge *next_edge;
  Edge(int val, Edge *n) { destination_index = val; next_edge = n;};
};

struct Point{
  int index;
  double position;
  int v_place;
  Edge *edge;
  Point(){index = -1; edge = NULL;};
};

void jostle(Point *A)
{
    int temp;
    
    for(int i = 1; i < size-1; i++)
    {
        int random = rand()%i;
        double temp = A[i].position;
	    A[i].position = A[random].position;
	    A[random].position = temp;   
    }
}

void relax(Point *A)
{
    double convergence = 10;
    while(convergence > 0.000001)
    {   
        convergence = 0;
        for(int i = 0; i < size; i++)
        {
            double position = 0;
            double new_position = 0;
            int counter = 0;
            if(A[i].position != 0 || A[i].position != 935)
            {
                double check = A[i].position;
                for(Edge *curr = A[i].edge; curr != NULL; curr = curr->next_edge)
                {
                    position += A[curr->destination_index].position;
                    counter++;
                }
                new_position = (position / counter);
                convergence += abs(new_position-check);
                A[i].position = new_position;
            }    
        }
    }            
}
      
int distance(Point *A)
{
    int dist = 0;
    for(int i = 0; i < size; i++)
    {
        for(Edge *curr = A[i].edge; curr != NULL; curr = curr->next_edge)
        {
            int pew = A[i].v_place - A[curr->destination_index].v_place;
            dist += pew * pew;
        }
    }
    return dist/2;
}        

int main(void)
{
    srand(time(NULL));
    int coolarray[size];
    ifstream fin;
    Point *wires = new Point[size];
    
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
        wires[a].index = a;
        wires[a].edge = new Edge(b, wires[a].edge);
        wires[b].position = b;
        wires[b].index = b;
        wires[b].edge = new Edge(a, wires[b].edge); 
    }
    fin.close();
    double best_dist = 400000000;
    double start_dist = best_dist;
    vector<Pair> v;
    
    while(start_dist > 1000000)
    {
        jostle(wires);
        //random_shuffle(&wires[0], &wires[size-1]);
    
        relax(wires);
        
        for(int i = 0; i < size; i++)
        {
            v.push_back(Pair(wires[i].position, wires[i].index));
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < size; i++)
        {
            wires[v[i].second].v_place = i;
        }
        best_dist = distance(wires);
        if(best_dist < start_dist)
        {
            
            for(int i = 0; i <size; i++)
            {
                coolarray[wires[i].v_place] = i;
            }
            start_dist = best_dist;
        }   
        v.clear(); 
   }
    
   cout << start_dist << endl;
   
   for(int i = 0; i < size; i++)
   {
       cout << coolarray[i] << endl;
   }     
          
   return 0;
}

