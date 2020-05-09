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
struct Node {
	int index;
	int depth;
	struct Node *left;
	struct Node *right;
};

//inOrder Traversal
void inOrder(Node *root) {
	if(root == NULL) return;
	inOrder(root->left);
	cout << root->data;
	inOrder(root->right);
}

vvec swapNodes(vvec indexes, vec queries) {
	/*
	 * Write your code here.
	 */
	int lgq = queries.size();
	int lgi = indexes.size();
	
	for(int i=0; i<lgq; i++) {
		
	)
	
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T; cin >> T;
	while(T > 0) {
	
	int n; cin >> n;
	
	int id = 1;
	int dp = 1;
	Node* root = (Node*)malloc(sizeof(Node));
		root->index = id;
		root->depth = dp;
		root->right = NULL;
		root->left = NULL;
	
	vec tp(2);
	id++;
	while(ct < n) {
		rep(i, 2) cin >> tp[i];
		/* How to make binaryTree? */
		
	}
	
	//cout << << endl;
	
	T--; } 
	
	return 0;
}

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
