#include <bits/stdc++.h>
using namespace std;

//プロトタイプ宣言

//グローバル変数
const int64_t mod = 1000000007;
//const int INF = ;
//const int MAX_N = ;
//const int MAX_M = ;
//vvec dp(MAX_N, vec(MAX_M));

//関数：
int64_t mod_pow(int64_t a, int64_t b) {
	int64_t ans = 1;
	
	while(b != 0) {
		if(b & 1) ans = ans*a % mod;
		a = a*a % mod;
		b = b >> 1;
	}
	
	return ans;
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	
	//int n, int m;
	int mx = max(m-1, n);
	int mn = min(m-1, n);
	int64_t Nr = 1;
	int64_t Dr = 1;
	for(int i=mx+mn; i>mx; i--) Nr = ((Nr%mod) * (i%mod)) % mod;
	for(int i=mn; i>0; i--) Dr = ((Dr%mod) * (i%mod)) % mod;
	
	//int tmp = 1;
	//for(int i=1; i<=mod-2; i++) tmp = ((tmp%mod)*(Dr%mod))%mod;
	//long ans = (Nr * tmp) % mod;
	int64_t ans = (Nr * mod_pow(Dr, mod-2)) % mod;

	cout << ans << endl;
	return 0;
}
