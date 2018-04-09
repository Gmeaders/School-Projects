#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
    string s;
    int a;
    int b;
} STEP;

vector<STEP> step_set;
bool visited[1001][1001];
int jug1, jug2, total;


int pourSource(int a, int b, int jug)
{
    int spaceB = jug - b;
    if(spaceB == 0) return a;
    if(spaceB >= a) return 0;
    return a - spaceB;
}

int pourDest(int a, int b, int jug)
{
    int spaceB = jug - b;
    if(spaceB >= a) return a+b;
    return jug;
}

bool visit(int a, int b, int step)
{
  STEP curr_step;
  if(a + b == total) return true;
  if(visited[a][b]) return false;
  visited[a][b] = true;
  
  if(visit(jug1, b, step + 1))
  { 
    curr_step.s = "Fill 1\t";
    curr_step.a = jug1;
    curr_step.b = b;
    step_set.push_back(curr_step);
    return true;
  }
  
  if(visit(0, b, step + 1))
  {
    curr_step.s = "Empty jug 1";
    curr_step.a = 0;
    curr_step.b = b;
    step_set.push_back(curr_step);
   return true;
  }
  
  if(visit(pourSource(a, b, jug2), pourDest(a, b, jug2), step + 1))
  {
    curr_step.s = "Pour 1 into 2";
    curr_step.a = pourSource(b, a, jug1);
    curr_step.b = pourDest(b, a, jug1);
    step_set.push_back(curr_step);
   return true;
  }
  
  if(visit(a, jug2, step + 1))
  {
    curr_step.s = "Fill jug 2";
    curr_step.a = a;
    curr_step.b = jug2;
    step_set.push_back(curr_step);
    return true;
  }
  
  if(visit(a, 0, step + 1))
  {
    curr_step.s = "empty jug 2\t";
    curr_step.a = a;
    curr_step.b = 0;
    step_set.push_back(curr_step);
    return true;
  }
  
  if(visit(pourSource(b, a, jug1), pourDest(b, a, jug1), step + 1))
  {
   curr_step.s = "Pour 2 into 1";
   curr_step.a = pourDest(b, a, jug1);
   curr_step.b = pourSource(b, a, jug1);
   step_set.push_back(curr_step);
   return true;
  }
  
  return false;
  
 }

int main()
{
   int a, b, x;
   int check1, check2;
   cout << "Enter A: ";
   cin >> jug1;
   cout << "Enter B: ";
   cin >> jug2;
   cout << "Enter X: ";
   cin >> total;
   cout << endl;

   if(visit(0, 0, 0))
   {
    for(int i = step_set.size(); i > 0; i--)
    {
        cout << endl << step_set[i-1].s << "\t[a = " << step_set[i-1].a << ", b = " << step_set[i-1].b << "]";
    }
    cout << endl;
   }
   else cout << "impossible" << endl;
   return 0;
  }