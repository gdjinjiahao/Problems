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

ostringstream s1, s2;
struct Node {
	int n, a, b, c;
	int cnt;
};
stack<struct Node> s;

void f(int n, int a, int b, int c)
{
	if (n == 1) {
		//printf("%d: %d ---> %d\n", n, a, c);
		s1 << n << ": " << a << " ---> " << c << "\n";
		return;
	}
	f(n - 1, a, c, b);
	//printf("%d: %d ---> %d\n", n, a, c);
	s1 << n << ": " << a << " ---> " << c << "\n";
	f(n - 1, b, a, c);
}

void solve(int n)
{
	struct Node p, t;
	p.a = 1;
	p.b = 2;
	p.c = 3;
	p.cnt = 0;
	p.n = n;
	s.push(p);
	while (!s.empty()) {
		s.top().cnt++;
		p = s.top();
		if (p.cnt == 1) {
			if (p.n == 1) {
				s2 << p.n << ": " << p.a << " ---> " << p.c << "\n";
				s.pop();
			}
			else {
				t.a = p.a;
				t.b = p.c;
				t.c = p.b;
				t.cnt = 0;
				t.n = p.n - 1;
				s.push(t);
			}
		}
		else if (p.cnt == 2) {
			s2 << p.n << ": " << p.a << " ---> " << p.c << "\n";
			t.a = p.b;
			t.b = p.a;
			t.c = p.c;
			t.cnt = 0;
			t.n = p.n - 1;
			s.push(t);
		}
		else
			s.pop();
	}
}



int main()
{
	int n;
	cin >> n;
	f(n, 1, 2, 3);
	solve(n);
	if (s1.str() == s2.str()) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
