class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        if(root->left == NULL and root->right == NULL)
            return;
        if(root->left!=NULL){
            flatten(root->left);
        }
        if(root->right!=NULL){
            flatten(root->right);
        }
        if(root->left==NULL) return;
        TreeNode *tmp = root;
        while(tmp->left->left) tmp = tmp->left;
        TreeNode *now = tmp->left;
        while(now->right != NULL) now=now->right;
        // TreeNode *shift = tmp->left;
        now->right = tmp->right;
        tmp->right = tmp->left;
        tmp->left = NULL;
    }
};