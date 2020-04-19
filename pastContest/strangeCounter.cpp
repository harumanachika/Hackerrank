#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define int int64_t
#define double long double
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//long t
	long an = 3; long bn = 3;
	while(t > bn) {
		an *= 2;
		bn += an;
	}
	long ans = an - (t-bn+an) + 1;

	//cout <<  << endl;
	return ans;
}
//std::string str;
//str = std::to_string(int i);
//bitset<3> s(N);
//int ans = (char)grid - '0';