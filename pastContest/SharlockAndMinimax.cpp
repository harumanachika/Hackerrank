#include <bits/stdc++.h>
#define int int64_t
#define double long double
#define rep(i, N) for(int i=0; i<N; i++)
#define rep2(i, j, M) for(int i=j; i<M; i++)
#define repr(i, N) for(int i=N-1; i>=0; --i)
#define all(v) v.begin(),v.end() 
using namespace std;
using vec  = vector<int>;
using vvec = vector<vec>;
typedef pair<int,int> pr;
typedef tuple<int,int> tup;

//グローバル変数 関数：
//vvec dp(MAX_N, vec(MAX_M));
int const INF = 1000000005;
int div2(int a) {
	if(a%2 == 0) return a/2;
	else return (a+1)/2;
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	/* number of tryal: begin
	int T; cin >> T;
	while(T > 0) { */
	
	int n; cin >> n;
	vec arr(n); rep(i, n) cin >> arr[i];
	int p, q; cin >> p >> q;
	
	sort(all(arr));
	
	pr ans; ans.first = -1;
	if(arr[0] >= q) {
		ans.first = arr[0]-p;
		ans.second = p;
	} else if(arr[n-1] <= p) {
		ans.first = q-arr[n-1];
		ans.second = q;
	} else {
		/* The maximum (M - arr[i]) occurs on the mid values between adjacent numbers in the sorted array. */
		if(arr[0] > p && ans.first < arr[0]-p) {
			ans.first = arr[0]-p;
			ans.second = p;
		}
		
		if(arr[n-1] < q && ans.first < q-arr[n-1]) {
			ans.first = q-arr[n-1];
			ans.second = q;
		}
		
		rep(i, n-1) {
			int cr = (arr[i]+arr[i+1])/2;
			if(cr <= q && cr >= p && ans.first < cr-arr[i]) {
				ans.first = cr-arr[i];
				ans.second = cr;
			} else if(cr > q && ans.first < q-arr[i]) {
				ans.first = q-arr[i];
				ans.second = q;
			} else if(cr < p && ans.first < arr[i]-p) {
				ans.first = arr[i]-p;
				ans.second = p;
			}
		}
	}
	
	cout << ans.second << endl;
	
	/* number of tryal: end
	T--; } */
	
	return 0;
}
