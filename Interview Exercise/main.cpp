/*
** Author: Marvin
** Date: 2017 / 03 / 25
*/
#include "pair_abs.h"


int main()
{
	int n = 0;
	int m = 0;
	vector<int> arr;
	cin >> n;
	for (int k = 0; k < n; k++)
	{
		cin >> m;
		arr.push_back(m);
	}
	int i = n - 2;
	for (; i >= 0; i--)
	{
		if (arr[i] > arr[i + 1])
			break;
	}
	if (i <= 0)
		cout << arr[0] << " ";
	else
		for (int j = 0; j <= i; j++)
			cout << arr[j] << " ";
	cout << endl;
	return 0;
}