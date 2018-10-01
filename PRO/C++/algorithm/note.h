
//not a actual header, just my notebook

static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q){

        if(p==NULL && q==NULL)
            return true;

        if(p==NULL || q==NULL)
            return false;

        if(p->val==q->val)
            return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);

        else
            return false;

    }


};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL && q != NULL) return false;
        if(p != NULL && q == NULL) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};


class Solution {
public:

    bool flag = false;

    bool hasPathSum(TreeNode* root, int sum) {
        preorder(root, sum);
        return flag;
    }

    void preorder(TreeNode* root, int sum){
        if(root != NULL){
            int value = root -> val;
            if(sum == value && root ->left == NULL && root -> right == NULL){
                flag = true;
            }

            preorder(root->left, sum-value);
            preorder(root->right, sum-value);

        }
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
	int profit = 0;
	for (int i = 0; i < prices.size(); ++i) {
		if (prices[i] < buy) {
			buy = prices[i]; continue;
		}
		if (buy<INT_MAX&&prices[i] - buy>profit)
			profit = prices[i] - buy;
	}
	return profit;
    }
};
