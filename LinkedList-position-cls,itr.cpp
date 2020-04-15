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
class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode *next;
	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

class SinglyLinkedList {
public:
	SinglyLinkedListNode *head;
	SinglyLinkedListNode *tail;
	SinglyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}
	
	void insert_node(int node_data) {
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);
		if(!this->head) {
			this->head = node;
		} else {
			this->tail->next = node;
		}
		this->tail = node;
	}
};

//get Node Value
int getNode(SinglyLinkedListNode* head, int positionFromTail) {
	SinglyLinkedListNode* nowNode = head;
	SinglyLinkedListNode* rearNode = head;
	while(positionFromTail > 0) {
		nowNode = nowNode->next;
		positionFromTail--;
	}
	
	while(nowNode->next != NULL) {
		nowNode = nowNode->next;
		rearNode = rearNode->next;
	}
	
	return rearNode->data;
}

//delete Duplicate-Value Nodes
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
	if(head == NULL || head->next == NULL) return head;
	
	SinglyLinkedListNode* nextNode = head->next;
	while(nextNode->data == head->data) {
		if(nextNode->next != NULL) nextNode = nextNode->next;
		else {
			nextNode = NULL;
			break;
		}
	}
	
	head->next = removeDuplicates(nextNode);
	return head;
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	/* number of tryal: begin
	int T; cin >> T;
	while(T > 0) { */
	
	SinglyLinkedList* llist = new SinglyLinkedList();
	int n; cin >> n;
	rep(i, n) {
		int item; cin >> item;
		
		SinglyLinkedListNode* llist_head = insertNodeAtTail(llist->head, item);  
		llist->head = llist_head;
	}
	
	//cout << << endl;
	
	/* number of tryal: end
	T--; } */
	
	return 0;
}
