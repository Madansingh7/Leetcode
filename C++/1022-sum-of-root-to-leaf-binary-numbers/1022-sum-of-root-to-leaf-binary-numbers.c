/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode* BST;

int sum(BST root, int digit){
    if(root==NULL){
        return 0;
    }
    // taking each node value mulplying with base 2 to get a complete binary value
    digit = (digit *2) +root->val;
    
    if(root->left==NULL && root->right==NULL){
        return digit;
    }

    return sum(root->left,digit) + sum(root->right,digit);
}

int sumRootToLeaf(BST root) {
   return sum(root, 0);
}