class Solution {

    private:
    map<TreeNode*, int> mp;
    
    public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(mp.find(root) != mp.end()) return mp[root];
        int val1 = root->val;
        if(root->left){
            val1 += rob(root->left->left);
            val1 += rob(root->left->right);
        }
        if(root->right){
            val1 += rob(root->right->left);
            val1 += rob(root->right->right);
        }
        int val2 = rob(root->left)+rob(root->right);
        return mp[root] = max(val1, val2);
    }
};