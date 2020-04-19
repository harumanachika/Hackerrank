#include <bits/stdc++.h>
using namespace std;

//グローバル変数 関数：
const int mod = 1000000007;
int64_t mod_pow(int64_t a, int64_t b) {
	int64_t ans = 1;
	
	while(b != 0) {
		if(b & 1) ans = ans*(int64_t)a % mod;
		a = a*a % mod;
		b = b >> 1;
	}
	
	return ans;
}

int64_t mod_fact(int64_t n) {
	int64_t ans = 1;
	
	while(n >= 2) {
		ans = ans*((int64_t)n%mod) % mod;
		n -= 1;
	}
	
	return ans;
}

//bad_alloc /Aborted.
const int MAX_NM = 1000005;
vector<vector<int>> arr_memo(MAX_NM, vector<int>(MAX_NM, 0));

//dfs code: Timeout.
int64_t arr(int i, int j) {
	if(i == 1 || j == 1) return 1;
	
	if(arr_memo[i][j] != 0) return arr_memo[i][j];
	else {
		arr_memo[i][j] = (arr(i-1, j) + arr(i, j-1))%mod;
		arr_memo[j][i] = arr_memo[i][j];
		return arr_memo[i][j];
	}
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int64_t n, m; cin >> n >> m;
	
	//int n, int m;
	//int -> int64_t solve() {
	int64_t ans;
	
	//ans = arr(n, m);
	
	int64_t nomi = mod_fact(n+m-2);
	int64_t denomi = mod_fact(n-1) * mod_fact(m-1);
	ans = ((nomi%mod) * (mod_pow(denomi, mod-2)%mod)) % mod;
	
	cout << ans << endl;
	return 0;
}
