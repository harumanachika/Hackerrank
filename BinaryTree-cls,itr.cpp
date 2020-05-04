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
typedef tuple<int,int> tup;

//グローバル変数 関数：
//vvec dp(MAX_N, vec(MAX_M));
class Node {
	public:
		int data;
		Node *left;
		Node *right;
		Node(int d) {
			data = d;
			left = NULL;
			right = NULL;
		}
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

	//preOrder Traversal
	void preOrder(Node *root) {
		if(root == NULL) return;
		cout << root->data << " ";
		preOrder(root->left); 
		preOrder(root->right);
	}

	//postOrder Traversal
	void postOrder(Node *root) {
		if(root == NULL) return;
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << " ";
	}

	//inOrder Traversal
	void inOrder(Node *root) {
		if(root == NULL) return;
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}

	//height of a BinaryTree
	int height(Node* root) {
		if(root != NULL) {
			int r = height(root->right);
			int l = height(root->left);
			return 1 + max(r, l);
		} else {
			return -1;
	}}
	
	//print the Top View of a BinaryTree
	typedef pair<int,int> pr;
	map<int,pr> mp;
	map<int,pr>::iterator itr; 
	
	void storeNode(Node *root, int i, int h) {
		if(root == NULL) return;
		
		itr = mp.find(i);
		if(itr == mp.end()) mp[i] = make_pair(h, root->data);
		else {
			if(itr->second.first > h) mp[i] = make_pair(h, root->data);
		}
		
		if(root->left != NULL) storeNode(root->left, i-1, h+1);
		if(root->right != NULL) storeNode(root->right, i+1, h+1);
	}
	
	void printmap() {
		for(itr=mp.begin(); itr!=mp.end(); ++itr)
			cout << itr->second.second << " ";
	}
	
	void topView(Node *root) {
		storeNode(root, 0, 0);
		printmap();
		return;
	}
	
	//level Order Traversal
	queue<Node*> q;	
	void levelOrder(Node* root) {
		if(root == NULL) return;
		q.push(root);
		
		while(!q.empty()) {
			Node* nowNode = q.front(); q.pop();
			cout << nowNode->data << " ";
			
			if(nowNode->left != NULL) q.push(nowNode->left);
			if(nowNode->right != NULL) q.push(nowNode->right);
	}}
	
	//insert Node to the BinarySearchTree
	Node* insert(Node* root, int data) {
		if(root == NULL) {
			Node* nowNode = (Node*)malloc(sizeof(Node));
			nowNode->data = data;
			nowNode->right = NULL;
			nowNode->left = NULL;
			root = nowNode;
		} else if(root->data < data) {
			root->rignt = insert(root->right, data);
		} else {
			root->left = insert(root->left, data);
		}
		
		return root;
	}
	
	//Hoffman Decoding
	void decode_huff(node* root, string s) {
		node* nowNode = root;
		
		for(i=0; i<s.size(); i++) {
			if(s[i] == '1') {
				if(nowNode->right != NULL) nowNode = nowNode->right;
				else {
					nowNode = root;
					continue;
				}
				
				if(nowNode->right == NULL && nowNode->left == NULL) {
					cout << nowNode->data;
					nowNode = root;
					continue;
				} else continue;
			} else {
				if(nowNode->left != NULL) nowNode = nowNode->left;
				else {
					nowNode = root;
					continue;
				}
				
				if(nowNode->right == NULL && nowNode->left == NULL) {
					cout << nowNode->data;
					nowNode = root;
					continue;
				} else continue;
	}}}
	
	//lowest Common Ancestor of a BinarySearchTree
	Node *lca(Node *root, int v1, int v2) {
		if(root->data > v1 && root->data > v2) {
			return lca(root->left, v1, v2);
		} else if(root->data < v1 && root->data < v2) {
			return lca(root->right, v1, v2);
		} else {
			return root;
	}}
	
	
}; //End of Solution

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	/* number of tryal: begin
	int T; cin >> T;
	while(T > 0) { */
	
	Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.preOrder(root);
    return 0;
	
	/* number of tryal: end
	T--; } */
	
	return 0;
}

/*	struct data {
	char *name;
	int age;
	int height;
	double weight;
};*/

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
