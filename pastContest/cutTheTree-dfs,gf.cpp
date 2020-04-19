#include <bits/stdc++.h>
//#define _GLIBCXX_DEBUG
//#define int int64_t
//#define double long double
//#define rep(i, N) for(int i=0; i<N; i++)
//#define repr(i, N) for(int i=N-1; i>=0; --i)
//#define all(v) v.begin(),v.end() 
using namespace std;
//using pr = pair<int, int>;
//using tup  = tuple<int, int, int>;
//using vec  = vector<int>;
//using vvec = vector<vec>;

//プロトタイプ宣言

//グローバル変数
const int INF = 100005005;
const int MAX_N = 100005;
//const int MAX_M = ;
//vvec dp(MAX_N, vec(MAX_M));
vector<int> data(MAX_N);
vector<bool> v(MAX_N);
//vector<vector<int>> edges;
vector<vector<int>> mp(MAX_N+1, vector<int>());
int lg, vt, tl;
int ans = INF;

//関数：
int dfs(int id) {
	int low = data[id-1];
	v[id-1] = true;
	
	for(int i=0; i<mp[id].size(); i++) {
		if(v[mp[id][i]-1] == false) {
			low += dfs(mp[id][i]);
		}
	}
	
	if(abs((tl-low)-low) < ans) {
		ans = abs((tl-low)-low);
	}
	
	return low;
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//vector<int> data, vector<vector<int>> edges;
	lg = data.size();
	vt = edges.size();
	
	v.resize(lg, false);
	tl = 0;
	for(int i=0; i<lg; i++) tl += data[i];
	
	for(int i=0; i<vt; i++) {
		mp[edges[i][0]].push_back(edges[i][1]);
		mp[edges[i][1]].push_back(edges[i][0]);
	}
	
	dfs(1);
	
	//cout << << endl;
	return ans;
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
