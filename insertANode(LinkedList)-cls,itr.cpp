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

//insert A Node At the Tail of the Linked List
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
	SinglyLinkedListNode* tlNode = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
	tlNode->data = data;
	tlNode->next = NULL;
	
	if(head == NULL) {
		head = tlNode;
	} else {
		SinglyLinkedListNode* nowNode = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
		nowNode = head;
		while((nowNode->next) != NULL) {
			nowNode = (nowNode->next);
		}
	
		nowNode->next = tlNode;
	}
	return head;
}

//insert A Node At the Head of the Linked List
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
	SinglyLinkedListNode* hdNode = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
	hdNode->data = data;
	hdNode->next = NULL;

	if(llist == NULL){
		llist = hdNode;
	} else {
		hdNode->next = llist;
		llist = hdNode;
	}
	
	return llist;
}

//insert A Node At Position
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
	 SinglyLinkedListNode* newNode = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
	newNode->data = data;
	
	if (head == NULL) {
		newNode->next = NULL;
		return newNode;
	}
	
	if (position == 0) {
		newNode->next = head;
		return newNode;
	}
	
	SinglyLinkedListNode* nowNode = head;
	while(position-1 > 0) {
		nowNode = nowNode->next;
		position--;
	}
	newNode->next = nowNode->next;
	nowNode->next = newNode;
	
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
