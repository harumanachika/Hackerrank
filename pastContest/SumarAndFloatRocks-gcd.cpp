#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG

//プロトタイプ宣言

//グローバル変数 関数：
int gcd(int x, int y) {
	if(x > y) swap(x, y);
 
	int ans;
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

	//int x1, y1, x2, y2;
	int x = abs(x2 - x1);
	int y = abs(y2 - y1);
	
	if(x == 0) return y - 1;
	if(y == 0) return x - 1;

	int ans = gcd(x, y) - 1;
	return ans;
}
