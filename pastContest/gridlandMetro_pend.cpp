#include <bits/stdc++.h>
using namespace std;

//const int INF = 1001001001;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> track(k, vector<int>(3));
	for(int i=0; i<k; i++)for(int j=0; j<3; j++) cin >> track[i][j];

	//int n, int m, int k, vector<vector<int>> track;
	//int64_t -> gridlandMetro();
	stack<tuple<int, int, int>> mp;
	
	int64_t ct = (int64_t)m * (int64_t)n;
	if(k == 0) return ct;
	
	int id, c1, c2;
	sort(track.begin(), track.end());
	reverse(track.begin(), track.end());
	
	for(int i=0; i<k; i++) {
		id = track[i][0];
		c1 = track[i][1];
		c2 = track[i][2];
		
		mp.push(make_tuple(id, c1, c2));
	}
	
	tuple<int, int, int> tp, ts;
	while(!mp.empty()) {
		tp = mp.top(); mp.pop();
		
		if(mp.empty()) {
			ct = ct - ((int64_t)get<2>(tp)-(int64_t)get<1>(tp)+1);
			return ct;
		}
		
		ts = mp.top(); mp.pop();
		
		if(get<0>(tp) == get<0>(ts)) {
			int e = max(get<1>(tp), get<1>(ts));
			int b = min(get<2>(tp), get<2>(ts));
			if(e > b) {
			//非連結の場合:
				
				ct = ct - ((int64_t)get<2>(ts)-(int64_t)get<1>(ts)+1);
				mp.push(tp);
				//実際には不可："+1" -> "-1"
				
			} else {
			//連結の場合:
				id = get<0>(tp);
				c1 = min(get<1>(tp), get<1>(ts));
				c2 = max(get<2>(tp), get<2>(ts));
				
				mp.push(make_tuple(id, c1, c2));
			}
		} else {
			ct = ct - ((int64_t)get<2>(tp)-(int64_t)get<1>(tp)+1);
			
			mp.push(ts);
		}
	}
	
	//cout << ct << endl;
	return ct;
}
