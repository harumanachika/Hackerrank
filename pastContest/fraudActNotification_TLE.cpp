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

int median(vector<int> arr) {
	int lg = arr.size();
	int med;
	vector<int> v(lg);
	countsort(arr, v);
	if(lg%2 != 0) {
		med = v[lg/2];
	} else {
		med = (v[lg/2-1]+v[lg/2])/2 + 1;
	}	
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
	int mid = d / 2;
	vector<int>::iterator itr = expenditure.begin();
	int ct = 0;
	for(int i=0; i<lg-d; i++) {
        vector<int> sub(itr+i,itr+i+d); //イテレーターで部分数列を指定
        int med = median(sub);
        if(expenditure[i+d] >= 2*med) ct++;
    }    
    //cout << ct << endl;
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
