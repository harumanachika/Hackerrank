#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define rep(i, N) for(int i=0; i<N; i++)
#define rep2(i, N, M) for(int i=N; i<M; i++)
#define repr(i, N) for(int i=N-1; i>=0; --i)
#define all(v) v.begin(),v.end() 
using namespace std;
using pr = pair<int, int>;
using tup  = tuple<int, int, int>;
using vec  = vector<int>;
using vvec = vector<vec>;

//グローバル変数 関数：
//vvec dp(MAX_N, vec(MAX_M));
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
	
	int T; cin >> T;
	while(T > 0) {
	
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	string ans = "NO";
	
	//gcd(a+n*b, b) = gcd(a, b) = gcd(a, m*a+b)
	if(gcd(a,b) == gcd(x,y)) ans = "YES";
	
	cout << ans << endl;
	
	T--; }
	
	return 0;
}

