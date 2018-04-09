#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef pair<double, double> Point;


double distance(double x, double y, double x1, double y1)
{
    double temp = ((x - x1) * (x - x1));
    temp +=(y-y1) * (y-y1);
    return sqrt(temp);
  }
  
int main()
{
    vector<Point> v;
    double x, y;
    double minD = 2.0;
    set<Point> s;
    ifstream fin;
    fin.open("points.txt");
    while(fin>>x>>y){
        v.push_back(Point(x,y));
     }
     fin.close();
     
     sort(v.begin(), v.end());
     
     int i = 0;
     for(int j = 0; j < v.size(); j++)
     {
        s.insert(Point(v[j].second, v[j].first));
        
        
        while(v[j].first - v[i].first > minD)
        {   
            s.erase(Point(v[i].second, v[i].first));
            i++;
        }
        
        
        set<Point>::iterator it;
        it = s.find(Point(v[j].second, v[j].first));
        
        it++; 
        while (it != s.end())
        {
            
            double current = distance(v[j].second, v[j].first, it->first, it->second);
            if(current < minD) minD = current; 
            it++; 
        }
        it = s.find(Point(v[j].second, v[j].first));
        while(it != s.begin())
        {
            it--;
            double current = distance(v[j].second, v[j].first, it->first, it->second);
            if(current < minD) minD = current;  
        }
     }
     
     cout << minD << endl;
  return 0;
}
            
