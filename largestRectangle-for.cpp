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
//vvec dp(MAX_N, vec(MAX_H));

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	/* number of tryal: begin
	int T; cin >> T;
	while(T > 0) { */
	
	int n; cin >> n;
	vec h(n+1); rep(i, n) cin >> h[i];
	h[n] = 0;
	
	int ans = 0; int id = 0;
	stack<int> s;
	
	//for roop - update condition not stated:
	for(int i=0; i<n+1;) {
		if(s.empty() || h[s.top()] < h[i]) s.push(i++);
		else {
			id = s.top();
			s.pop();
			int w = s.empty()? i : (i-s.top()-1);
			ans = max(ans, h[id]*w);  //dp-like update
		}
	}
	
	cout << ans << endl;
	
	/* number of tryal: end
	T--; } */
	
	return 0;
}
