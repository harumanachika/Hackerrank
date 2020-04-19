#include <bits/stdc++.h>
#define int int64_t
using namespace std;

//プロトタイプ宣言

//グローバル変数
//const int INF = ;
//const int MAX_N = ;
//const int MAX_M = ;
//vvec dp(MAX_N, vec(MAX_M));

//関数：
/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int r, c; cin >> r >> c;

	//int r, int c;
	vector<int> cc = {0,2,4,6,8};
	int rr = 10*((r-1) / 2);
	
	int ans;
	if(r%2 == 0) ans = cc[c-1] + 1 + rr;
	else ans = cc[c-1] + rr;
	
	cout << ans << endl;
	return 0;
}
