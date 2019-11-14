#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
//#define int int64_t
//#define double long double
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//vector<int> a;
	// ->int64_t solve() {...
	int lg = a.size();

	map<int,int64_t> mp;
	for(int i=0; i<lg; i++) {
		int id = a[i];
		mp[id]++;
	}
	
	int64_t ct = 0;
	for(auto p : mp) {
		ct += p.second*(p.second-1);
	}
	
	//cout <<  << endl;
	return ct;
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

/*map<int,int> mp;
for(auto p : mp) {
	ct += p.second*(p.second-1); }

map<int,int>::iterator itr;
for(itr = mp.begin(); itr != mp.end(); itr++) {
	ans += itr->second * (itr->second-1);
}*/
