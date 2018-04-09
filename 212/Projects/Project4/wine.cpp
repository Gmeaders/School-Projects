/*
   Greg Meaders
   10/28/14
   Homework 4
   cpsc212
   wine.cpp
*/
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct wine
{
    double quality;
    double *attr;
    wine() { quality = -1; attr = NULL;}   
};

struct kd_tree
{   
    wine *key;
    kd_tree *left;
    kd_tree *right;
    kd_tree (wine *k) { key = k; left = right = NULL;}    
};

typedef pair<double, wine*> pri;

    
kd_tree *insert(kd_tree *T, wine *v, int d, int dem)
{
  if (T == NULL) return new kd_tree(v);

  if(v->attr[d] < T->key->attr[d]) {
  
  T->left = insert(T->left, v, (d+1) % dem, dem);
  }
  
  else T->right = insert(T->right, v, (d+1) % dem, dem);
  return T;
}

wine *randomize(wine *thing, int N)
{
    int random;
    wine temp;
    for(int i = 0; i < N; i++)
    {
        random = rand() % (N + 1);
        temp = thing[i];
        thing[i] = thing[random];
        thing[random] = temp;
    }
    
    return thing;
}

void neighbor(wine A, kd_tree *curr, priority_queue<pri> &Q, int D, int Dem, int K)
{
    if(curr == NULL)
        return;
    double distance = 0.0;
    for(int i = 0; i < Dem; i++)
    {
        distance += (A.attr[i] - curr->key->attr[i]) * (A.attr[i] - curr->key->attr[i]);
    }
    
    distance = sqrt(distance);
    
    if(distance != 0 && (Q.size() < K || distance <= Q.top().first))
    {
        Q.push(pri(distance, curr->key));
        if(Q.size() > K)
            Q.pop();
    }
    
    double D_Dist = 0.0;
    D_Dist = A.attr[D] - curr->key->attr[D];
    kd_tree *near;
    kd_tree *far;
    
    if(D_Dist <= 0)
    {
        near = curr->left;
        far = curr->right;
    }
    else
    {
        near = curr->right;
        far = curr->left;
    }
    
    neighbor(A, near, Q, (D+1) % Dem, Dem, K);
    
    if(D_Dist >= Q.top().first) return;
    
    neighbor(A, far, Q, (D+1) % Dem, Dem, K);
}

void classification(priority_queue<pri> &Q, double *A, int i)
{
    double weight = 0.0;
    double total =  0.0;
    double name = 0.0;
    
    while(!Q.empty())
    {
        weight = exp(-0.1 * Q.top().first);
        name += weight * Q.top().second->quality;
        total += weight;
        Q.pop();
    }
    A[i] = name / total;
}


int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << "Usage: " << argv[0] << " <infile> <k>\n";
        return -1;
    }
    ifstream in;
    kd_tree *tree = NULL;     //making the kd tree
    in.open(argv[1]);
    int K = atoi(argv[2]); //number of dimentions to search
    int N, D; //N is number of wines, D is dimensions
    in >> N >> D;
    wine *wines = new wine[N];
    for (int i = 0; i < N; i++)
    {
        in >> wines[i].quality;
        wines[i].attr = new double[D];
        for (int j = 0; j < D; j++)
        {
            in >> wines[i].attr[j];
        }
    }
    in.close();
    
    //setting mean and variance
    double mean = 0.0;
    double var = 0.0;
    for(int i = 0; i < D; i++)
    {
        mean = 0.0;
        var = 0.0;
        
        for(int j = 0; j < N; j++)
        {
            mean += wines[j].attr[i];
        }
        mean = mean/N;
        for(int j = 0; j < N; j++)
        {
            wines[j].attr[i] -= mean;
            var += wines[j].attr[i] * wines[j].attr[i];
        }
        var = sqrt(var/N);
        for(int j = 0; j < N; j++)
        {
            wines[j].attr[i] = wines[j].attr[i] / var;
        }
    }
 
    int curr_dem = 0;
    for(int i = 0; i < N; i++)
    {
        tree = insert(tree, &wines[i], curr_dem, D); 
    }
    
    double approx[N]; //total number of approximations
    
    for(int i = 0; i < N; i++)
    {
        priority_queue<pri> Q;
        neighbor(wines[i], tree, Q, 0, D, K);
        classification(Q, approx, i);
    }
    
    double error = 0.0;
    for(int i = 0; i < N; i++)
    {
        error += (wines[i].quality - approx[i]) * (wines[i].quality - approx[i]);
    }
    
    error = error / N;
    
    cout << "Avg Error is  " << error << endl;
        
    
    return 0;
    
    
}
