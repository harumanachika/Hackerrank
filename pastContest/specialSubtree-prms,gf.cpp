#include <bits/stdc++.h>
using namespace std;

//プロトタイプ宣言
struct eg {
	int cost, to;
};
typedef pair<int,int> P;
//priority_queueは<構造体>ではなく<pair<.>>等のみ利用可。

//グローバル変数
const int INF = 100005;
const int MAX_N = 3005;
const int MAX_M = MAX_N*(MAX_N-1)/2;
//vvec dp(MAX_N, vec(MAX_M));
int n, m, start; //declare cut.
vector<bool> v(MAX_N);
vector<vector<eg>> mp(MAX_M, vector<eg>());
//vector<int> aans(MAX_N);
int ct = 0;

//関数：
void prm(int id) {
	v[id] = true;
	P nxt; nxt.second = id; nxt.first = 0;
	
	priority_queue<P, vector<P>, greater<P>> q;
	q.push(nxt);
	while(!q.empty()) {
		nxt = q.top(); q.pop();
		if(!v[nxt.second]) {
			v[nxt.second] = true;
			ct += nxt.first;
		}
		
		for(int i=0; i<mp[nxt.second+1].size(); i++) {
			int ii = mp[nxt.second+1][i].to; ii--;
			int cc = mp[nxt.second+1][i].cost;
			
			if(!v[ii]) q.push(make_pair(cc, ii));
		}
	}
	
	return;
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//int n, vector<vector<int>> edges, int start;
	//m = edges.size();
	
	eg str;
	for(int i=0; i<m; i++) {
		str.to = edges[i][1];
		str.cost = edges[i][2];
		mp[edges[i][0]].push_back(str);
		str.to = edges[i][0];
		//str.cost = edges[i][2];
		mp[edges[i][1]].push_back(str);
	}
	start--;
	
	//Initialize.
	v.resize(n);
	for(int i=0; i<n; i++) v[i] = false;
	//memset(v, false, sizeof(v));
	//mp.resize(n, vector<eg>());
	
	prm(start);
	
	//cout << << endl;
	return ct;
}
