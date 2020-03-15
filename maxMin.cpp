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
const int INF = 1000000005;


/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	/* number of tryal: begin
	int T; cin >> T;
	while(T > 0) { */
	
	int n, k; cin >> n; cin >> k;
	vec arr(n); rep(i, n) cin >> arr[i];
	
	sort(all(arr));
	
	int mx = INF;
	for(int i=0; i+k-1<n; i++) {
		if(arr[i+k-1]-arr[i] < mx) mx = arr[i+k-1]-arr[i];
	}
	
	cout << mx << endl;
	
	/* number of tryal: end
	T--; } */
	
	return 0;
}
