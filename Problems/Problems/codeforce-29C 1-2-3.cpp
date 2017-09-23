/*
Ilya is working for the company that constructs robots. Ilya writes programs for entertainment robots, and his current project is "Bob", a new-generation game robot. Ilya's boss wants to know his progress so far. Especially he is interested if Bob is better at playing different games than the previous model, "Alice".

So now Ilya wants to compare his robots' performance in a simple game called "1-2-3". This game is similar to the "Rock-Paper-Scissors" game: both robots secretly choose a number from the set {1, 2, 3} and say it at the same moment. If both robots choose the same number, then it's a draw and noone gets any points. But if chosen numbers are different, then one of the robots gets a point: 3 beats 2, 2 beats 1 and 1 beats 3.

Both robots' programs make them choose their numbers in such a way that their choice in (i + 1)-th game depends only on the numbers chosen by them in i-th game.

Ilya knows that the robots will play k games, Alice will choose number a in the first game, and Bob will choose b in the first game. He also knows both robots' programs and can tell what each robot will choose depending on their choices in previous game. Ilya doesn't want to wait until robots play all k games, so he asks you to predict the number of points they will have after the final game.

Input
The first line contains three numbers k, a, b (1 ≤ k ≤ 1018, 1 ≤ a, b ≤ 3).

Then 3 lines follow, i-th of them containing 3 numbers Ai, 1, Ai, 2, Ai, 3, where Ai, j represents Alice's choice in the game if Alice chose i in previous game and Bob chose j (1 ≤ Ai, j ≤ 3).

Then 3 lines follow, i-th of them containing 3 numbers Bi, 1, Bi, 2, Bi, 3, where Bi, j represents Bob's choice in the game if Alice chose i in previous game and Bob chose j (1 ≤ Bi, j ≤ 3).

Output
Print two numbers. First of them has to be equal to the number of points Alice will have, and second of them must be Bob's score after k games.

Examples
input
10 2 1
1 1 1
1 1 1
1 1 1
2 2 2
2 2 2
2 2 2
output
1 9
input
8 1 1
2 2 1
3 3 1
3 1 3
1 1 1
2 1 1
1 2 3
output
5 2
input
5 1 1
1 2 2
2 2 2
2 2 2
1 2 2
2 2 2
2 2 2
output
0 0

分析：两个机器人的选择的不同组合最多只有9种，故关键在于找到循环节
*/
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
const double esp = 0.00000001;

//ostringstream s1, s2;

int A[4][4], B[4][4];
int C[4][4];
int sa[10], sb[10];


int main()
{
	long long k, a, b;
	cin >> k >> a >> b;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++) {
			C[i][j] = 0;
			cin >> A[i][j];
		}
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> B[i][j];

	int ith = 1;
	while (C[a][b] == 0) {
		sa[ith] = sb[ith] = 0;
		if (a < b) {
			if (a == 1 && b == 3) sa[ith]++;
			else sb[ith]++;
		}
		else if (a > b) {
			if (a == 3 & b == 1) sb[ith]++;
			else sa[ith]++;
		}

		C[a][b] = ith++;
		int ta = A[a][b];
		int tb = B[a][b];
		a = ta; b = tb;
	}
	long long ans1 = 0, ans2 = 0;
	for (int i = 1; i < C[a][b] && i <= k; i++) {
		ans1 += sa[i];
		ans2 += sb[i];
	}
	if (k >= C[a][b]) {
		int len = ith - C[a][b];
		int ta = 0, tb = 0;
		for (int i = C[a][b]; i < ith; i++) {
			ta += sa[i];
			tb += sb[i];
		}
		k = k - C[a][b] + 1;
		ans1 += (k / len)*ta;
		ans2 += (k / len)*tb;
		int end = k % len + C[a][b] - 1;
		for (int i = C[a][b]; i <= end; i++) {
			ans1 += sa[i];
			ans2 += sb[i];
		}
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}