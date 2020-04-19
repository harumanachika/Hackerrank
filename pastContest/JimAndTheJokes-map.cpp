#include <bits/stdc++.h>
using namespace std;

//グローバル変数 関数：
const int MAX_N = 100005;
map<int, int64_t> mp;

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<vector<int>> dates(n, vector<int>(2));
	for(int i=0; i<n; i++) cin >> dates[i][1] >> dates[i][2];

	//vector<vector<int>> dates;
	int lgr = dates.size();
	for(int i=0; i<lgr; i++) {
		int d1 = dates[i][2]/10;
		int d2 = dates[i][2]%10;
		int m = dates[i][1];
		if(d1 >= m || d2 >= m) continue;
		mp[d1*m + d2]++;
	}
	
	int64_t ans = 0;
	for(auto p : mp) {
		ans += p.second*(p.second-1)/2;
	}
	
	cout << ans << endl;
	//return ans;
}

/*	(n * m) % dvs = ((n%dvs) * (m%dvs)) % dvs
	int: (N+X+1)/X -> N/Xの切り上げ
*/
