#include <bits/stdc++.h>
using namespace std;

//プロトタイプ宣言

//グローバル変数
//const int INF = ;
const int MAX_N = 1005;
const int MAX_M = MAX_N*(MAX_N-1)/2;
//vvec dp(MAX_N, vec(MAX_M));
int n, m, s; //declare cut.
vector<bool> v(MAX_N);
vector<vector<int>> mp(MAX_M, vector<int>());
vector<int> aans(MAX_N);

//関数：
void bfsq(int id) {
	v[id] = true;
	aans[id] = 0;

	queue<int> q;
	q.push(id);
	while(!q.empty()) {
		id = q.front(); q.pop();
		for(int i : mp[id+1]) {
		//mpのindexは1からスタート
			if(!v[i-1]) {
				aans[i-1] = aans[id] + 1;
				v[i-1] = true;
				q.push(i-1);
			}
		}
	}
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<vector<int>> edges(m, vector<int>(2));
	for(int i=0; i<m; i++)for(int j=0; j<2; j++) cin >> edges[i][j];
	cin >> s;
	
	//int n, int m, vector<vector<int>> edges, int s;
	//vector<vector<int>> mp(n, vector<int>());
	for(int i=0; i<m; i++) {
		mp[edges[i][0]].push_back(edges[i][1]);
		mp[edges[i][1]].push_back(edges[i][0]);
	}
	s--;
	
	v.resize(n);
	for(int i=0; i<n; i++) v[i] = false;
	//mp.resize(n, vector<int>());
	aans.resize(n);
	for(int i=0; i<n; i++) aans[i] = -1;

	bfsq(s);
	
	vector<int>  ans(n-1);
	int j = 0;
	for(int i=0; i<n; i++) {
		if(i != s) {
			if(aans[i] != -1) ans[j] = 6*aans[i];
			else ans[j] = -1;
			j++;
		}
	}
	
	v.clear();
	//mp.clear();
	for(int i=1; i<=n; i++) mp[i].clear();
	//mpのindexは1からスタート
	aans.clear();

	//for(int i=0; i<n-1; i++) cout << ans[i] << ' ';
	//cout << endl;
	return ans;
}
