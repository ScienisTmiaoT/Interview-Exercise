/*
** Author: Marvin
** Date: 2017 / 03 / 25
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int main()
{
	//int n = 0;
	//int m = 0;
	//vector<int> arr;
	//cin >> n;
	//for (int k = 0; k < n; k++)
	//{
	//	cin >> m;
	//	arr.push_back(m);
	//}
	//int i = n - 2;
	//for (; i >= 0; i--)
	//{
	//	if (arr[i] > arr[i + 1])
	//		break;
	//}
	//if (i <= 0)
	//	cout << arr[0] << " ";
	//else
	//	for (int j = 0; j <= i; j++)
	//		cout << arr[j] << " ";
	//cout << endl;

	long long n = 0;
	long long q = 0;
	long long time = 0;
	long long t = 1;
	cin >> n;
	cin >> q;
	long long i = 0;
	if (2 * q >= n)
	{
		cout << n << endl;
		return 0;
	}
	else if (4 * q > n)
	{
		for (; i < 62; i++)
		{
			long long x = i * q * (t << i) + n;
			long long y = n * (t << i);
			if (x < y)
				break;
		}
	}
	else
	{
		for (; i < 62; i++)
		{
			long long x = q * (t << (i + 1));
			long long y = q * (t << (i + 2));
			long long z = i * n;
			long long w = (i + 1) * n;
			if (x <= z && y > w)
				break;
		}
	}
	time = i * q + (n - 1) / (t << i) + 1;
	cout << time << endl;
	return 0;
}