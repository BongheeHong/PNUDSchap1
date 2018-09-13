//½Ç½À7
//program 1.28: program to time program 1.27
#include <iostream>
#include <time.h>
#include <chrono>  // for high_resolution_clock

using namespace std;

int SequentialSearch(int *a, int k, int n)
{
	for (int i = 0; i < 1001; i++)
		if (a[i] == k) return i;
	return 0;
}


void TimeSearch()
{
	int a[1001], n[20];
	const long r[20] = { 300000, 300000,200000,200000,100000,100000,100000,80000,80000,
		50000,50000,25000,15000,15000,10000,7500,7000,6000,5000,5000 };

	for (int j = 1; j < 1000; j++)
		a[j] = j;

	for (int j = 0; j < 10; j++)
	{
		n[j] = 10 * j;
		n[j + 10] = 100 * (j + 1);
	}

	cout << "  n totalTime runTime" << endl;

	for (int j = 0; j < 20; j++)
	{
		// Record start time
		auto start = chrono::high_resolution_clock::now();
		
		for (long b = 1; b <= r[j]; b++)
			int k = SequentialSearch(a, n[j], 0);

		// Record end time
		auto finish = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = finish - start;

		cout << n[j] << ", Elapsed time=" << elapsed.count() << endl;
	}
}


int main(void)
{
	cout << "testing of TimeSearch()";
	TimeSearch();
	getchar();
	return 0;
}
