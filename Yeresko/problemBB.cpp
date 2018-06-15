#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
   long int N = 0;
   long int Q = 0;
   long int digit = 1;

   scanf("%ld", &N);

   if(N==0){ printf("%d\n", 10); return 0;
   } else if(N<10){ printf("%ld\n", N); return 0;
   } else {
       for(int i = 9; i > 1; i--)
        {
            while( (N%i) == 0)
            {
                Q += digit * i;
                digit *= 10;
                N /= i;
            }
        }
       if(N>1){ printf("%d\n", -1); return 0;}
   }

   printf("%ld\n", Q);
   return 0;

}
