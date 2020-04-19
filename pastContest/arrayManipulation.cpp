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
	
	/* number of tryal: begin
	int T; cin >> T;
	while(T > 0) { */
	
	int n, m; cin >> n >> m;
	vec arr(n, 0);
	
	rep(i, m) {
		int a, b, k;
		cin >> a >> b >> k;
		arr[--a] += k;
		if(b+1 <= n) arr[b] -= k;
	}
	
	int mx = arr[0];
	rep2(i, 1, n) {
		arr[i] += arr[i-1];
		if(mx < arr[i]) mx = arr[i];
	}
	
	cout << mx << endl;
	
	/* number of tryal: end
	T--; } */
	
	return 0;
}
