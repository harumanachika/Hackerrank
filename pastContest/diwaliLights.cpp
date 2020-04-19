#include <bits/stdc++.h>
using namespace std;

//プロトタイプ宣言

//グローバル変数
//const int INF = ;
//const int MAX_N = ;
//const int MAX_M = ;
//vvec dp(MAX_N, vec(MAX_M));
const long mod = 100000;

//関数：
/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//int n;
	long ans = 1;
	for(int i=0; i<n; i++) {
		ans = (ans*2) % mod;
	}
	
	//cout << << endl;
	return ans-1;
}
