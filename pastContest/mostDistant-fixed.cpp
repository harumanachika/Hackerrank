#include <bits/stdc++.h>
using namespace std;

//グローバル変数 関数：
double dist(int x, int y) {
	//x, y > 0;
	double ans = sqrt((double)x*(double)x + (double)y*(double)y);
	return ans;
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//vector<vector<int>> coordinates;
	int lgr = coordinates.size();
	vector<int> mx(2, 0);
	vector<int> mn(2, 0);
	for(int i=0; i<lgr; i++) {
		for(int j=0; j<2; j++) {
			if(coordinates[i][j] != 0 && coordinates[i][j] > mx[j]) mx[j] = coordinates[i][j];
			if(coordinates[i][j] != 0 && coordinates[i][j] < mn[j]) mn[j] = coordinates[i][j];
		}
	}
	
	double ans = (double)mx[0] - (double)mn[0];
	double r = (double)mx[1] - (double)mn[1];
	if(ans < r) ans = r;
	int tp1 = max(abs(mx[0]), abs(mn[0]));
	int tp2 = max(abs(mx[1]), abs(mn[1]));
	r = dist(tp1, tp2);
	if(ans < r) ans = r;
	
	//cout << << endl;
	return ans;
	
	//-> fout << fixed << setprecision(12) << ..
}

/*	(n * m) % dvs = ((n%dvs) * (m%dvs)) % dvs
	int: (N+X+1)/X -> N/Xの切り上げ
*/
