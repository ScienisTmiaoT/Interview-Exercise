/*
** Author: Marvin
** Date: 2017 / 03 / 25
*/
#ifndef DELETE_PLALINDROME_H
#define DELETE_PLALINDROME_H

/*
** ����һ���ַ���s������Դ���ɾ��һЩ�ַ���ʹ��ʣ�µĴ���һ�����Ĵ������
** ɾ������ʹ�û��Ĵ���أ������Ҫɾ�����ַ�������
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/*����˼·��Ѱ��ԭ���ͷ����������������*/
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

