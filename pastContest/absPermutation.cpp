#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define int int64_t
#define double long double
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//int n, int k
	
	if(k == 0) {
		vector<int> ans(n);
		for(int i=0; i<n; i++) {
			ans[i] = i+1;
		}
		return ans;
	}
	else if(n%(2*k) != 0) {
		vector<int> ans(1);
		ans[0] = -1;
		return ans;
	}
	else {
		vector<int> ans(n);
		int lg = n / (2*k);
		for(int i=0; i<lg; i++) {
			for(int j=1; j<=k; j++) {
				int id = j + (2*k*i) - 1;
				ans[id] = k + (2*k*i) + j;
			}
			for(int j=k+1; j<=2*k; j++) {
				int id = j + (2*k*i) - 1;
				ans[id] = -k + (2*k*i) + j;
			}
		}
		return ans;
	}
	//cout <<  << endl;
}
//std::string str;
//str = std::to_string(int i);
//bitset<3> s(N);
//int ans = (char)grid - '0';