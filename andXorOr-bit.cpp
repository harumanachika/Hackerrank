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
	vec a(n); rep(i, n) cin >> a[i];
	
	//target = ((m1 & m2) ^ (m1 | m2)) & (m1 ^ m2)
	stack<int> s;
	int mx = 0; int mn;
	rep(i, n) {
		while(!s.empty()) {
			mn = a[i] ^ s.top();
			if(mx < mn) mx = mn;
			
			if(a[i] < s.top()) s.pop();
			else break;
		}
		s.push(a[i]);
	}
	
	cout << mx << endl;
	
	/* number of tryal: end
	T--; } */
	
	return 0;
}

//std::string str;
//str = std::to_string(int i);
//bitset<3> s(N);
//int ans = (char)grid - '0';
//int id = lower_bound(all(arr), x) - arr.begin();
//cout << fixed << setprecision(10) << tld << endl;
//vector<int> sub(itr,itr+d); //イテレーターで部分数列(i=0...d)を指定
