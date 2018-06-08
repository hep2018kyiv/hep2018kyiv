#include <iostream>
#include <map>
using namespace std;



int   ftotal( int  all_cubes )
{
    int    res = 0;
    int   numb_comb[501][501];//масив кубиків та стрічок, в стрічках - кількість кубиків, а стовпчиках - номер сходинки

    for( int  cubes = 1; cubes <= all_cubes; cubes++ )
    {
        numb_comb[cubes][1]   =   1;
        int     cols = 2;

//рахуємо кількість комбінації за допомогої рекурсивної формули
        while   (numb_comb[cubes][cols] = numb_comb[cubes - cols][cols] + numb_comb[cubes - cols][cols - 1])
        {
            if( cubes   ==  all_cubes )
            {
                res     +=  numb_comb[cubes][cols];
            }

            ++cols;
        }
    }

    return  res;
}

int     main()

{//вводимо значення кількості кибиків та виводимо результат
    // unsigned int start_time =  clock();
    int     N_all_cubes;

   cin    >>  N_all_cubes;

    cout   <<  ftotal( N_all_cubes )<<endl;
   // unsigned int end_time = clock(); // конечное время
    //  unsigned int search_time = end_time - start_time; // искомое
    //  cout<<search_time<<endl;
}



