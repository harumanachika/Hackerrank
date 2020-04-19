#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define int int64_t
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//vector<int> a
	int lg = a.size();
	int const INF = 1005;

	int mx = INF;
	for(int i=0; i<lg-1; i++) {
		int dst = INF;
		for(int j=i+1; j<lg; j++) {
			if(a[i] == a[j]) dst = j - i;
			if(mx > dst) mx = dst;
		}
	}
	if(mx == INF) mx = -1;

	//cout <<  << endl;
	return mx;
}
//std::string str;
//str = std::to_string(int i);
//bitset<3> s(N);
//int ans = (char)grid - '0';