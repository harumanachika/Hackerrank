#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define int int64_t
#define double long double
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, c; cin >> r >> c;
	vector<string> grid(r);
	for(int i=0; i<r; i++) cin >> grid[i];

	//vector<string> grid
	int lgr = grid.size();
	int lgc = grid[0].size();
	vector<vector<int>> dp(lgr, vector<int>(lgc, 0));
	vector<vector<int>> cs;
	
	for(int i=0; i<lgr; i++)for(int j=0; j<lgc; j++) {
		if(grid[i][j] == 'B') continue;
		
		int now = 1;
		int k = 1;
		while(i-k>=0 && i+k<lgr && j-k>=0 && j+k<lgc && grid[i-k][j]=='G' && grid[i+k][j]=='G' && grid[i][j-k]=='G' && grid[i][j+k]=='G') {
			now += 4;
			k += 1;
		}
		dp[i][j] = now;
		cs.push_back(vector<int>{i, j});
	}

	vector<vector<int>> ddp(lgr, vector<int>(lgc));
	int n = cs.size();
	int ans = 0;
	int ct;
	for(int a=0; a<	n; a++) {
		int ffst = dp[cs[a][0]][cs[a][1]];
		ct = (ffst - 1) / 4;
		for(int cct = 0; cct <= ct; cct++) {
			//memcpy(ddp, dp, sizeof(dp));
			for(int i=0; i<lgr; i++)for(int j=0; j<lgc; j++) ddp[i][j] = dp[i][j];
			//if(ddp[cs[a][0]][cs[a][1]] == 0) continue;
			int fst = 1 + 4*cct;
			ddp[cs[a][0]][cs[a][1]] = 0;
			for(int k=1; k<=cct; k++) {
				ddp[cs[a][0]+k][cs[a][1]] = 0;
				ddp[cs[a][0]-k][cs[a][1]] = 0;
				ddp[cs[a][0]][cs[a][1]+k] = 0;
				ddp[cs[a][0]][cs[a][1]-k] = 0;
			}
			
			for(int i=0; i<lgr; i++)for(int j=0; j<lgc; j++) {
				if(ddp[i][j] == 0) continue;
				
				int now = 1;
				int k = 1;
				while(i-k>=0 && i+k<lgr && j-k>=0 && j+k<lgc && ddp[i-k][j]!=0 && ddp[i+k][j]!=0 && ddp[i][j-k]!=0 && ddp[i][j+k]!=0) {
					now += 4;
					k += 1;
				}
				ddp[i][j] = now;
			}
			
			int snd = 0;
			for(int i=0; i<lgr; i++)for(int j=0; j<lgc; j++) {
				if(ddp[i][j] > snd) {
					snd = ddp[i][j];
				}
			}
			
			if(fst*snd > ans) ans = fst*snd;
		}
	}
	
	//cout << ans << endl;
	return ans;

}
//std::string str;
//str = std::to_string(int i);
//bitset<3> s(N);
//int ans = (char)grid - '0';