#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
//#define int int64_t
//#define double long double
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	vector<int> a(N);
	for(int i=0; i<N; i++) cin >> a[i];
	
	//vector<int> a;
	int lg = a.size();
	vector<int> v(lg);
	sort(a.begin(), a.end());
	
	v[0] = 0;
	for(int i=1; i<lg; i++) {
		if(a[i] == a[i-1]) v[i] = v[i-1] + 1;
		else v[i] = 0;
	}
	
	int ct = 0;
	for(int i=1; i<lg; i++) ct += v[i];
	
	cout << ct*2 << endl;
	//return ct*2;
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
