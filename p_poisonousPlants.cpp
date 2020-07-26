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
	
	int n; cin >> n;
	vec p(n); rep(i, n) cin >> p[i];
	
	int dy = -1;
	int ini = 0;
	
	while(ini != int(p.size())) {
		int cur = 1;
		int prv = p[0];
		ini = p.size();
		dy++;
		
		while(cur < int(p.size())) {
			if(p[cur] > prv) {
				prv = p[cur];
				p.erase(p.begin()+cur);
			}
			else {
				prv = p[cur];
				cur++;
			}
		}
	}
	
	cout << dy << endl;
	
	/* number of tryal: end
	T--; } */
	
	return 0;
}
