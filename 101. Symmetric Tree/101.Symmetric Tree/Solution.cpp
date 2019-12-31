/*101. Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
NOTE: SOLUTION ONLY,NO MAIN INCLUDED TO BUILD BINARY TREE
*/
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
};

TreeNode* root = new TreeNode();

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		TreeNode* travelL = root;
		TreeNode* travelR = root;

		return symmTravel(travelL, travelR);

	}

	bool symmTravel(TreeNode* travelL, TreeNode* travelR) {
		if (travelL == NULL && travelR == NULL) {
			return true;
		}
		else if (travelL == NULL || travelR == NULL) {
			return false;
		}

		if (travelL->val == travelR->val) {
			return symmTravel(travelL->left, travelR->right) &&
				symmTravel(travelL->right, travelR->left);
		}
		else {
			return false;
		}

	}
};