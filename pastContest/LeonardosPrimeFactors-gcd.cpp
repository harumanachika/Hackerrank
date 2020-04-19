#include <bits/stdc++.h>
using namespace std;

//プロトタイプ宣言

//グローバル変数

//関数：
/* ユークリッドの互除法 */
long gcd(long x, long y) {
	if(x > y) swap(x, y);
	
	long ans;
	while(x > 0) {
		ans = x;
		x = y % x;
		y = ans;
	}
	return ans;
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//long n;
	if(n == 1) return 0;
	//if(n == 2) return 1;
	
	//long nn = sqrt(n);
	vector<long> prime = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
	long ctn = 0;
	long ctq = 1;
	//for(long i=3; (ctq*i)<=n; i+=2) {
	for(int i=0; (ctq*prime[i])<=n; i++) {
	//	if(gcd(ctq, i) == 1) {
			ctq *= prime[i];
			ctn++;
	//	}
	}
	
	//cout << << endl;
	return ctn;
}

/* --
	if(n == 1) return 0;

	long ctn = 1;
	long ctq = 2;
	for(long i=3; (ctq*i)<=n; i+=2) {
		if(gcd(ctq, i) == 1) {
			ctq *= i;
			ctn++;
		}
	}
	
