#include <bits/stdc++.h>
using namespace std;

//プロトタイプ宣言

//グローバル変数
const int INF = 100000;
//const int MAX_N = ;
//const int MAX_M = ;
//vvec dp(MAX_N, vec(MAX_M));

//関数：
/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	int best = 1;
	int ans = 1;
	for(int i=1; i<=n; i++) {
		if(n%i != 0) continue;
		
		int tp = i;
		int sm = 0;
		while(tp != 0) {
			sm += tp % 10;
			tp /= 10;
		}
		
		if(best < sm) {
			ans = i;
			best = sm;
		} else if(best == sm && ans > i) {
			ans = i;
		}
	}
	
	cout << ans << endl;
	return 0;
}
