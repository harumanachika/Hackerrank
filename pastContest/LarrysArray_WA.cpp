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
	
	vector<int> df(lg, 0);
	int pls = 0;
	int mns = 0;
	for(int i=0; i<lg; i++) {
		int df[i] = A[i] - (i+1);
		if(df > 0) pls += df[i];
		else if(df < 0) mns += df[i];
	}
	
	string ans;
	int tl = pls+mns;
	if(tl != 0) ans = "NO";
	
	for(int i=0; i<lg; i++) {
	
	}
	
	
	//cout <<  << endl;
	return ans;
}


Explaination:

One Fact: A rotation does not change the parity of the number of inversions.
That is because, the number of inversions can be decomposed into these three parts:
1. The inversions among the three numbers involved in the rotation.
2. The inversions among the numbers not involved in the rotation.
3. The inversions between the three numbers and the other numbers.
For part 2 and 3, the number of inversions are unchanged. For part 1, the number of inversions are changed by 2 % 2 = 0. (Since 1 number is moved to the front of other 2 numbers, actually, if you move 1 number to the front of n numbers, the number of inversions will be changed by n % 2).
Two Directions:
1. If the array is sortable, then the initial number of inversions is even.
2. If the initial number of inversions is even, then the array is sortable.
Direction 1 is obvious, since the final position has a inversion with number 0, and rotations does not change the parity of inversions. So in the beginning, the number of inversions must be even.
Direction 2 can be proved by construction. We can do the following to sort the array like bubble sort. We first do rotations of position 1 to n to put 1 in position 1, then do rotations of position 2 to n to put 2 in position 2. By doing this, we can do rotations to put n-3 in position n-3. Then there are 2 numebrs left, and we have no more numbers to do rotations. So are the last 2 numbers sorted already? The answer is yes, since we have the assumption that the number of initial inversions is even.
So far, we have proved the correctness of this claim.
