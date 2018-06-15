#include <iostream>
#include<stdio.h>
#include<vector>
#include <algorithm>
#include <math.h>
using namespace std;
void returnNum(vector<int>  digits){
  int res = 0;
  int pow = 1;
  for(int i = digits.size()-1; i >= 0 ; i--) 
  {
    res = res + pow*digits[i];
    pow = pow*10;
  }
  cout << res /*<<endl*/;  // remove endl at hte end
}
bool myfn(int i, int j) { return i<=j; }
int main(){
  int N,K;
  int nEl =0;
  int fSwap = 0;
  int numSwap1 = 0;
  int a,b;
cin >> N >> K;

vector<int> digits; // цифры
vector<int> digitsCopy;
digits.reserve(6);
digitsCopy.reserve(6);
std::vector<int>::iterator result;



for (int i = N; i != 0; i /= 10)
{
  digits.push_back(i % 10);
  nEl++;
}
int buff = 1000;
bool flag_check_same = false;
int check_digit=0;
for (unsigned int i=0; i <= digits.size()-1; ++i)
{ 
  check_digit = digits[i];
  if(check_digit == buff) flag_check_same = true;
  buff = check_digit;
}
// cout<<nEl<<endl;
//  digits.shrink_to_fit(); // уменьшить используемой памяти до необходимой

reverse(digits.begin(), digits.end()); // развернуть
digitsCopy = digits;
bool flagDone1 = false;
bool flag = true;
if (K<=(nEl-1)) {fSwap = K; flagDone1 = true;} /// if K < numOfEl -1 then standart 
else fSwap = nEl - 1; // else 
// for (int i =0; i<fSwap; i++)
// { 
//   
//   result = std::max_element(digits.begin()+i, digits.end());
//   swap(digits[i],digits[std::distance(digits.begin(), result)]);
//   if(digits == digitsCopy && (1-flag)) {flag = true; numSwap1 = i;}
//   digitsCopy = digits;
// //   for (unsigned int j(1); j < digits.size()-1; j++)
// //   if (digits[j-1]<=digits[j] && digits[j]>=digits[j+1]) numSwap1 = i+1;
// //   cout<<"blaaa"<<endl;
// }
int k =0;
while(flag && (k<K))
{ 
  result = std::max_element(digits.begin()+k, digits.end(),myfn);
  swap(digits[std::distance(digits.begin(), result)],digits[k]);
  k++;
  if(digits == digitsCopy) {flag = false; numSwap1 = k; /*cout<<"no swap"<<endl;*/}
  digitsCopy = digits;
  
}

// cout<<numSwap1<<endl;
if (k == K && (flag)){
  if(digits[0] == digits[1] && K==2 && digits[nEl-2]<digits[nEl-1]) swap(digits[nEl-2],digits[nEl-1]);
  returnNum(digits);
}
else{
//   bool flagDone2 = false;
//   for (unsigned int i=1; i <= digits.size()-1; ++i)
//     if (digits[i-1]==digits[i] || digits[i]==digits[i+1]) flagDone2 = true;
//    cout<< flagDone2<<endl;
//      cout<< flag_check_same<<endl;

  if (flag_check_same ) returnNum(digits);
  else{
  for (int i = numSwap1; i <=K; i++)
  { /*if(i%2 == 0) { a = nEl-2; b = nEl -1;}
    else {b = nEl-2; a = nEl -1;} 
    swap(digits[a],digits[b]);*/
    swap(digits[nEl-1],digits[nEl-2]);
//     cout<<"done"<<endl;
    
  }
  returnNum(digits);
  }
}    



}