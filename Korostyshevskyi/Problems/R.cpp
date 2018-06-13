#include "iostream"
#include "string.h"


using namespace std;

char convert(int i)
{
    return i;
}

int returnVal(char x)
{
    return (int)x;
}



int CalcCash (int Char[1000000], int length ,int A, int M,int start,int prevCash){
  long long int CalacultedCash = 0;


  if (start == 0){
  for (int i = start; i < length + start; i++){
    long long int cashe = Char[i];
    for (int j = start; j < i; j++){

      cashe = cashe*A % M;
    }
    CalacultedCash += cashe;

    CalacultedCash = CalacultedCash % M;
  }
  }
  else {
    unsigned long long int prevcash = prevCash;
    if(prevcash < Char[start - 1]) prevcash += M;
    prevcash -= Char[start - 1];
    prevcash *= 222993064;
    prevcash = prevcash % M;
    long long int cashe = Char[length + start - 1];
    for (int j = start; j < length + start - 1; j++){
      cashe = cashe*A % M;
    }
    prevcash += cashe;

    prevcash = prevcash % M;
    CalacultedCash = prevcash;
  }

  return CalacultedCash;
}

int main(){

  int length;
  cin >> length;

  int PodLength;
  cin >> PodLength;

  int Hesh;
  cin >> Hesh;

  int A = 1103515245;
  int B = 12345;
  int C = 1009;
  int D = 1000000007;

  int Char[1000000];
  Char[0] = 1;

  unsigned long long int bufer = Char[0];
  long long int twoPower = 1024;
  twoPower*=1024;
  twoPower*=1024;
  twoPower*=4;
  //cout << twoPower << endl;
  for (int i = 1; i < length; i++){
    unsigned long long int cashe = (bufer*A+B) % twoPower;
    Char[i-1] =  returnVal('a') + (bufer>>16) % 26;
    bufer = cashe;
  }
  Char[length - 1] =  returnVal('a') + (bufer>>16) % 26;


  int flag = -1;

  int prevCash = 0;

  for (int i = 0; i < length - PodLength + 1 ; i++){
    /*
    for (int j = i; j < PodLength+i; j ++ ){
      cout << convert(Char[j]);
    }
    cout << " ";
    */
    //cout << CalcCash(Char, PodLength, C, D, i) << " ";

    prevCash = CalcCash(Char, PodLength, C, D, i, prevCash);
    if (prevCash == Hesh){
      flag = i;
      break;
    }

  }

      if (flag != -1){
        for(int i = flag; i < PodLength + flag; i++){
          cout << convert(Char[i]);
        }
        cout << endl;
      }
      else if(flag == -1){
        cout << 0 << endl;
      }



 return 0;

}
