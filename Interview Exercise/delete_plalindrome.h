/*
** Author: Marvin
** Date: 2017 / 03 / 25
*/
#ifndef DELETE_PLALINDROME_H
#define DELETE_PLALINDROME_H

/*
** 给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何
** 删除才能使得回文串最长呢？输出需要删除的字符个数。
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/*解题思路是寻找原串和反串的最长公共子序列*/
void plalindrome()
{
	string str, rstr;
	while (cin >> str)
	{
		rstr = str;
		reverse(rstr.begin(), rstr.end());
		int len = str.size();
		vector<vector<int>> lcs(len + 1, vector<int>(len + 1, 0));
		for (int i = 1; i <= len; i++)
		{
			for (int j = 1; j <= len; j++)
			{
				if (str[i - 1] == rstr[j - 1])
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				else
					lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
		cout << len - lcs[len][len] << endl;
	}
}

#endif // !DELETE_PLALINDROME_H

