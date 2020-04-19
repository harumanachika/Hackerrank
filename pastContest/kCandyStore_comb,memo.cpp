#include <bits/stdc++.h>
using namespace std;

//グローバル変数 関数：
const int MAX_N = 1005;
const int mod = 1000000000;
vector<vector<int>> c(MAX_N, vector<int>(MAX_N, 0));

int conbi(int m, int r) {
	if(m <= 0 || r < 0 || m < r) return 0;
	if(m == 1 || r == 0) return 1; // r=0 -> ?
	if(r == 1) return m;
	
	if(c[m][r] != 0) return c[m][r];
	else return c[m][r] = (conbi(m-1, r) + conbi(m-1, r-1)) % mod;
}
 
/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//int n, int k;
	int ans = conbi(n+k-1, n-1);
	
	//cout << << endl;
	return ans;
}

/*	(n * m) % dvs = ((n%dvs) * (m%dvs)) % dvs
	int: (N+X+1)/X -> N/Xの切り上げ
*/
