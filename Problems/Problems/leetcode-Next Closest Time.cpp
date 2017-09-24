/*
���⣺����һ��ʱ�䣬��ʽΪHH:MM���������ʱ��ĸ�λ������ɵĸ�ʱ�����һ�����ʱ�䡣
������������α������ж��Ƿ�Ϸ�����
*/
#include <sstream>
using namespace std;
class Solution {
public:
	string nextClosestTime(string time) {
		for (int i = 0; i<10; i++) dig[i] = false;
		int h = (time[0] - '0') * 10 + time[1] - '0';
		int m = (time[3] - '0') * 10 + time[4] - '0';
		dig[time[0] - '0'] = true; dig[time[1] - '0'] = true;
		dig[time[3] - '0'] = true; dig[time[4] - '0'] = true;
		while (1) {
			m++;
			if (m >= 60) {
				h++;
				m = 0;
			}
			if (h >= 24) h = 0;
			if (yes(h, m)) break;
		}

		if (h<10) s1 << 0;
		s1 << h << ':';
		if (m<10) s1 << 0;
		s1 << m;
		return s1.str();
	}
private:
	ostringstream s1;
	bool dig[10];
	bool yes(int h, int m)
	{
		if (h<10) {
			if (!dig[0]) return false;
			if (!dig[h]) return false;
		}
		else {
			if (!dig[h / 10]) return false;
			if (!dig[h % 10]) return false;
		}

		if (m<10) {
			if (!dig[0]) return false;
			if (!dig[m]) return false;
		}
		else {
			if (!dig[m / 10]) return false;
			if (!dig[m % 10]) return false;
		}
		return true;
	}
};