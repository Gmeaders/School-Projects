/*
    Greg Meaders
    10/3/14
    Project 2
    Bad3.cpp
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 2) {
    cout << "Usage: bad1 <input size>\n";
    return 0;
  }

  int N = atoi(argv[1]);  // get first command-line argument
  if (N<1 || N>100000) {
    cout << "Invalid input size!\n";
    return 0;
  }
  
  // Generate and print bad input of size N for prog1
  // (currently just generates an input of N random numbers)
  cout << N << "\n";
  int j = N;
  for (int i=0; i<N/2; i++)
  {
    cout << j << endl;
    j--;
  }
  
  for(int i = N/2; i > 0; i--)
  {
    cout << j << endl;
    j++;
  }  
  return 0;
}
