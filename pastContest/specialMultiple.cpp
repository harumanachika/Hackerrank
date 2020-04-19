#include <bits/stdc++.h>
using namespace std;

//プロトタイプ宣言

//グローバル変数
//const int INF = ;
//const int MAX_N = ;
//const int MAX_M = ;
//vvec dp(MAX_N, vec(MAX_M));

//関数：
int64_t binary(int64_t n) {
	int64_t ans;
	if(n == 1) {
		ans = 1;
		return ans;
	}
	
	if(n%2 == 0) ans = 10*binary(n/2);
	else ans = 10*binary(n/2) + 1;
	return ans;
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//int n;
	int64_t i = 1;
	int64_t j = 9;
	while(j%n != 0) {
		i++;
		j = binary(i);
		j *= 9;
	}
	
	//cout << << endl;
	string ans = std::to_string(j);
	return ans;
}
