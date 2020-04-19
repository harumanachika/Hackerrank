#include <bits/stdc++.h>
using namespace std;

//グローバル変数 関数：
const int INF = 10000000005;
const int MAX_N = 100005;
vector<long> fib_memo(MAX_N, 0);
long fib(long n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	
	if(fib_memo[n] != 0) return fib_memo[n];
	else return fib_memo[n] = fib(n-1)+fib(n-2);
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//long n;
	string ans = "IsNotFibo";

	long i = 1;
	while(fib(i) < n) i++;
	if(fib(i) == n) ans = "IsFibo"
	
	//cout << << endl;
	return ans;
}

/*	(n * m) % dvs = ((n%dvs) * (m%dvs)) % dvs
	int: (N+X+1)/X -> N/Xの切り上げ
*/

//std::string str;
//str = std::to_string(int i);
//bitset<3> s(N);
//int ans = (char)grid - '0';
//int id = lower_bound(all(arr), x) - arr.begin();
//cout << fixed << setprecision(10) << tld << endl;
//vector<int> sub(itr,itr+d); //イテレーターで部分数列(i=0...d)を指定
		
/*	struct data {
	char *name;
	int age;
	int height;
	double weight;
};*/

/*	string ans(lgd, '0');
	string &refer = ans;
	for(int i=0; i<lgd; i++) refer[i] = (char)vd[i] + '0';*/

/*	map<int,int> mp;
for(auto p : mp) {
	ct += p.second*(p.second-1); }

map<int,int>::iterator itr;
for(itr = mp.begin(); itr != mp.end(); itr++) {
	ans += itr->second * (itr->second-1);
}*/
