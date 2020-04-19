#include <bits/stdc++.h>
using namespace std;

//グローバル変数 関数：

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i]; 
	
	//vector<int> a;
	int lg = a.size();
	set<int> sums; //insert, eraser, find, count, empty, 
	vector<int> ans;
	
	int cr = a[0];
	sums.insert(cr);
	for(int i=1; i<lg; i++) {
		cr += a[i];
		sums.insert(cr);
	}
	
	for(auto it=sums.begin(); it!=sums.end(); ++it) { //*iterator = sums[], ++it!!
		if(cr%(*it) == 0) {
			bool frag = true;
			for(int k=1; k <= cr/(*it); k++) {
				auto tt = sums.find((*it) * k);
				if(tt == sums.end()) {
					frag = false;
					break;
				}
			}
			if(frag) ans.push_back(*it);
		}
	}
	
	//for(int i=0; i<ans.size(); i++) cout << ans[i] << ' ';
	//cout << endl;
	return ans;
}
