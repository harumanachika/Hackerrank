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
	
	int n; cin >> n;
	if(n == 0) {
		cout << 0 << endl;
		continue;
	}
	map<int, int> mp;
	rep(i, n) {
		int tp; cin >> tp;
		mp[tp]++;
	}
	
	map<int, int>::iterator itr = mp.end(); itr--;
	int prv = itr->first;
	int frq = itr->second;
	(itr->second)--;
	int ct = 1;
	int mn = 0;
	map<int, int>::iterator anc = itr;
	
	while(1) {
		while(1) {
			itr--;
			if(itr->second < frq) break;
			
			if(itr->first == prv-1) {
				prv = itr->first;
				frq = itr->second;
				(itr->second)--;
				ct++;
				continue;
			} else break;
		}
		
		if(mn == 0) mn = ct;
		else if(ct < mn) mn = ct;
		
		while(anc->second == 0 && anc != mp.begin()) anc--;
		
		if(anc->second != 0 && anc != mp.begin()) {
			itr = anc;
			prv = itr->first;
			frq = itr->second;
			(itr->second)--;
			ct = 1;
		} else break;
	}
	
	cout << mn << endl;
	
	T--; }
	
	return 0;
}

/*
map<int,int>::iterator itr, itr1, itr2;
for(itr = mp.begin(); itr != mp.end(); itr++) {
	ans += itr->second * (itr->second-1);
}

distance(itr1, itr2);
advance(itr, k);
next(itr, k); //=itr + k;
*itr;
itr = mp.begin(); mp.erase(itr);
itr = prev(mp.end());
*/
