#include <bits/stdc++.h>
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

	//int l, int s1, int s2, vector<int> queries;
	//queries: int -> double!!!
	//cout << fixed << setprecision(6) << [result] << endl;!!!

	int lg = queries.size();
	vector<double> ans(lg);
	
	for(int i=0; i<lg; i++) {
		double mx = max((double)s1, (double)s2);
		double mn = min((double)s1, (double)s2);
		double d = (double)l - sqrt((double)queries[i]);
		if(d <= 0) ans[i] = 0.0;
		else ans[i] = sqrt(2.0)*d / (mx-mn);
	}
	
	//cout << << endl;
	return ans;
}
