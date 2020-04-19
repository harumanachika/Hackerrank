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
	
	int T; cin >> T;
	while(T > 0) {	
	
	int n; cin >> n;
	int ct3 = 0, ct5 = 0, ct15 = 0;
	bool frag = false;
	
	for(int i=0; n-15*i>=0; i++) {
		rep(j, 3)rep(k, 5) {
			if(5*j+3*k+15*i == n) {
				ct5 = k;
				ct3 = j;
				ct15 = i;
				frag = true;
			}
		}
	}
	
	if(frag) {
		rep(i, ct15*15) cout << 5;
		rep(i, ct5*3) cout << 5;
		rep(i, ct3*5) cout << 3;
		cout << endl;
	} else cout << -1 << endl;
	
	T--; }	
	return 0;
}
