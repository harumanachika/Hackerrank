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

	//string s;
	int lg = s.size();
	int i = 0;
	while(i<lg-1) {
		if(s[i] == s[i+1]) {
			s.erase(i,2); //i文字目以降を2文字分だけ削除。
			lg -= 2;
			if(i != 0) i--;
		} else {
			i++;
		}
	}
	if(s == "") s = "Empty String";
	
	//cout << << endl;
	return s;
}

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
