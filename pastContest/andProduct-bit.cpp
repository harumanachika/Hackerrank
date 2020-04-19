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
/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//long a, long b;
	
	long ans = a;
	//for(int i=a+1; i<=b; i++) ans = ans&(long)i;
	ans = a & ~((1 << (int)log2(a^b))-1);

	//cout << << endl;
	return ans;
}

Let s say a and b are:

a = 26 = 011010
b = 40 = 101000

The leftmost 1 bit of b is to the left of the leftmost 1 bit of a. So, there is a power of 2 that lies between a and b - namely, 32 (100000) which when ANDed with anything before it will result in 0. This will make the final result 0.
However, if a and b were

a = 42 = 101010
b = 57 = 111001

their leftmost 1 bits are aligned (are in the same bit position). If we temporarily ignore this 1 bit in both, we have:

a = 01010
b = 11001

Again there exists a power of 2, namely 16 (10000) that lies between these two sub-values that will eventually zero out the AND product in these bits.

The ANDproduct of the range [101010, 111001] is 100000. In other words, ANDing the range [101010, 111001] is equivalent to preserving the ALL leftmost ALIGNED bits (both 1s and 0s) and zeroing out all bits starting with the first non-aligned bit.

To zero-out all bits starting with the first non-aligned bit, we need to AND these bits with 0s.

To do so, we first a XOR b to get 10011. These bits will have to be zeroed-out. Next, we get the smallest power of 2 larger than this XOR value which happens to be 100000. Subtracting 1, we get 11111, and then finally inverting the bits, we get 11111111111111111111111111100000 (32-bit).

Now, this value ANDed with either A or B will produce the final AND product.

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
