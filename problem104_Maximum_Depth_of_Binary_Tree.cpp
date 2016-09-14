/**提交了3次才AC   Runtime：6ms
**第一次Time Limit Exceeded， 第二次Wrong Answer
**这道题不难，用递归很容易做出来（之前在数据结构的书上看到过相似的内容哈哈哈）
**/
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
    int maxDepth(TreeNode* root) {
        if (!root)
	       	return 0;
	    else
	    {
	        int len_left = 1 + maxDepth(root->left);
	        int len_right = 1+ maxDepth(root->right);
		    return (len_left > len_right)?len_left:len_right;
	    }
    }
};