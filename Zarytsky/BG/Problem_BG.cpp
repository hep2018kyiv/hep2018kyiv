#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int *colors = new int[N];
	for(int i = 0; i < N; i++)
		cin >> colors[i];

	int M;
	cin >> M;

	int *req = new int[M];
	for(int i = 0; i < M; i++)
		cin >> req[i];


	int *n_col = new int[M];
	for(int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (colors[i] == req[j])
			{
				n_col[j] += 1;
				break;
			}
		}
	}

	for (int i =0; i< M; i++)
		cout << n_col[i] << " ";
	cout << endl;

}