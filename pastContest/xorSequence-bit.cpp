#include <bits/stdc++.h>
//#define _GLIBCXX_DEBUG
//#define int int64_t
//#define double long double
//#define rep(i, N) for(int i=0; i<N; i++)
//#define repr(i, N) for(int i=N-1; i>=0; --i)
//#define all(v) v.begin(),v.end() 
using namespace std;
//using pr = pair<int, int>;
//using tup  = tuple<int, int, int>;
//using vec  = vector<int>;
//using vvec = vector<vec>;

//プロトタイプ宣言

//グローバル変数
//const int INF = ;
//const int MAX_N = ;
//const int MAX_M = ;
//vvec dp(MAX_N, vec(MAX_M));

//関数：
long a(long x) {
	//base case.
	if(x == 0) return 0;

	long ans;
	ans = x ^ a(x-1);
	return ans;
}

long reva(long x) {
	long r = x % 8;
	long d = x / 8;

	long ans;
	if(r == 0) ans = 0 + d*8;
	else if(r == 1 || r == 5) ans = 1;
	else if(r == 2) ans = 3 + d*8;
	else if(r == 3 || r == 7) ans = 0;
	else if(r == 4) ans = 4 + d*8;
	else ans = 7 + d*8;

	return ans; 
}

long g(long x) {
	long ans = 0;
	for(int i=0; i<=x; i++) ans = ans ^ reva(i);
	return ans;
}



long g(long x) {
	long r = x % 8;
	long d = x / 8;
	
	long ans;
	if(r == 0 || r == 1) ans = r + d*8;
	else if(r == 2 || r == 3) ans = 2;
	else if(r == 4 || r == 5) ans = r+2 + d*8;
	else ans = 0;
	
	return ans; 
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//long l, long r;
	//A[0] = 0;
	//A[x] = A[x-1] ^ x;
	long ans;
	ans = g(r) ^ g(l-1);
	
	//cout << << endl;
	return ans;
}
A[x] = 1 ^ 2 ^ 3 ^ ... ^ x. 
A[L] ^ A[L+1] ^ A[L+2] ^ ... ^ A[R]
 = A[1] ^ A[2] ^ ... A[L-1] ^ (A[L] ^ A[L+1] ^ ... ^ A[R]) ^ A[1] ^ A[2] ^ ... ^ A[L-1],
because a ^ b = b ^ a, a ^ a = 0, and 0 ^ a = a. 

construct a function G(X) = A[1] ^ A[2] ^ ... ^ A[X]. 
the answer is G(R) ^ G(L-1). search the patern for G(X).

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
