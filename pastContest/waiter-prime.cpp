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

/* エラトステネスのふるい */
const int MAX_P = 10000;
queue<int> prime; vector<int> v(MAX_P, 0);
void getprime() {
	//memset(v, 0, sizeof(v));
	for(int i=2; i<MAX_P; i++) {
		if(v[i] == false) {
			prime.push(i);
			for(int j=2; i*j<MAX_P; j++) v[i*j] = 1;
		}
	}
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	/* number of tryal: begin
	int T; cin >> T;
	while(T > 0) { */
	
	getprime();
	int n, q; cin >> n >> q;
	vector<stack<int>> a(q+1), b(q+1);
	
	rep(i, n) {
		int tp; cin >> tp;
		a[0].push(tp);
	}
	
	rep2(i, 1, q+1) {
		int p;
		if(!prime.empty()) {
			p = prime.front();
			prime.pop();
		} else p = 10001;
		while(!a[i-1].empty()) {
			int tp; tp = a[i-1].top(); a[i-1].pop();
			if(tp%p == 0) {
				b[i].push(tp);
			} else {
				a[i].push(tp);
			}
		}
	}
	
	rep2(i, 1, q+1)while(!b[i].empty()) {
		int tp; tp = b[i].top(); b[i].pop();
		cout << tp << endl;
	}
	rep2(i, 1, q+1)while(!a[i].empty()) {
		int tp; tp = a[i].top(); a[i].pop();
		cout << tp << endl;
	}
	
	/* number of tryal: end
	T--; } */
	
	return 0;
}
