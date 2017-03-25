/*
** Author: Marvin
** Date: 2017 / 03 / 25
*/
#ifndef PAIR_ABS
#define PAIR_ABS

/*
** СQ�������ϲ���ʱ�뵽��������⣺��n������������ɶ�Ԫ�飬��ľ���ֵ��С
** ���ж��ٶ��أ���ľ���ֵ�����أ�
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
		//sort(arr.begin(), arr.end());
		long min_value = INTMAX;
		long max_value = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				long temp = abs(arr[j] - arr[i]);
				if (temp < min_value)
				{
					min_count = 1;
					min_value = temp;
				}
				else if(temp == min_value)
					min_count++;

				if (temp > max_value)
				{
					max_count = 1;
					max_value = temp;
				}
				else if (temp == max_value)
					max_count++;
			}
		}
		cout << min_count << " " << max_count << endl;
	}
}

#endif // !
