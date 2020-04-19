#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define int int64_t
#define double long double
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//vector<int> arr
	int lg = arr.size();
	
	vector<int> d(lg);
	d[0] = 0;
	for(int i=1; i<lg; i++) {
		if(arr[i-1] <= arr[i]) d[i] = 0;
		else d[i] = d[i-1] + 1;
	}
	
	string ans;
	int st = 0;
	int ed = 0;
	
	int ct_1 = 0;
	int mx = 0;
	int id = 0;
	for(int i=1; i<lg; i++) {
		if(d[i] == 1) ct_1++;
		if(mx < d[i]) {
			mx = d[i];
			id = i;
		}
	}
	
	if(ct_1 == 0) {
		cout << "yes" << endl;
	}
	else if(ct_1 > 2 || (ct_1 == 2 && mx > 1)) {
		cout << "no" << endl;
	}
	else if(ct_1 == 2) {
		int id2;
		for(int i=id+1; i<lg; i++) {
			if(d[i] == 1) id2 = i;
		}
		if(arr[id2] >= arr[id-2] && arr[id2] <= arr[id] && arr[id-1] >= arr[id2-1] && arr[id-1] <= arr[id2+1]) {
			cout << "yes" << endl;
			cout << "swap " << id-1+1 << ' ' << id2+1 << endl;
		} else {
			cout << "no" << endl;
		}
	} else {
		if(id == lg-1) {
			cout << "yes" << endl;	
			cout << "swap " << id-mx+1 << ' ' << id+1 << endl;
		}
		else if(arr[id] >= arr[id-mx-1] && arr[id] <= arr[id-mx+1] && arr[id-mx] >= arr[id-1] && arr[id-mx] <= arr[id+1]) {
			cout << "yes" << endl;
			if(mx > 1) cout << "reverse " << id-mx+1 << ' ' << id+1 << endl;
			else cout << "swap " << id-mx+1 << ' ' << id+1 << endl;
		} else {
			cout << "no" << endl;
		}
	}
	
	//cout <<  << endl;
	//return 0;
}
//std::string str;
//str = std::to_string(int i);
//bitset<3> s(N);
//int ans = (char)grid - '0';