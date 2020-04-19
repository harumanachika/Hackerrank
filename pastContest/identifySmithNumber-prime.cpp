#include <bits/stdc++.h>
//#define int int64_t
//#define double long double
#define rep(i, N) for(int i=0; i<N; i++)
#define rep2(i, j, M) for(int i=j; i<M; i++)
#define repr(i, N) for(int i=N-1; i>=0; --i)
#define all(v) v.begin(),v.end() 
using namespace std;
using pr = pair<int, int>;
using tup  = tuple<int, int, int>;
using vec  = vector<int>;
using vvec = vector<vec>;

//グローバル変数 関数：
/* MAX_P以下の素数を配列primeにスタック */
const int MAX_P = 1000000;
vector<int> prime(500000); vector<int> v(MAX_P, 0);
int top = 0;
void getprime() {
	//memset(v, 0, sizeof(v));
	for(int i=2; i<MAX_P; i++) {
		if(v[i] == 0) {
			prime[top++] = i;
			for(int j=2; i*j<MAX_P; j++) v[i*j] = 1;
		}
	}
}

int sumDigit(int x) {
	int sum = 0;
	while(x > 0) {
		sum += x%10;
		x /= 10;
	}
	return sum;
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	getprime();
	
	int n; cin >> n;
	
	int sumpr = 0, sumn = 0, og = n;
	sumn = sumDigit(n);
	rep(i, top) {
		while(n%prime[i] == 0) {
			n /= prime[i];
			sumpr += sumDigit(prime[i]);
		}
	}
	if(n > 1) sumpr += sumDigit(prime[n]);
	
	int ans = 0;
	if(n < og && sumpr == sumn) ans = 1; 
	cout << ans << endl;
	return 0;
}
