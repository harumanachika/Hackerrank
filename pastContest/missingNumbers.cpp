#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
//#define int int64_t
//#define double long double
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	vector<int> arr(n); for(int i=0; i<n; i++) cin >> arr[i];
	int m; cin >> m;
	vector<int> brr(m); for(int i=0; i<m; i++) cin >> brr[i];

	//vector<int> arr vector<int> brr;
	int lga = arr.size();
	int lgb = brr.size();
	vector<int> ans;
	
	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());
	
	int i = 0; int j = 0;
	while(i < lgb) {
		if(arr[j] == brr[i]) {
			i++; j++;
		} else if(arr[j] != brr[i] && brr[i] != brr[i+1]) {
			ans.push_back(brr[i]);
			i++;
		} else {
			i++;
		}
	}
		
	//cout <<  << endl;
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
