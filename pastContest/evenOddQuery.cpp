#include <bits/stdc++.h>
using namespace std;

//プロトタイプ宣言

//グローバル変数
//const int INF = ;
//const int MAX_N = 100005;
//vector<int> arr(MAX_N);
//int n;

//関数：
//const int64_t mod = 1;
int mod_pow(int a, int b) {
	int ans = 1;
	
	while(b != 0) {
		if(b & 1) ans = ans*a;
		a = a*a;
		b = b >> 1;
	}
	
	return ans;
}

int find(int x, int y) {
	if(x > y) return 1;
	
	int ans = mod_pow(arr[x], find(x+1, y));
	return ans;
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//vector<int> arr, vector<vector<int>> queries;
	int lgq = queries.size();
	int lga = arr.size();
	vector<string> ans(lgq);
	
	for(int i=0; i<lgq; i++) {
		int x = queries[i][0]-1;
		int y = queries[i][1]-1;
		if(arr[x+1]==0 && (x+1<lga && x!=y)) ans[i] = "Odd";
		else {
			if(arr[x]%2 == 1) ans[i] = "Odd";
			else ans[i] = "Even";
		}
	}
	
	//cout << << endl;
	return ans;
}
