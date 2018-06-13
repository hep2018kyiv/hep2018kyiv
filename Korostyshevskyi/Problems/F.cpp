#include "iostream"
#include <stdlib.h>

using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int CalcBrak (int date[3], int h, int m, int s, int A, int M){
  int CalacultedBrak = 0;

  int fulldate[6];

  fulldate[0] = date[0];
  fulldate[1] = date[1];
  fulldate[2] = date[2];
  fulldate[3] = h;
  fulldate[4] = m;
  fulldate[5] = s;

  for (int i = 0; i < 6; i++){
    long long int cashe = fulldate[i];
    for (int j = 0; j < i+1; j++){

      cashe = cashe*A % M;
      //cout << cashe << endl;
    }
    CalacultedBrak += cashe;

    CalacultedBrak = CalacultedBrak % M;
  }
  return CalacultedBrak;
}

int main() {
  int BracNum, SerNum, count = 0, A, M = 1000000007;
  int Brak[1000000], Ser[1000000];

  cin >> A;


  cin >> SerNum;

  for(int i = 0; i < SerNum; i++){
    cin >> Ser[i];
  }

  qsort (Ser, SerNum, sizeof(int), compare);

  /*for(int i = 0; i < SerNum; i++){
    cout << Ser[i] << " " << '\n';
  }
  */

  int i = 0;
  int j = 0;

  int date[3] = {2015, 9, 24};

  BracNum = 0;

  for (int h = 0; h < 24; h++){
    for (int m = 0; m < 60; m++){
      for (int s = 0; s < 60; s++){
       Brak[BracNum] = CalcBrak(date, h, m, s, A, M);
       BracNum ++;
      }
    }
  }

  qsort (Brak, BracNum, sizeof(int), compare);

  while ((i < BracNum)*(j < SerNum)){

    if (Brak[i] == Ser[j]){
      count ++;
      j++;
    }
    else if (Brak[i] < Ser[j]) i++;
    else if (Brak[i] > Ser[j]) j++;
  }

  cout << count << endl;

  return 0;
}
