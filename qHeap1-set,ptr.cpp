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
	
	int q; cin >> q;
	set<int> st; //keyのみのmap.
	rep(i, q) {
		int op; cin >> op;
		if(op != 3) {
			int v; cin >> v;
			if(op == 1) st.insert(v);
			else st.erase(st.find(v));
		} else {
			cout << *st.begin() << endl; //pointer->iterator
		}
	}
	//cout << << endl;
	
	/* number of tryal: end
	T--; } */
	
	return 0;
}


/*	map<int,int> mp;
for(auto p : mp) {
	ct += p.second*(p.second-1); }

map<int,int>::iterator itr, itr1, itr2;
for(itr = mp.begin(); itr != mp.end(); itr++) {
	ans += itr->second * (itr->second-1);
}
*/
