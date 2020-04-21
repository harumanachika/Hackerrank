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

//Print
void printLinkedList(SinglyLinkedListNode* head) {
	SinglyLinkedListNode* nowNode = head;
	
	while(nowNode != NULL) {
		cout << nowNode->data << endl;
		nowNode = nowNode->next;
	}
}

//Reverse print
void reversePrint(SinglyLinkedListNode* head) {
	SinglyLinkedListNode* nowNode = head;
	
	if(nowNode == NULL) return;
	else {
		reversePrint(nowNode->next);
		cout << nowNode->data << endl;
	}
}

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
	
	if(head == NULL) {
		newNode->next = NULL;
		return newNode;
	}
	
	if(position == 0) {
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

//delete A Node At Position
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
	SinglyLinkedListNode* prvNode = NULL;
	SinglyLinkedListNode* nowNode = head;
	
	if(position == 0) {
		head = head->next;
		delete(nowNode);
		return head;
	}
	
	while(position > 0) {
		prvNode = nowNode;
		nowNode = nowNode->next;
		position--;
	}
	if(nowNode != NULL) {
		prvNode->next = nowNode->next;
		delete(nowNode);
	}
	
	return head;
}

//reverse
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
	SinglyLinkedListNode* nowNode = head;
	
	if(head->next != NULL) {
		nowNode = reverse(head->next);
		head->next->next = head;
		head->next = NULL;
	}
	
	return nowNode;
}

//compare
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
	if(head1->next == NULL && head2->next == NULL) {
		return 1;
	} else if(head1->next == NULL || head2->next == NULL) {
		return 0;
	}
	
	if(head1->data == head2->data) {
		return compare_lists(head1->next, head2->next);
	} else {
		return 0;
	}
}

//merge Two Sorted
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
	if(head1 == NULL) {
		return head2;
	} else if(head2 == NULL) {
		return head1;
	}
	
	if(head1->data < head2->data) {
		head1->next = mergeLists(head1->next, head2);
		return head1;
	} else {
		head2->next = mergeLists(head1, head2->next);
		return head2;
	}
}

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

//cycle Detection
bool has_cycle(SinglyLinkedListNode* head) {
	//Floyd’s Cycle detection algorithm
	if(head == NULL) return 0;
	
	SinglyLinkedListNode* fast = head;
	SinglyLinkedListNode* slow = head;
	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		
		if(fast == slow) return 1;
	}
	
	return 0;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
	SinglyLinkedListNode* nowNode1 = head1;
	SinglyLinkedListNode* nowNode2 = head2;
	
	while(nowNode1 != nowNode2) {
		if(nowNode1->next == NULL) nowNode1 = head2;
		else nowNode1 = nowNode1->next;
		
		if(nowNode2->next == NULL) nowNode2 = head1;
		else nowNode2 = nowNode2->next;
	}
	
	return nowNode2->data;
}

/* メイン・プログラム */
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	/* number of tryal: begin
	int T; cin >> T;
	while(T > 0) { */
	
	SinglyLinkedList* llist = new SinglyLinkedList();
	
	
	//cout << << endl;
	
	/* number of tryal: end
	T--; } */
	
	return 0;
}
