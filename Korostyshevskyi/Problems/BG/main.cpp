
#include "cmath"
#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
int N;
int M;
int count = 0;
int in[100000][2];
int buf;


cin >> N;

for (int i = 0; i < N; i++){
  in[i][1] = 0;
  in[i][0] = 0;
}

for (int i = 0; i < N; i++){
  cin >> buf;
  int flag = 0;
  for (int j = 0; j < count; j++){
    if (in[j][0] == buf){
      in[j][1] ++;
      flag = 1;

    }
  }
  if(flag == 0){
    in[count][0] = buf;
    in[count][1] = 1;
    count ++;
  }
}
cin >> M;
for(int i = 0; i < M; i ++){
  cin >> buf;
  int flag = 0;
  for (int j = 0; j < count; j++){
    if (in[j][0] == buf){
      cout << in[j][1] << " " ;
      flag = 1;

    }
  }
  if(flag == 0){
     cout << 0 << " ";
  }
}

    return 0;
}
