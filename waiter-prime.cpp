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

/* エラトステネスのふるい */
const int MAX_P = 10000;
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

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	/* number of tryal: begin
	int T; cin >> T;
	while(T > 0) { */
	
	getprime()
	int n, q; cin >> n >> q;
	vector<stack<int>> 
	
	//cout << << endl;
	
	/* number of tryal: end
	T--; } */
	
	return 0;
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

map<int,int>::iterator itr, itr1, itr2;
for(itr = mp.begin(); itr != mp.end(); itr++) {
	ans += itr->second * (itr->second-1);
}

distance(itr1, itr2);
advance(itr, k);
next(itr, k); //=itr + k;
*itr;
itr = mp.begin(); mp.erase(itr);
itr = prev(mp.end());
*/
