#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int *board;
//int count = 0;

bool issafe(int r, int N)
{
    for(int i = 0; i < r; i++)
    {
        if(board[i] == board[r]) return false;
        if(board[i] == board[r]+(r- i) || board[i] == board[r]-(r-i)) return false;
    }
    
    return true;
 }

int check_row(int r, int N)
{

    int queens = 0;
    
    if(r >= N)
    {
        return 1;
    }
    
    for(int i = 0; i < N; i++)
    {
        board[r] = i;
        
        if(issafe(r, N))
        {
           queens += check_row(r + 1, N); 
        }
            
    }
    return queens;
}
        
int main(int argc, char *argv[])
{

  int total;
  if (argc != 2) {
    cout << "Bad input size\n";
    return 0;
  }

  int N = atoi(argv[1]);  // get first command-line argument
  //if (N<4) {
  //  cout << "Invalid input size!\n";
 //   return 0;
  //}
  
  board = new int[N];
  for(int i = 0; i < N; i++)
  {
    board[i] = 0;
  }
  
  total = check_row(0, N);
  cout << total << endl;
  
  return 0;
 }
  
