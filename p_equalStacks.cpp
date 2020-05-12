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
	
	int n1, n2, n3; cin >> n1 >> n2 >> n3;
	vvec cyl(3, vec(101));
	int st = 0; cyl[1].push_back(st);
	repr(i, n1) {
		int tp; cin >> tp; st += tp;
		cyl[1].push_back(st);
	}
	st = 0; cyl[2].push_back(st);
	repr(i, n2) {
		int tp; cin >> tp; st += tp;
		cyl[2].push_back(st);
	}
	st = 0; cyl[3].push_back(st);
	repr(i, n3) {
		int tp; cin >> tp; st += tp;
		cyl[3].push_back(tp);
	}
	
	int i = n1-1; int j = n2-1; int k = n3-1;
	while(cyl[1][i] != cyl[2][j]) {
		while(cyl[2][j] != cyl[3][k])) {
			
		}
	}
	
	//cout << << endl;
	
	/* number of tryal: end
	T--; } */
	
	return 0;
}
