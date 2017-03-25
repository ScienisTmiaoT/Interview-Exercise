/*
** Author: Marvin
** Date: 2017 / 03 / 25
*/
#ifndef CHAR_SHIFT_H
#define CHAR_SHIFT_H

/*
** 小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符
** 的相对位置不变，且不能申请额外的空间。 你能帮帮小Q吗？
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
** 主要思路就是从后往前扫描字符串，使用三个指针，指针pre负责一直往前扫，指针ke负责记录第一个小写字母，指针te负责记录第二个小写字母
** 一旦遇到pre所在位置为大写字母，并且ke已经记录到了小写字母，此时可以考虑交换，分为两种情况：
** 情况一：只有ke记录到了小写字母而te并未记录到，此时交换pre和ke所在位置字符
** 情况二：ke和te都记录到了小写字母，此时可以将ke位置的字符替换成pre位置的字符，将te位置的字符替换成原来ke位置的字符，然后一直向前
**		  两两交换，直到到达pre的位置，这是为了保证夹在大写字母中间的所有小写字母的顺序不变
**
*/
void charshift()
{
	string s;
	while (cin >> s)
	{
		int len = s.size();
		int pre = len - 1;
		int ke = -1;
		int te = -1;
		while (pre >= 0)
		{
			if (s[pre] >= 'A' && s[pre] <= 'Z')
			{
				if (pre < ke)
				{
					if (te == -1)
					{
						char t = s[ke];
						s[ke] = s[pre];
						s[pre] = t;
						ke = pre;
					}
					else
					{
						char t = s[ke];
						s[ke] = s[pre];
						int ba = te - 1;
						char d = s[te];
						while (ba >= pre)
						{
							char k = s[ba];
							s[ba] = d;
							d = k;
							ba--;
						}
						s[te] = t;
						ke--;
						te--;
					}
				}
			}
			else if (ke == -1)
				ke = pre;
			else if (te == -1)
				te = pre;
			pre--;
		}
		cout << s << endl;
	}
}

#endif // !CHAR_SHIFT_H
