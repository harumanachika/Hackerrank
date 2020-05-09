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
	
	int T; cin >> T;
	while(T > 0) {
	
	string s; cin >> s;
	int lg = s.size();
	stack<char> q;
	
	for(int i=0; i<lg; i++) {
		char br = s[i];
		if(br == '(' || br == '{' || br == '[') q.push(br);
		
		if(br == ')') {
			if(q.empty()) {
				q.push(0);
				break;
			}
			int tp = q.top(); q.pop();
			if(tp != '(') {
				q.push(0);
				break;
			}
		} else if(br == '}') {
			if(q.empty()) {
				q.push(0);
				break;
			}
			int tp = q.top(); q.pop();
			if(tp != '{') {
				q.push(0);
				break;
			}
		} else if(br == ']') {
			if(q.empty()) {
				q.push(0);
				break;
			}
			int tp = q.top(); q.pop();
			if(tp != '[') {
				q.push(0);
				break;
			}
		}
	}
	
	if(q.empty()) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	T--; }
	
	return 0;
}
