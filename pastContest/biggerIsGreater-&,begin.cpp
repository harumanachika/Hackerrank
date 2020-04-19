#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define int int64_t
#define double long double
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string w; cin >> w;

	//string w
	int lg = w.size();
	const int INF = 100100105;
	vector<pair<int,char>> alf(lg);
	bool frag = false;
	for(int i=0; i<lg; i++) {
		alf[i].first = w[i] - 'a' + 1;
		alf[i].second = w[i];
	}
	
	for(int i=lg-1; i>=1; --i) {
		if(alf[i].first > alf[i-1].first) {
			int mn = INF;
			int ct;
			for(int j=lg-1; j>=i; --j) {
				int nb =  alf[j].first - alf [i-1].first;
				if(mn > nb && nb > 0) {
					mn = nb;
					ct = j;
				}
			}
			swap(alf[i-1], alf[ct]);
			sort(alf.begin()+i,alf.end());
			//reverse(alf.begin()+i,alf.end());
			frag = true;
			break;
		}
	}

	string ans = w;
	string &ref = ans;
	for(int i=0; i<lg; i++) {
		ref[i] = alf[i].second;
	}
	if(!frag) ans = "no answer";
	//cout << ans << endl;
	return ans;
}
//std::string str;
//str = std::to_string(int i);
//bitset<3> s(N);
//int ans = (char)grid - '0';