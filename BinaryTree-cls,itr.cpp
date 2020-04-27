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
		
	}

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
