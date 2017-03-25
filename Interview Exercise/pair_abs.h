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

/*
** 思路就是先排序，因为内置函数排序的时间复杂度比较小，
** 对于最小差值来说，要单独考虑相同的元素，这样一来最小肯定是0，然后就是对相同元素进行组合
** 对于最大差值来说，肯定是最小和最大的值之差，但是要考虑到连续相同的最小值和最大值，也要考
** 虑到最小值和最大值相同的情况
*/
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
