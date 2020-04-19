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

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T; cin >> T;
	while(T > 0) { 
	
	int a, b, x; cin >> a >> b >> x;
	int k = round(pow(a, b)/x);
	
	cout << fixed << setprecision(0) << k*x << endl;
	
	T--; }
	
	return 0;
}

