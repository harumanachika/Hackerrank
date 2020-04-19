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

	//int n;
	if(n%2 != 0) return 0;
	
	int ct = 0;
	int i = 1;
	while(i <= sqrt(n)) {
		if(n%i == 0) {
			if(i%2 == 0) ct++;
			if((n/i)%2 == 0) ct++;
		}
		if(i == sqrt(n)) ct--;
		i++;
	}
	
	//cout << << endl;
	return ct;
}
