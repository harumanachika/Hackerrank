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
	string s;
	stack<string> stk; 
	rep(i, n) {
		int quest; cin >>quest;
		if(quest == 1) {
			string tp; cin >> tp;
			stk.push(s);
			s += tp;
		} else if(quest == 2) {
			int tp; cin >> tp;
			stk.push(s);
			s.erase(s.size()-tp); //pending.
		} else if(quest == 3) {
			int tp; cin >> tp;
			cout << s[tp-1] << endl;
		} else {
			string tp; tp = stk.top(); stk.pop();
			s = tp;
		}
	}
	
	/* number of tryal: end
	T--; } */
	
	return 0;
}
