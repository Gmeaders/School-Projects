#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct Point {
   double score;
   double *location;
   Point(double q, double *loc) { score = q; location = loc; }
   Point() { score = -1; location = NULL; } 
};

struct Node {
   Point *key;
   Node *left;
   Node *right;
   Node(Point *k) { key = k; left = right = NULL; }
   Node() { key = NULL; left = NULL; right = NULL; }
};

Point *wine;
int N;
int D;
int K;
typedef pair<double, Point*> pdp; 
priority_queue<pdp> pq;

double calc_mean(int dim)
{
   double sum = 0;
   for(int i=0; i<N; i++) sum += wine[i].location[dim];
   return sum/N;
}

void sub_mean(int dim, double mean)
{ 
   for(int i=0; i<N; i++) wine[i].location[dim] -= mean;
}

double calc_variance(int dim)
{
   double sum = 0;   
   for(int i=0; i<N; i++) sum += (wine[i].location[dim]*wine[i].location[dim]);  
   return sum/N;
}

void divide_std_dev(int dim, double var)
{
   double std_dev = sqrt(var);
   for(int i=0; i<N; i++) wine[i].location[dim] /= std_dev;
}

Node *insert(Node *T, Point *p, int d)
{
   if(T == NULL) return new Node(p);
   if(p->location[d] < T->key->location[d]) T->left = insert(T->left, p, (d+1) % D);
   else T->right = insert(T->right, p, (d+1) % D);  
   return T;
}

double dist_squared(Point i, Point j)
{
   double dist = 0;
   for(int a=0; a<D; a++) dist += (i.location[a] - j.location[a]) * (i.location[a] - j.location[a]);
   return sqrt(dist);
}

void nearest_neigh(Point p, Node *curr, priority_queue<pdp> &result, int dim)
{
   if(curr == NULL) return;

   double dist = dist_squared(p, *curr->key);
   if (dist != 0 && (result.size() < K || dist <= result.top().first))
   {
      result.push(pdp(dist, curr->key));
      if(result.size() > K) result.pop();
   }

   double dim_dist = p.location[dim] - curr->key->location[dim];
   Node *near;
   Node *far;
   if(dim_dist <= 0)
   {
      near = curr->left;
      far = curr->right; 
   }
   else
   {
      near = curr->right;
      far = curr->left;
   }
  
   nearest_neigh(p, near, result, (dim+1) % D);

   if(dim_dist >= result.top().first) return;
  
   nearest_neigh(p, far, result, (dim+1) %D);
}

void classification(priority_queue<pdp> &result, double *guess, int i)
{
   double weight, param;
   double label, total = 0;
  
   while(!result.empty())
   {
      //param = -0.1 * result.top().first * 0.01;
      //weight = pow(M_E, param);
      weight = exp(-0.1 * result.top().first);
      label += weight * result.top().second->score;
      total += weight;
      result.pop();
   }
   guess[i] = label/total;
}

double sq_error(double *guess)
{
   double err = 0;
   for(int i=0; i<N; i++) err += (wine[i].score - guess[i]) * (wine[i].score - guess[i]);
   return err/N;
}


int main()
{
   srand(time(NULL)); 
   string source;
   cout << "Enter the name of input file: " << endl;
   cin >> source;

   cout << "Enter value between 1-10 for k: " << endl;
   //read in input for K (needs to be int from 1-10)
   while (!(cin >> K) || K < 1 || K > 10)
   {
      cout << "Invalid input size! Please enter an int from 1-10: \n";
      cin.clear();
      cin.ignore(1000, '\n');
   }
  
   //read in file
   ifstream fin(source.c_str()); 
  
   //the first line contains N and D
   fin >> N >> D;

   wine = new Point[N];
  
   double score;
   double loc;
   for(int i=0; i<N; i++)
   {
      fin >> score;
      wine[i].score = score; //insert first value of each line as quality
      wine[i].location = new double[D];
 
      for(int j=0; j<D; j++)
      {  
         fin >> loc;
         wine[i].location[j] = loc;
      }
    }
  
   fin.close();

  
  /*//rescale the distribution
   double mean;
   double var;
   for(int j=0; j<D; j++)
   {
      mean = calc_mean(j);
      sub_mean(j, mean);
      var = calc_variance(j);
      divide_std_dev(j, var);
   }*/
   
   
    for (int i =0; i < D; i++) 
    {
     double mean = 0.0;
      for (int j = 0; j < N; j++)
      {
        mean += wine[j].location[i];
      }
      mean /= N;
      for (int j = 0; j < N; j++)
      {
        wine[j].location[i] -= mean;
      }
      
      double var = 0.0;
      
      for (int j = 0; j<N; j++)
      {
       var += pow(wine[j].location[i],2);
      }
      
      double stddev = sqrt(var/N);
      
      for (int j = 0; j< N; j++)
      {
        wine[j].location[i] /= stddev;
      }
    }
  
  
   //randomize points to insert them randomly into kd tree
   //this should keep it relatively balanced
   for(int i=0; i<N; i++) swap (wine[i], wine[rand() % N]); 
  
   Node *T = NULL;
  
   int it=0;
   for(int j=0; j<N; j++)
   {
      T = insert(T, &wine[j], it);
      if(it<D) it++;
      else it = 0;
   }
  
   double guess[N]; //stores all the guessed label of each point 

   for (int i=0; i<N; i++)
   {
      priority_queue<pdp> result;
      nearest_neigh(wine[i], T, result, 0);
      classification(result, guess, i);
   }

   double error = sq_error(guess);
   cout << "Avg Error: " << error << endl;
  
   return 0;
}
