#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
//#define int int64_t
//#define double long double
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];

	//vector<int> arr;
	//->int64_t lilysHomework()
	int lg = arr.size();
	vector<int> original(lg);
	for(int i=0; i<lg; i++) original[i] = arr[i];

	map<int64_t,int> mp;
	for(int i=0; i<lg; i++) mp[arr[i]] = i;
	vector<int> ordered(lg);
	for(int i=0; i<lg; i++) ordered[i] = arr[i];
	sort(ordered.begin(), ordered.end());
	
	int64_t ct_1 = 0; int tp;
	for(int i=0; i<lg; i++) {
		if(arr[i] != ordered[i]) {
			ct_1++;
			tp = mp[ordered[i]];
			mp[arr[i]] = mp[ordered[i]];
			arr[tp] = arr[i];
			arr[i] = ordered[i];
		}
	}
	
	for(int i=0; i<lg; i++) arr[i] = original[i];
	for(int i=0; i<lg; i++) mp[arr[i]] = i;
	for(int i=0; i<lg; i++) ordered[i] = arr[i];
	sort(ordered.begin(), ordered.end());
	
	int64_t ct_2 = 0;
	for(int i=0; i<lg; i++) {
		if(arr[i] != ordered[lg-1-i]) {
			ct_2++;
			tp = mp[ordered[lg-1-i]];
			mp[arr[i]] = mp[ordered[lg-1-i]];
			arr[tp] = arr[i];
			arr[i] = ordered[lg-1-i];
		}
	}
	
	int ans = min(ct_1, ct_2);
	
	//cout <<  << endl;
	return ans;
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
