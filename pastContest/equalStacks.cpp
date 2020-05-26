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
	int h1 = 0; int h2 = 0; int h3 = 0;
	vec tw1, tw2, tw3;
	rep(i, n1) {
		int tp; cin >> tp;
		tw1.push_back(tp);
		h1 += tp;
	}
	rep(i, n2) {
		int tp; cin >> tp;
		tw2.push_back(tp);
		h2 += tp;
	}
	rep(i, n3) {
		int tp; cin >> tp;
		tw3.push_back(tp);
		h3 += tp;
	}
	
	int p1 = 0; int p2 = 0; int p3 =0;
	bool frag = false;
	if(h1 == h2 && h2 == h3) frag = true;
	while(!frag) {
		if(h1 >= h2 && h1 >= h3) {
			h1 -= tw1[p1];
			p1++;
		} else if(h2 >= h1 && h2 >= h3) {
			h2 -= tw2[p2];
			p2++;
		} else if(h3 >= h1 && h3 >= h2) {
			h3 -= tw3[p3];
			p3++;
		}
		
		if(h1 == h2 && h2 == h3) frag = true;
	}
	
	cout << h1 << endl;
	
	/* number of tryal: end
	T--; } */
	
	return 0;
}
