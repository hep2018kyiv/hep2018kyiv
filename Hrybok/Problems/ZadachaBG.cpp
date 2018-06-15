#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;

static map<unsigned long, unsigned long> maps;
int main()
{
    unsigned long  N, M;
    cin >> N;
    unsigned long bufer;
    for (unsigned long  i = 0; i < N; i++){
        cin >> bufer;
        maps[bufer]++;
    }
    cin >> M;
    for (unsigned long  i = 0; i < M; i++){
        cin >> bufer;
        cout << maps[bufer] << " ";
    }
    return 0;
}
