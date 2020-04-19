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
int n, m, s; //declare cut.
vector<bool> v(MAX_N);
vector<vector<eg>> mp(MAX_M, vector<eg>());
vector<int> aans(MAX_N);

//関数：
void dks(int id) {
	v[id] = true;
	aans[id] = 0;
	P mn; mn.second = id; mn.first = 0;
	
	priority_queue<P, vector<P>, greater<P>> q;
	q.push(mn);
	while(!q.empty()) {
		mn = q.top(); q.pop();
		v[mn.second] = true;
		//q.clear()
		
		if(aans[mn.second] < mn.first) continue;
		
		for(int j=0; j<mp[mn.second+1].size(); j++) {
			int jj = mp[mn.second+1][j].to; jj--;
			int cc = mp[mn.second+1][j].cost;
			if(!v[jj] && aans[mn.second]+cc < aans[jj]) {
				aans[jj] = aans[mn.second]+cc;
				q.push(make_pair(aans[jj], jj));
			}
		}
	}
	
	return;
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<vector<int>> edges(m, vector<int>(3));
	for(int i=0; i<m; i++)for(int j=0; j<3; j++) cin >> edges[i][j];
	cin >> s;
	
	//int n, vector<vector<int>> edges, int s;
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
	s--;
	
	//Initialize.
	v.resize(n);
	for(int i=0; i<n; i++) v[i] = false;
	//memset(v, false, sizeof(v));
	//mp.resize(n, vector<eg>());
	aans.resize(n);
	for(int i=0; i<n; i++) aans[i] = INF;
	//fill(aans, aans+n, INF);
	
	dks(s);

	vector<int> ans(n-1);
	int j = 0;
	for(int i=0; i<n; i++) {
		if(i != s) {
			if(aans[i] != INF) ans[j] = aans[i];
			else ans[j] = -1;
			j++;
		}
	}
	
	v.clear();
	for(int i=1; i<=n; i++) mp[i].clear();
	//mpのindexは1からスタート
	aans.clear();

	for(int i=0; i<n-1; i++) cout << ans[i] << ' ';
	cout << endl;
	//return ans;
}
