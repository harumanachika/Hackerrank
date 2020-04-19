#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define rep(i, N) for(int i=0; i<N; i++)
#define rep2(i, j, M) for(int i=j; i<M; i++)
#define repr(i, N) for(int i=N-1; i>=0; --i)
#define all(v) v.begin(),v.end() 
using namespace std;
using pr = pair<int, int>;
using tup  = tuple<int, int, int>;
using vec  = vector<int>;
using vvec = vector<vec>;

//グローバル変数 関数：
//vvec dp(MAX_N, vec(MAX_M));


/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	/* number of tryal: begin
	int T; cin >> T;
	while(T > 0) { */
	
	int n, k; cin >> n >> k;
	vec c(n); rep(i, n) cin >> c[i];
	
	sort(all(c)); reverse(all(c));
	
	int s = 0;
	int rv = 0;
	while(k*s < n) {
		rep2(i, k*s, k*(s+1)) {
			if(i >= n) break;
			rv += c[i]*(s+1);
		}
		s++;
	}
	
	cout << rv << endl;
	
	/* number of tryal: end
	T--; } */
	
	return 0;
}
