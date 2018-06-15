#include <iostream>
using namespace std;

int numDigits(int number)
{
    int digits = 0;
    while(number) 
    {
        number /= 10;
        digits++;
    }
    return digits;
}

int *num2array(int number)
{
	int numDigitsN = numDigits(number);
	int *N_array = new int[numDigitsN];
	int var = number;
	for(int i = numDigitsN-1; i >= 0; i--)
	{
		N_array[i] = var % 10;
		var /= 10;
	}
	return N_array;
}

int array2num(int *N_array, int numDigitsN)
{
	int Num = 0;
	int n = 1;
	for(int i = numDigitsN-1; i >= 0; i--)
	{
		Num += N_array[i]*n;
		n*=10;
	}
	return Num;
}

int *numCycleSort_Simple(int N, int numDigitsN, int K, int& N_pm)
{
	int *N_array = num2array(N);

	int *N_array_sorted = new int[numDigitsN];
	for(int i = 0; i < numDigitsN; i++)
		N_array_sorted[i] = N_array[i];

	N_pm = 0;
	for (int i = 0; i < numDigitsN; i++)
	{
		int numMax = N_array[i];
		int indMax = i;
		for (int j = i+1; j < numDigitsN; j++)
		{
			if (N_array[j] > numMax)
			{
				numMax = N_array[j];
				indMax = j;
			}
		}
		if (indMax == i)
			continue;

		N_pm++;
		if (N_pm > K)
		{
			N_pm--;
			break;
		}

		N_array_sorted[i] = numMax;
		N_array_sorted[indMax] = N_array[i];

		for(int k = 0; k < numDigitsN; k++)
			N_array[k] = N_array_sorted[k];
	}

	return N_array_sorted;
}

int *numCycleSort_Biggest(int N, int numDigitsN, int K, int& N_pm)
{
	int *N_array = num2array(N);

	int *N_array_sorted = new int[numDigitsN];
	for(int i = 0; i < numDigitsN; i++)
		N_array_sorted[i] = N_array[i];

	int valMax = array2num(N_array_sorted, numDigitsN);
	int indMax = 0;

	N_pm = 0;

	for(int i = 0; i < numDigitsN; i++)
	{
		valMax = array2num(N_array_sorted, numDigitsN);
		indMax = i;

		for (int j = i+1; j < numDigitsN; j++)
		{
			N_array_sorted[i] = N_array[j];
			N_array_sorted[j] = N_array[i];

			if (array2num(N_array_sorted, numDigitsN) > valMax)
			{
				valMax = array2num(N_array_sorted, numDigitsN);
				indMax = j;
			}

			for(int k = 0; k < numDigitsN; k++)
				N_array_sorted[k] = N_array[k];
		}
		if (indMax == i)
			continue;

		N_pm++;
		if (N_pm > K)
		{
			N_pm--;
			break;
		}

		N_array_sorted[i] = N_array[indMax];
		N_array_sorted[indMax] = N_array[i];

		for(int k = 0; k < numDigitsN; k++)
			N_array[k] = N_array_sorted[k];
	}

	return N_array_sorted;
}

int *numCycleSort_Fast(int N, int numDigitsN, int K, int& N_pm)
{
	int *N_array = num2array(N);

	int *N_array_sorted = new int[numDigitsN];
	for(int i = 0; i < numDigitsN; i++)
		N_array_sorted[i] = N_array[i];

	int *N_sorted = numCycleSort_Simple(N, numDigitsN, 100, N_pm);

	int any_same;
	int iPos;

	N_pm = 0;

	int not_sorted = 1;
	int all_numbers_dublicates;
	int out_of_pm = 0;

	// do cycle while array is not sorted
	while (not_sorted == 1 && out_of_pm == 0)
	{
		// loop all elements
		for(int i = 0; i < numDigitsN; i++)
		{
			// looking for any same numbers
			any_same = 0;
			for(int j = 0; j < numDigitsN; j++)
			{
				if (N_array_sorted[i] == N_array_sorted[j] && i != j)
				{
					any_same++;
					break;
				}
			}
			// if there are no same numbers and element is not on its place
			if(N_array_sorted[i] != N_sorted[i] && any_same == 0)
			{
				// looking for proper position
				for(int j = 0; j < numDigitsN; j++)
				{
					if(N_array_sorted[i] == N_sorted[j])
					{
						iPos = j;
						break;
					}
				}

				N_pm++;
				if (N_pm > K)
				{
					out_of_pm = 1;
					N_pm--;
					break;
				}
				// permutate
				N_array_sorted[i] = N_array[iPos];
				N_array_sorted[iPos] = N_array[i];

				for(int k = 0; k < numDigitsN; k++)
					N_array[k] = N_array_sorted[k];

				// permutation is done. going on
				break;
			}
		}

		// is there are only dublicated elements left on wrong positions...
		all_numbers_dublicates = 1;
		for(int j = 0; j < numDigitsN; j++)
		{
			if (N_array_sorted[j] != N_sorted[j])
			{
				any_same = 0;
				for(int k = 0; k < numDigitsN; k++)
				{
					if (N_array_sorted[j] == N_array_sorted[k] && j != k)
					{
						any_same++;
						break;
					}
				}

				if (any_same == 1)
					continue;
				else 
					all_numbers_dublicates = 0;
			}
		}

		// ...if yes doing these stuff
		if (all_numbers_dublicates == 1)
		{
			for(int i = 0; i < numDigitsN; i++)
			{
				if(N_array_sorted[i] != N_sorted[i])
				{
					for(int j = 0; j < numDigitsN; j++)
					{
						// find proper position
						if(N_array_sorted[i] == N_sorted[j])
						{
							iPos = j;
							// if changed element will be on its place too - stop looping and joy
							if(N_array_sorted[j] == N_sorted[i])
								break;
							// else, the last proper position will be chosen 
						}
					}

					N_pm++;
					if (N_pm > K)
					{
						out_of_pm = 1;
						N_pm--;
						break;
					}

					N_array_sorted[i] = N_array[iPos];
					N_array_sorted[iPos] = N_array[i];

					// for(int k = 0; k < numDigitsN; k++)
					// 	cout << N_array_sorted[k];
					// cout << endl;

					for(int k = 0; k < numDigitsN; k++)
						N_array[k] = N_array_sorted[k];

					break;
				}
			}
		}

		// is it sorted?
		not_sorted = 0;
		for(int i = 0; i < numDigitsN; i++)
		{
			if(N_array[i] != N_sorted[i])
				not_sorted = 1;
		}
	}

	return N_array_sorted;
}

int main()
{
	int N; // Number 
	long int K; //Number of permutations
	cin >> N >> K;

	int numDigitsN = numDigits(N);

	int *N_array = num2array(N);

	// Is there any same numbers?
	int any_same = 0;
	for(int i = 0; i < numDigitsN; i++)
	{
		if(any_same > 0)
			break;
		for(int j = i+1; j < numDigitsN; j++)
		{
			if(N_array[i] == N_array[j])
			{
				any_same++;
				break;
			}
		}
	}

	int *N_array_sorted;
	int N_pm = 0;

	if (any_same == 0)
	{
		N_array_sorted = numCycleSort_Simple(N, numDigitsN, K, N_pm);
		// cout << "Number of permutations - " << N_pm << endl;

		if (K-N_pm <= 0)
			cout << array2num(N_array_sorted, numDigitsN) << endl;
		if (K-N_pm > 0 && (K-N_pm) % 2 == 0)
			cout << array2num(N_array_sorted, numDigitsN) << endl;
		if (K-N_pm > 0 && (K-N_pm) % 2 != 0)
		{
			int *N_array_sorted2 = new int[numDigitsN];
			for(int i = 0; i < numDigitsN; i++)
				N_array_sorted2[i] = N_array_sorted[i];

			N_array_sorted[numDigitsN-1] = N_array_sorted2[numDigitsN-2];
			N_array_sorted[numDigitsN-2] = N_array_sorted2[numDigitsN-1];
			cout << array2num(N_array_sorted, numDigitsN) << endl;
		}
	}
	else
	{
		N_array_sorted = numCycleSort_Biggest(N, numDigitsN, K, N_pm);
		// cout << "Number of permutations - " << N_pm << endl;

		int *N_array_sorted_fast = numCycleSort_Fast(N, numDigitsN, K, N_pm);
		// cout << "Number of permutations - " << N_pm << endl;

		if (array2num(N_array_sorted, numDigitsN) > array2num(N_array_sorted_fast, numDigitsN))
			cout << array2num(N_array_sorted, numDigitsN) << endl;
		else
			cout << array2num(N_array_sorted_fast, numDigitsN) << endl;
	}	


	return 0;
}