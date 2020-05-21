#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define rep(i, N) for(int i=0; i<N; i++)
#define rep2(i, j, M) for(int i=j; i<M; i++)
#define repr(i, N) for(int i=N-1; i>=0; --i)
#define all(v) v.begin(),v.end() 
using namespace std;
using vec  = vector<int>;
using vvec = vector<vec>;
typedef pair<int,int> pr;
typedef tuple<int,int> tup;

//グローバル変数 関数：
//vvec dp(MAX_N, vec(MAX_M));


/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T; cin >> T;
	while(T > 0) {
	
	int n, m, x; cin >> n >> m >> x;
	vec a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	
	int ida = 0; int idb = 0;
	int rsm = 0; int ans = 0;
	while(rsm+a[ida] <= x && ida < n) {
		rsm += a[ida];
		ida++;
	}
	ans = ida;
	
	while(ida >= 0 && idb < m) {
		rsm += b[idb];
		idb++;
		while (rsm > x && ida > 0) {
			ida--;
			rsm -= a[ida];
		}
		if(rsm <= x && ida+idb > ans) ans = ida+idb;
	}
	
	cout << ans << endl;
	
	T--; }
	
	return 0;
}
