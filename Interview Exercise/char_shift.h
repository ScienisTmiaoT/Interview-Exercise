/*
** Author: Marvin
** Date: 2017 / 03 / 25
*/
#ifndef CHAR_SHIFT_H
#define CHAR_SHIFT_H

/*
** СQ���������һ�����⣺��һ���ַ����Ĵ�д��ĸ�ŵ��ַ����ĺ��棬�����ַ�
** �����λ�ò��䣬�Ҳ����������Ŀռ䡣 ���ܰ��СQ��
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
** ��Ҫ˼·���ǴӺ���ǰɨ���ַ�����ʹ������ָ�룬ָ��pre����һֱ��ǰɨ��ָ��ke�����¼��һ��Сд��ĸ��ָ��te�����¼�ڶ���Сд��ĸ
** һ������pre����λ��Ϊ��д��ĸ������ke�Ѿ���¼����Сд��ĸ����ʱ���Կ��ǽ�������Ϊ���������
** ���һ��ֻ��ke��¼����Сд��ĸ��te��δ��¼������ʱ����pre��ke����λ���ַ�
** �������ke��te����¼����Сд��ĸ����ʱ���Խ�keλ�õ��ַ��滻��preλ�õ��ַ�����teλ�õ��ַ��滻��ԭ��keλ�õ��ַ���Ȼ��һֱ��ǰ
**		  ����������ֱ������pre��λ�ã�����Ϊ�˱�֤���ڴ�д��ĸ�м������Сд��ĸ��˳�򲻱�
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
