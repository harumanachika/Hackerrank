#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define int int64_t
#define double long double
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, c, n; cin >> r >> c >> n;
	vector<string> grid(r);
	for(int i=0; i<r; i++) cin >> grid[i];

	//int n, vector<string> grid
	int lgr = grid.size();
	int lgc = grid[0]. size();
	const int INF = 100;

	vector<vector<int>> dp(lgr, vector<int>(lgc, INF));
	for(int i=0; i<lgr; i++)for(int j=0; j<lgc; j++) {
		if(grid[i][j] == 'O') dp[i][j] = 0;
	}

	//see end of this text.
	if(n%4 == 0 || n%4 == 2) n = 2;
	else if(n%4 == 3) n = 3;
	else if(n != 1 && n%4 == 1) n = 5;
	//see end of thix text.

	for(int t=1; t<=n; t++) {
		for(int i=0; i<lgr; i++)for(int j=0; j<lgc; j++) {
			if(dp[i][j] != INF) dp[i][j]++;
			if(t%2 == 0 && dp[i][j] == INF) dp[i][j] = 0;
			if(dp[i][j] == 3) {
				if(i-1 >= 0) dp[i-1][j] = INF;
				if(j-1 >= 0) dp[i][j-1] = INF;
				dp[i][j] = INF;
				if(j+1 < lgc && dp[i][j+1] < 2) dp[i][j+1] = INF;
				if(i+1 < lgr && dp[i+1][j] < 2) dp[i+1][j] = INF;
			}
		}
	}

	vector<string> ans(lgr);
	for(int i=0; i<lgr; i++) {
		ans[i] = grid[i];
		string &ref = ans[i];
		for(int j=0; j<lgc; j++) {
			if(dp[i][j] == INF) ref[j] = '.';
			else ref[j] = 'O';
		}
	}
	
	//for(int i=0; i<r; i++) cout << ans[i] << endl;
	return ans;
}

//n=0: Initially, Bomberman arbitrarily plants bombs in some of the cells, the initial state.
//n=1: After one second, Bomberman does nothing.
//n=2, 4, 6...: After one more second, Bomberman plants bombs in all cells without bombs, thus filling the whole grid with bombs. No bombs detonate at this point.
//n=3, 7, 11...: After one more second, any bombs planted exactly three seconds ago will detonate. Here, Bomberman stands back and observes.
//Bomberman then repeats steps 3 and 4 indefinitely.
//n=5, 9, 13...