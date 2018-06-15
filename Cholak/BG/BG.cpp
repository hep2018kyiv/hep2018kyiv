#include <iostream>
#include <map>    //подключили библиотеку для работы с map
using namespace std;
 
int main()
{ 
  unsigned int N, M, i, j, color;
  
  cin >> N;
  map <unsigned int,unsigned int> mutants;
  for(i=0; i<N;++i)
  {
    cin>>color;
    ++mutants[color];
  }
  cin >> M;
  for(i=0; i<M;++i)
  {
    cin>>j;
    cout<<mutants[j]<<" ";
  }
 
}