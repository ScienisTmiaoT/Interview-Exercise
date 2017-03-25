/*
** Author: Marvin
** Date: 2017 / 03 / 25
*/
#ifndef PAIR_ABS
#define PAIR_ABS

/*
** 小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差的绝对值最小
** 的有多少对呢？差的绝对值最大的呢？
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INTMAX 2147483647

void pairabs()
{
	int n;
	while (cin >> n)
	{
		int min_count = 0;
		int max_count = 0;
		vector<int> arr(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		long min_value = INTMAX;
		long max_value = -1;
		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = i + 1; j < n; j++)
		//	{
		//		long temp = abs(arr[j] - arr[i]);
		//		if (temp < min_value)
		//		{
		//			min_count = 1;
		//			min_value = temp;
		//		}
		//		else if(temp == min_value)
		//			min_count++;

		//		if (temp > max_value)
		//		{
		//			max_count = 1;
		//			max_value = temp;
		//		}
		//		else if (temp == max_value)
		//			max_count++;
		//	}
		//}

		int q = 0;
		int c = 1;
		for (int i = 0; i < n - 1; i++)
		{
			long temp = abs(arr[i] - arr[i + 1]);
			if (temp < min_value)
			{
				min_count = 1;
				min_value = temp;
			}
			else if (temp == min_value)
				min_count++;

			if (arr[i] == arr[i + 1])
			{
				c++;
			}
			else
			{
				if (c != 1)
				{
					q += c * (c - 1) / 2;
					c = 1;
				}
			}
		}

		if (q != 0)
		{
			if (c != 1)
				min_count = q + c * (c - 1) / 2;
			else
				min_count = q;
		}

		int m = 1;
		int s = 1;
		if (arr[0] == arr[n - 1])
		{
			max_count = n * (n - 1) / 2;
		}
		else
		{
			for (int i = 1; i < n - 1; i++)
			{
				if (arr[i] == arr[0])
					m++;
				if (arr[i] == arr[n - 1])
					s++;
			}
			max_count = m * s;
		}
		cout << min_count << " " << max_count << endl;
	}
}

#endif // !PAIR_ABS
