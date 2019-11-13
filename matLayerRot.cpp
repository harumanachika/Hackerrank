#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
//#define int int64_t
//#define double long double
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, r; cin >> N >> M >> r;
	vector<vector<int>> matrix(N, vector<int>(M));
	for(int i=0; i<N; i++)for(int j=0; j<M; j++) cin >> matrix[i][j];
	
	//vector<vector<int>> matrix, int r
	int lgr = matrix.size();
	int lgc = matrix[0].size();
	int m = lgr; int n = lgc; int pd;
	pd = 2*(m+n) - 4;
	vector<int> v; //Stack to the vector variable using 'push_back'.
	vector<int> tmp(pd-rr);

	//vector<vector<int>> ans(lgr, vector<int>(lgc));
	int itr = min(lgr, lgc) / 2;
	for(int i=0; i<itr; i++) {
		m = lgr - i; //range i:m
		n = lgc - i; //range i:n
		pd = 2*(m+n) - 4*i - 4; 
		int rr = r % pd;
		for(int j=i; j<m; j++) {
			v.push_back(matrix[j][i]);
		}
		for(int j=i+1; j<n ;j++) {
			v.push_back(matrix[m-1][j]);
		}
		for(int j=m-2; j>=i; --j) {
			v.push_back(matrix[j][n-1]);
		}
		for(int j=n-2; j>i; --j) {
			v.push_back(matrix[i][j]);
		}
		
		//cout << v.size() << ":" << pd << endl;
		//for(int i=0; i<pd; i++) cout << v[i] << ' ';
		//cout << endl;
		
		//rotation
		for(int j=pd-rr; j<pd; j++) tmp[j-pd+rr] = v[j];
		for(int j=pd-rr-1; j>=0; --j) v[j+rr] = v[j];
		for(int j=0; j<rr; j++) v[j] = tmp[j];
		
		//for(int i=0; i<pd; i++) cout << v[i] << ' ';
		//cout << endl;
		
		//rotation - end
		
		for(int j=i; j<m; j++) {
			matrix[j][i] = v.front();
			v.erase(v.begin());
		}
		for(int j=i+1; j<n; j++) {
			matrix[m-1][j] = v.front();
			v.erase(v.begin());
		}
		for(int j=m-2; j>=i; --j) {
			matrix[j][n-1] = v.front();
			v.erase(v.begin());
		}
		for(int j=n-2; j>i; --j) {
			matrix[i][j] = v.front();
			v.erase(v.begin());
		}
	}
	
	for(int i=0; i<lgr; i++)for(int j=0; j<lgc; j++) {
			cout << matrix[i][j];
			if(j == lgc-1) cout << endl;
			else cout << ' ';
	}
	//return 0;
}
//std::string str;
//str = std::to_string(int i);
//bitset<3> s(N);
//int ans = (char)grid - '0';
//int id = lower_bound(all(arr), x) - arr.begin();

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
