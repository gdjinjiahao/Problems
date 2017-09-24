/*
You're now a baseball game point recorder.

Given a list of strings, each string can be one of the 4 following types:

1.Integer (one round's score): Directly represents the number of points you get in this round.
2."+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
3."D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
4."C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
Each round's operation is permanent and could have an impact on the round before and the round after.

You need to return the sum of the points you could get in all the rounds.
分析：借助类似栈的结构即可实现。
*/
class Solution {
public:
	int calPoints(vector<string>& ops) {
		long long sum = 0;
		int n = 0;
		for (int i = 0; i<ops.size(); i++) {
			string t = ops[i];
			if (t[0] == '+') {
				e[n] = e[n - 1] + e[n - 2];
				sum += e[n];
				n++;

			}
			else if (t[0] == 'D') {
				e[n] = e[n - 1] << 1;
				sum += e[n];
				n++;
			}
			else if (t[0] == 'C') {
				n--;
				sum -= e[n];
			}
			else {
				int tn = 0;
				if (t[0] == '-') {
					for (int i = 1; i<t.length(); i++) tn = tn * 10 + t[i] - '0';
					tn *= -1;
				}
				else
					for (int i = 0; i<t.length(); i++) tn = tn * 10 + t[i] - '0';
				e[n] = tn;
				sum += e[n];
				n++;
			}
		}
		return sum;
	}
private:
	int e[1010];
};