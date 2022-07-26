class Solution {
private:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
	// Whenever the current node is either equal to NULL, p, or q, Simply return
	// the node no need to go futher.
        if(root==NULL or root==p or root==q) return root;
        
        TreeNode *left = lca(root->left, p, q);
        TreeNode *right = lca(root->right, p, q);
        
	// The condition " if(left==NULL and right==NULL) return NULL; " is also covered in the following two conditions.
        if(left==NULL) return right;
        else if(right==NULL) return left;
	// When both left and right are non-NULL, that essentially means you have found the ancestor node.
	else return root; 
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
    }
};

/*
* NOTE: Watch Striver's video for better explanation.
*/
