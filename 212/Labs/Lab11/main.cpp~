#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

using namespace std;
typedef pair<int, string> states;

struct State{

  string name;
  vector<string> neighbors;
};

map<string, State *> Nodes;
vector<states> dists_label;


int BFS(string name)
{
   map<string,int> dists;
   queue<string> Q;
   Q.push(name);
   dists[name] = 0;
   int total = 0;
   while(!Q.empty())
   {
        string curr = Q.front();
        Q.pop();
        
        int d = dists[curr];
        if(d > total) total = d;
        for(int j = 0; j < Nodes[curr]->neighbors.size(); j++)
        {
            string n = Nodes[curr]->neighbors[j];
            if(dists.count(n) == 0)
            {
                dists[n] = dists[curr] + 1;
                Q.push(n);
            }
         }
    }
    
    return total;
}
                
   

int main()
{
    string a, b;
    ifstream fin;
    fin.open("usa_48_state_graph.txt");

    while(fin >> a >> b)
    {
      if(Nodes.count(a) == 0)
      {
        Nodes[a] = new State;
        Nodes[a]->name = a;
      }
      Nodes[a]->neighbors.push_back(b);
      
      
      if(Nodes.count(b) == 0)
      {
        Nodes[b] = new State;
        Nodes[b]->name = b;

      }
      Nodes[b]->neighbors.push_back(a);
      
     }
     fin.close();
     
     map<string, State *>::iterator it;
     for (it = Nodes.begin(); it != Nodes.end(); it++) 
     {
        int ecc = BFS(it->second->name);
        dists_label.push_back(states(ecc, it->second->name));
     }
   
     sort(dists_label.begin(), dists_label.end());
   
     for(int i = 0; i < dists_label.size(); i++)
     {
        cout << dists_label[i].second << " " << dists_label[i].first << endl;
     }
     
     return 0;
     
     }



        
