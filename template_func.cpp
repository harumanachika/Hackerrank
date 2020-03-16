#include <bits/stdc++.h>
using namespace std;


/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	/* number of tryal: begin
	int T; cin >> T;
	while(T > 0) { */
	
	
	//cout << << endl;
	
	/* number of tryal: end
	T--; } */
	
	return 0;
}

/* 添字の範囲をチェック */
//int lgr, lgc;
bool check(int i, int j) {
	bool frag = false;
	if(i>=0 && i<lgr && j>=0 && j<lgc) frag = true;
	return frag;
}

/* 二進表記の1の数をカウント */
int count(int bits) {
	if(bits == 0) return 0;
	return count(bits >> 1) + (bits & 1);
}

/* 十進表記から二進表記に変換 */
int binary(int n) {
	int ans;
	if(n == 1) {
		ans = 1;
		return ans;
	}
	
	if(n%2 == 0) ans = 10*binary(n/2);
	else ans = 10*binary(n/2) + 1;
	return ans;
}

/* xのn乗をmodで割った余りを返す -- Russian Peasant Exponential
（素数pに対して x^(p-1) = 1 (mod p) が成り立つ）*/
/* (../d)%mod = (..*(mod_pow(d, mod-2)%mod))%mod */
//const int mod = ;
int64_t mod_pow(int64_t a, int64_t b) {
	int64_t ans = 1;
	
	while(b != 0) {
		if(b & 1) ans = ans*a % mod;
		a = a*a % mod;
		b = b >> 1;
	}
	
	return ans;
}

/* nの階乗をmodで割った余りを返す
（素数pに対して x^(p-1) = 1 (mod p) が成り立つ）*/
//const int mod = ;
int64_t mod_fact(int64_t n) {
	int64_t ans = 1;
	
	while(n >= 2) {
		ans = ans*(n%mod) % mod;
		n -= 1;
	}
	
	return ans;
}

/* xのn乗をmodで割った余りを返す（複素数版） -- Russian Peasant Exponential
（素数pに対して x^(p-1) = 1 (mod p) が成り立つ）*/
//const int mod = ;
vector<int64_t> mod_pow(int64_t a, int64_t b, int64_t k) {
	vector<int64_t> ans(2);
	if(k == 0) {
		ans[0] = 1; ans[1] = 0;
		return ans;
	}

	ans[0] = 1; ans[1] = 0;
	while(k > 0) { // <- error.
		if(k & 1) {
			int tp;
			tp = (((a%mod)*(ans[0]%mod))%mod - ((b%mod)*(ans[1]%mod))%mod + mod) % mod;
			ans[1] = (((a%mod)*(ans[1]%mod))%mod + ((b%mod)*(ans[0]%mod))%mod) % mod;
			ans[0] = tp;
		}
		int tp;
		tp = (((a%mod)*(a%mod))%mod - ((b%mod)*(b%mod))%mod + mod) % mod;
		b = (2*(a%mod)*(b%mod)) % mod;
		a = tp;
		k = k >> 1;
	}
	
	return ans;
}

/* Fibonacci数列の計算（メモ化による高速化） */
//const int MAX_N = ;
vector<int64_t> fib_memo(MAX_N, 0);
int64_t fib(int64_t n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	
	if(fib_memo[n] != 0) return fib_memo[n];
	else return fib_memo[n] = fib(n-1)+fib(n-2);
}

/* 組合せの計算（メモ化による高速化） */
//const int MAX_N = ;
//const int mod = ;
vector<vector<int>> c(MAX_N, vector<int>(MAX_N, 0));
int conbi(int m, int r) {
	if(m <= 0 || r < 0 || m < r) return 0;
	if(m == 1 || r == 0) return 1; // r=0 -> ?
	if(r == 1) return m;
	
	if(c[m][r] != 0) return c[m][r];
	else return c[m][r] = (conbi(m-1, r) + conbi(m-1, r-1)) % mod;
}

/* ユークリッドの互除法 */
int gcd(int x, int y) {
	if(x > y) swap(x, y);
 
	int ans;
	while(x > 0) {
		ans = x;
		x = y % x;
		y = ans;
	}
	return ans;
}

/* 素数判定関数 */
bool has_divisor(int, int);

bool is_prime(int n) {
	if (n == 1) return false;
	else if (n == 2) return true;
	else {
		return !has_divisor(n, 2);
	}
}

bool has_divisor(int n, int i) {
	//base case 1:
	if (i == n) return false;
	//base case 2:
	if (n % i == 0) return true;
	
	return has_divisor(n, i+1);
}

/* エラトステネスの篩 */
const int MAX_P = 1000000;
queue<int> prime; vector<int> v(MAX_P, 0);
void getprime() {
	//memset(v, 0, sizeof(v));
	for(int i=2; i<MAX_P; i++) {
		if(v[i] == false) {
			prime.push(i);
			for(int j=2; i*j<MAX_P; j++) v[i*j] = 1;
		}
	}
}

/* 配列の中位数を返す */
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

/* クイック・ソート（返し値：互換数） */
int quicksort(vector<int> &arr, int left, int right) {
	int i, j, p;
	int ans = 0;
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
