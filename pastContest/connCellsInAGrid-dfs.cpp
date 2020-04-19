#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
//#define int int64_t
//#define double long double
using namespace std;

const int INF = 105105;
int MAX_N = 25;
int MAX_M = 25;
vector<vector<int>> matrix(MAX_N, vector<int>(MAX_M));
vector<vector<int>> v(MAX_N, vector<int>(MAX_M, INF));
int ans = 0;
int lgr, lgc;

bool check(int i, int j) {
	bool frag = false;
	if(i>=0 && i<lgr && j>=0 && j<lgc) frag = true;
	return frag;
}

void dfs(int i, int j) {
	//int df[] = {-1, 0, 1};
	
	for(int a=-1; a<2; a++)for(int b=-1; b<2; b++) {
		int ii = i + a;
		int jj = j + b;
		if(check(ii, jj) && matrix[ii][jj]==1 && v[ii][jj]==INF) {
			ans++;
			v[ii][jj] = 0;
			dfs(ii, jj);
		} else if(check(ii, jj) && matrix[ii][jj]==0 && v[ii][jj]==INF) {
			v[ii][jj] = 0;
		}
	}
	
	return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	for(int i=0; i<n; i++)for(int j=0; j<m; j ++) cin >> matrix[i][j];
	
	//vector<vector<int>> matrix;
	lgr = matrix.size();
	lgc = matrix[0].size();
	int mx = 0;

	for(int i=0; i<lgr; i++)for(int j=0; j<lgc; j++) {
		if(matrix[i][j] == 0 && v[i][j] == INF) v[i][j] = 0;
		else if(matrix[i][j] == 1 && v[i][j] == INF) {
			ans = 1;
			v[i][j] = 0;
			dfs(i,j);
			if(ans > mx) mx = ans;
		}
	}
	
	cout << mx << endl;
	//return mx;
}

//std::string str;
//str = std::to_string(int i);
//bitset<3> s(N);
//int ans = (char)grid - '0';
//int id = lower_bound(all(arr), x) - arr.begin();
//cout << fixed << setprecision(10) << tld << endl;
//vector<int> sub(itr,itr+d); //イテレーターで部分数列(i=0...d)を指定

/*struct data {
	char *name;
	int age;
	int height;
	double weight;
};*/

/*string ans = w;
string &ref = ans;
rep(i, N) {
	ref[i] = arr[i];
}*/

/*map<int,int> mp;
for(auto p : mp) {
	ct += p.second*(p.second-1); }

map<int,int>::iterator itr;
for(itr = mp.begin(); itr != mp.end(); itr++) {
	ans += itr->second * (itr->second-1);
}*/
