#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, d; cin >> N >> d;
	vector<int> arr(N);
	for(int i=0; i<N; i++) cin >> arr[i];
	
	//int d , vector<int> arr,
	int ans = 0;
	int lg = arr.size();
	const int INF = 10005;

	vector<pair<int,int>> iv(lg-1);
	for(int i=0; i<lg-1; i++) {
		int sm = 0;
		int j = i;
		iv[i].first = i;
		while(sm < d) {
			if(j >= lg-1) break;
			sm += (arr[j+1]-arr[j]);
			j++;
		}
		if(sm == d) iv[i].second = j;
		else iv[i].second = INF;
	}

	for(int i=0; i<lg-1; i++) {
		if(iv[i].second < lg-1) {
			int k = iv[i].second;
			if(iv[k].second < lg) ans++;
		}
	}
	return ans;
}
//std::string str;
//str = std::to_string(int i);
//bitset<3> s(N);
//int ans = (char)grid - '0';