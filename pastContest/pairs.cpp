#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
//#define int int64_t
//#define double long double
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	//int k, vector<int> arr;
	int lg = arr.size();
	sort(arr.begin(), arr.end());
	
	int ct = 0;
	for(int i=0; i<lg; i++) {
		for(int j=i; j<lg; j++) {
			int dif = arr[j] - arr[i];
			if(dif == k) {
				ct++;
				break;
			} else if(dif > k) {
				break;
			}
		}
	}

	//cout <<  << endl;
	return ct;
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
