#include <iostream>
#include <stdlib.h>

using namespace std;

static map<unsigned long, unsigned long> counts;

int main(int argc, char * argv[])
{
    unsigned long  N, M;
    ifstream input;

    cin >> N;
    unsigned long buff;
    for (unsigned long  i = 0; i < N; i++){
        cin >> buff;
        counts[buff]++;
    }

    cin >> M;
    for (unsigned long  i = 0; i < M; i++){
        cin >> buff;
        cout << counts[buff] << " ";
    }
    return 0;
}
