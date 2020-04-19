#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
//#define int int64_t
//#define double long double
using namespace std;

/* マージ・ソート：arrまたはvのどちらかにソート結果が格納される */
int64_t ans = 0;
void mergesort(vector<int> &arr, vector<int> &v, int left, int right) {
	if(right-left >= 2) {
		int mid = (left+right) / 2;
		mergesort(v, arr, left, mid);
		mergesort(v, arr, mid, right);
		int i = mid - 1;
		int j = right - 1;
		int k = right - 1;
		while(i >= left && j >= mid) {
			if(arr[j] >= arr[i]) v[k--] = arr[j--];
			else {
				ans += j - mid + 1; //インサーション・ソート対応互換数
				v[k--] = arr[i--];
			}
		}
		while(i >= left) v[k--] = arr[i--];
		while(j >= mid) v[k--] = arr[j--];
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];

	//vector<int> arr;
	int lg = arr.size();
	vector<int> v(arr);
	ans = 0;
	mergesort(arr, v, 0, lg);

	cout << ans << endl;
	//return ans;
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
