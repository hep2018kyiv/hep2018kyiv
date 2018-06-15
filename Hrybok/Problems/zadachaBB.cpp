#include <iostream>

using namespace std;

int main()
{
   long int N, Q = 0 ,p = 1;
   cin >> N; // вводимо число
   if(N==0) // zякщо воно 0, Q=10
    {
        cout<<"10"<<endl;
        return 0;
    }
    if(N<10) // якщо число з 1 цифри, виводимо саме це число
    {
        cout<<N<<endl;
        return 0;
    }
    // для інших чисел алгоритм наступний: знаходимо на кожному кроці ітерації найбільший  дільник числа, дільник складається з 1 цифри!
    // запонюємо число Q цими дільниками у зворотньому порядку, аби число Q було найменше
    for(int div = 9; div > 1; --div)
    {
        while( (N%div) == 0)
        {
            Q += p * div;
            p = p * 10;
            N /= div;
        }
    }
  if(N>1)
    {
        cout<<"-1"<<endl;
        return 0;
    }
   cout << Q << endl;
    return 0;
}
