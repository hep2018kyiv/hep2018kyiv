#include <iostream>
#include<stdio.h>
//#include<vector>
#include <algorithm>
#include <math.h>
using namespace std;
void swap (int *a, int *b)
{
int x;
x = *a;
*a = *b;
*b = x;
}
void returnNum(int digits[]){
  int res = 0;
  int pow = 1;
  const int N = sizeof(digits) / sizeof(int);
  for(int i = N-1; i >= 0 ; i--) 
  {
    res = res + pow*digits[i];
    pow = pow*10;
  }
  cout << res /*<<endl*/;  // remove endl at hte end
}


int main(){
  int N,K;
  int nEl =0;
  int fSwap = 0;
  int numSwap1 = 0;
  int a,b;
cin >> N >> K;

int digits[7]; // цифры
int digitsCopy[7];
for (int i = N; i != 0; i /= 10)
{
    nEl++;
}
int jj=0;
for (int i = N; i != 0; i /= 10)
{
    digits[nEl-jj]=(i % 10);
    jj++;
}
digitsCopy[0]=digits[0];
digitsCopy[1]=digits[1];
digitsCopy[2]=digits[2];
digitsCopy[3]=digits[3];
digitsCopy[4]=digits[4];
digitsCopy[5]=digits[5];
digitsCopy[6]=digits[6];
bool flagDone1 = false;
bool flag = true;
if (K<=(nEl-1)) {fSwap = K; flagDone1 = true;} /// if K < numOfEl -1 then standart 
else fSwap = nEl - 1; // else 
// for (int i =0; i<fSwap; i++)
// { 
//   
//   swap(digits[i],digits[std::distance(digits.begin(), result)]);
//   swap(&digits[i],&digits[std::distance(digits, std::max_element(digits+i, digits + nEl))]);
//   if(digits == digitsCopy && (1-flag)) {flag = true; numSwap1 = i;}
//   digitsCopy = digits;
// //   for (unsigned int j(1); j < digits.size()-1; j++)
// //   if (digits[j-1]<=digits[j] && digits[j]>=digits[j+1]) numSwap1 = i+1;
// //   cout<<"blaaa"<<endl;
// }
int k =0;

while(flag && (k<K))
{ 
  swap(&digits[k],&digits[std::distance(digits, std::max_element(digits+k, digits + nEl))]);
  if(digitsCopy[0]==digits[0] && digitsCopy[1]==digits[1] && digitsCopy[2]==digits[2] && digitsCopy[3]==digits[3] && digitsCopy[4]==digits[4] && digitsCopy[5]==digits[5] && digitsCopy[6]==digits[6] && (1-flag)) {flag = true; numSwap1 = k;}
  digitsCopy[0]=digits[0];
  digitsCopy[1]=digits[1];
  digitsCopy[2]=digits[2];
  digitsCopy[3]=digits[3];
  digitsCopy[4]=digits[4];
  digitsCopy[5]=digits[5];
  digitsCopy[6]=digits[6];
  k++;
}

cout<<numSwap1<<endl;
if (k<K && (flag)) returnNum(digits);
else{
  bool flagDone2 = false;
  for (unsigned int i(1); i <= nEl-1; ++i)
    if (digits[i-1]==digits[i] || digits[i]==digits[i+1]) flagDone2 = true;
//   cout<< flagDone2;
  if (flagDone2 ) returnNum(digits);
  else{
  for (int i = numSwap1; i <=K; i++)
  { /*if(i%2 == 0) { a = nEl-2; b = nEl -1;}
    else {b = nEl-2; a = nEl -1;} 
    swap(digits[a],digits[b]);*/
    swap(&digits[nEl-1],&digits[nEl-2]);
//     cout<<"done"<<endl;
    
  }
  returnNum(digits);
  }
}    



}