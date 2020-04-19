#include <bits/stdc++.h>
using namespace std;

//グローバル変数 関数：
/* (../d)%mod = (..*(mod_pow(d, mod-2)%mod))%mod */
vector<int64_t> mod_pow(int64_t a, int64_t b, int64_t k, int64_t m) {
	vector<int64_t> ans(2);
	if(k == 0) {
		ans[0] = 1; ans[1] = 0;
		return ans;
	}

	ans[0] = 1; ans[1] = 0;
	while(k > 0) { // <- error.
		if(k & 1) {
			int tp;
			tp = (((a%m)*(ans[0]%m))%m - ((b%m)*(ans[1]%m))%m + m) % m;
			ans[1] = (((a%m)*(ans[1]%m))%m + ((b%m)*(ans[0]%m))%m) % m;
			ans[0] = tp;
		}
		int tp;
		tp = (((a%m)*(a%m))%m - ((b%m)*(b%m))%m + m) % m;
		b = (2*(a%m)*(b%m)) % m;
		a = tp;
		k = k >> 1;
	}
	
	return ans;
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int64_t a, b, k, m;
	cin >> a >> b >> k >> m;
	
	//int64_t a, b, k, m;
	vector<int64_t> ans(2);
	ans = mod_pow(a, b, k, m);
	
	for(int i=0; i<2; i++) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}

/*	(n * m) % dvs = ((n%dvs) * (m%dvs)) % dvs
	int: (N+X+1)/X -> N/Xの切り上げ
*/
