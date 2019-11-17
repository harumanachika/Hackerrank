#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
//#define int int64_t
//#define double long double
using namespace std;

/* クイック・ソート（返し値：互換数） */
int64_t quicksort(vector<int> &arr, int left, int right) {
	int i, j, p;
	//int64_t ans = 0;
	i = left; j = right;
	p = (arr[i]+arr[j]) / 2;
	while(i < j) {
		while(arr[i] < p) i++;
		while(arr[j] > p) j--;
		if (i < j) {
			swap(arr[i++], arr[j--]);
			ans += abs(i-j);
		}
		if(i == j) {
			if(arr[i] < p) i++;
			else if(arr[j] > p) j--;
		}
		if (i >= left+2) ans += quicksort(arr, left, i-1);
		if (j <= right-2) ans += quicksort(arr, j+1, right);
	}
	return ans;
}

/* マージ・ソート（返し値：インサート・ソート対応互換数） */
int64_t ans = 0;
int64_t mergesort(vector<int> &arr, int left, int right) {
	//base case:
	if(right-left <= 1) return 0;

	int mid = left + (right-left)/2;
	vector<int> v;
	
	mergesort(arr, left, mid);
	mergesort(arr, mid, right);
	
	for(int i=left; i<=mid; i++) v.push_back(arr[i]);
	for(int i=right; i>mid; --i) v.push_back(arr[i]);
		
	int itr_left = 0;
	int itr_right = v.size();
	for(int k=left; k<=right; k++) {
		if(v[itr_left] < v[itr_right]) arr[k] = v[itr_left++];
		else {
			arr[k] = v[itr_right--];
			ans += mid - left - itr_left;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	vector<int> arr(N);
	for(int i=0; i<N; i++) cin >> arr[i];
	
	//vector<int> arr;
	//-> int64_t insertionSort();
	int lg = arr.size();
	//int64_t ans = 0;

	mergesort(arr, 0, lg-1);

	//cout << ans << endl;
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

/*map<int,int> mp;
for(auto p : mp) {
	ct += p.second*(p.second-1); }

map<int,int>::iterator itr;
for(itr = mp.begin(); itr != mp.end(); itr++) {
	ans += itr->second * (itr->second-1);
}*/
