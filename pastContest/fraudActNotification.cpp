#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
//#define int int64_t
//#define double long double
using namespace std;

/* 分布数え上げソート（aをソートしてbに格納） */
void countsort(vector<int> &a, vector<int> &b) {
	int lg = a.size();
	map<int, int> mp;
	int mx = 0;
	
	for(int i=0; i<lg; i++) {
		mp[a[i]]++;
		if(a[i] > mx) mx = a[i];
	}
	for(int i=1; i<=mx; i++) mp[i] += mp[i-1];
	for(int i=lg-1; i>=0; --i) b[--mp[a[i]]] = a[i];	
}



int twicemedian(vector<int> &arr, vector<int> accum, int d) {
	int lg = arr.size();
	//map<int,int> accum;
	int mx = 200;
	//for(int i=0; i<lg; i++) {
	//	if(arr[i] > mx) mx = arr[i];
	//}
	//for(int i=0; i<=mx; i++) accum[i] = mp[i];
	for(int i=1; i<=mx; i++) accum[i] += accum[i-1];
	
	int med;
	int a = 0; int b = 0;
	
	if(d%2 == 0) {
		int mid_1 = d/2; int mid_2 = mid_1 + 1;
		for(int i=0; i<=mx; i++) {
			if(mid_1 <= accum[i]) {
				a = i;
				break;
			}
		}
		for(int i=a; i<=mx; i++) {
			if(mid_2 <= accum[i]) {
				b = i;
				break;
			}
		}
	} else {
		int mid_1 = d/2 + 1;
		for(int i=0; i<=mx; i++) {
			if(mid_1 <= accum[i]) {
				a = i*2;
				break;
			}
		}
	}
	
	med = a + b;
	return med;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, d; cin >> n, d;
	vector<int> expenditure(n);
	for(int i=0; i<n; i++) cin >> expenditure[i];
	
	//vector<int> expenditure, int d
	int lg = expenditure.size();
	vector<int> mp(200, 0);
	int ct = 0;

	mp[0] = 0;
	for(int i=0; i<d; i++) mp[expenditure[i]]++;
	for(int i=d; i<lg; i++) {
		int med = twicemedian(expenditure, mp, d);
		if(expenditure[i] >= med) ct++;
	
		mp[expenditure[i]]++;
		mp[expenditure[i-d]]--;
	}

	cout << ct << endl;
	//return ct;
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
