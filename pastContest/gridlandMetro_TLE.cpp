#include <bits/stdc++.h>
using namespace std;

//const int INF = 1001001001;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//int n, m, k; cin >> n >> m >> k;
	//vector<vector<int>> track(k, vector<int>(3));
	//for(int i=0; i<k; i++)for(int j=0; j<3; j++) cin >> track[i][j];

	//int n, int m, int k, vector<vector<int>> track;
	//int64_t -> gridlandMetro();
	map<int, priority_queue<int>> mp;
	
	int64_t ct = (int64_t)m * (int64_t)n;
	
	//sort(track.begin(), track.end());
	for(int i=0; i<k; i++) {
		int id = track[i][0];
		int c1 = track[i][1];
		int c2 = track[i][2];
		//bool frag = true;
		if(c2 >= c1) {
			for(int j=c1; j<=c2; j++) mp[id].push(j); 
		}
	}
	
	for(auto p : mp) {
		int lg = p.second.size();
		//sort(p.second.begin(), p.second.end());
		int ctt = 1;
		for(int i=1; i<lg; i++) {
			int a = p.second.top(); p.second.pop();
			if(p.second.top() != a) ctt++;
		}
		ct -= ctt;
	}	

	//cout <<  << endl;
	return ct;
}
