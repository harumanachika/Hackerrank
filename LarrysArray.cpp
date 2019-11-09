#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define int int64_t
#define double long double
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//vector<int> A
	int lg = A.size();
	int ct = 0;
	for(int i=0; i<lg-1; i++)for(int j=i+1; j<lg; j++) {
		if(A[i] > A[j]) ct++;
	}
	
	string ans;
	if(ct%2 != 0) ans = "NO";
	else ans = "YES";
	//１回の置換で、A[i]>A[j]となるjが２つ発生。
	//jの個数は常に偶数。`
	
	//cout <<  << endl;
	return ans;
}
//std::string str;
//str = std::to_string(int i);
//bitset<3> s(N);
//int ans = (char)grid - '0';