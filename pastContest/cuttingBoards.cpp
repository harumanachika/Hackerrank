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
int const mod = 1000000007;


/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T; cin >> T;
	while(T > 0) {
	
	int m, n; cin >> m >> n;
	priority_queue<pr> q;
	rep(i, m-1) {
		pr tp;
		cin >> tp.first;
		tp.second = 0;
		q.push(tp);
	}
	rep(i, n-1) {
		pr tp;
		cin >> tp.first;
		tp.second = 1;
		q.push(tp);
	}
	
	int ans = 0;
	int y = 1, x = 1;
	while(!q.empty()) {
		pr tp;
		tp = q.top(); q.pop();
		if(tp.second == 0) {
			ans = (ans + (tp.first*x % mod)) % mod;
			y++;
		} else {
			ans = (ans + (tp.first*y % mod)) % mod;
			x++;
		}
	}
	
	cout << ans << endl;
	
	T--; }
	
	return 0;
}
