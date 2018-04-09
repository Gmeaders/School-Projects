#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;

struct place{
    double x;
    double y;
    int key;
    place(double a, double b, int k) {a = x; b = y; k = key;}
    place(){};
};

void jostle(place *town)
{
    place temp;
    int random = 0;
    for(int i=0; i < 49; i++)
    {
        random = rand() % (i + 1);
        temp = town[i];
        
        town[i] = town[random];
       
        town[random] = temp;
        
    }
}

double distance(place *seq)
{
    double dist = 0;
    int i;
    double x1, x2, y1, y2;
    for(i=0; i<49; i++)
    {
        x1 = seq[i].x;
        y1 = seq[i].y;
        x2 = seq[i+1].x;
        y2 = seq[i+1].y;
        double temp = ((x1-x2) * (x1 - x2));
        temp += (y1-y2) * (y1-y2);
        dist += sqrt(temp);
    }
    x1 = seq[49].x;
    y1 = seq[49].y;
    x2 = seq[0].x;
    y2 = seq[0].y;
    double temp = ((x1-x2) * (x1 - x2));
    temp += (y1-y2) * (y1-y2);
    dist += sqrt(temp);
    return dist;
}

void rev(place *A, int L, int R){
	if(R <= L) return;
	place temp = A[L];
	A[L] = A[R];
	A[R] = temp;
	rev(A, L + 1, R - 1);
}

bool refine(place *A)
{
    double dist = distance(A);
    for(int i =0; i < 50; i++)
    {
        for(int j=0;j<50;j++)
        {
            rev(A, i, j);
            if(distance(A) < dist) return true;
            rev(A, i, j);
        }
     }
     return false;
}
               
int main(){
    srand(time(NULL));
    int i = 0;
    double a; 
    double b;
    
    place *towns = new place[50];
    place *best = new place[50];
    ifstream fin;
    fin.open("tsp_points.txt");
    while(fin >> a >> b)
    {
        towns[i].x = a;
        towns[i].y = b;
        towns[i].key = i;
        best[i] = towns[i];
        i++;
    }
    fin.close();
    
    for(int i = 0; i < 50; i++)
    {
        jostle(towns);
        while(refine(towns));
        if(distance(towns) < distance(best))
        {
         for(int i = 0; i<50; i++)
         {
            best[i] = towns[i];
         }
        } 
    }           
    cout << distance(best) << endl;
    
    for(int i = 0; i<50; i++)
    {
        cout << best[i].key << " ";
    }
    
    
    
    
    return 0;
}
