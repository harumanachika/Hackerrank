#include <bits/stdc++.h>
using namespace std;

//プロトタイプ宣言

//グローバル変数
//const int INF = ;
//const int MAX_N = ;
//const int MAX_M = ;
//vvec dp(MAX_N, vec(MAX_M));

//関数：
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

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//int a, int b, int c;
	string ans;
	
	if(max(a, b)>c && c%gcd(a, b)==0) ans = "YES";
	else ans = "NO";
	
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
