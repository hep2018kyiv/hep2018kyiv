#include <iostream>
#include <string>
using namespace std;
int main()
{


string a;
long long p=0,max=0,i;
while(cin >> a)//вводимо наше значення у вигляді стрічки в форматі латинскьих букв і цифр
{
    p=0;max=0;//переводимо його в формат  цифр
 long n=a.size();
//cout<< n;
for(i=0; i<n; i++)
{
if(a[i]>='0' && a[i]<='9')
{ p+= (a[i]-'0');
    if(a[i]-'0'>max)
        max=a[i]-'0'; }
else { p+= (a[i]-'A'+10);
    if(a[i]-'A'+10>max)
        max=a[i]-'A'+10;}
}
if(max==0)//якщо після переводу отримали макс значення 0(максимальний символ в стрчці, введеній нами )  виводимо мінімальне k=2
{ i=0;
    cout << "2" << endl;}
else {
for(i=max+1; i<=36; i++)// інакше шукаємо й виводимо k менше 37
if(p%(i-1)==0)
{ cout << i << endl; return 0; }}
if(i==37)
    cout << "No solution." << endl;

}

return 0;
}
