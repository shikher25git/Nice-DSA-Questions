class Solution {

    private:
    TreeNode* lca( TreeNode* root, TreeNode* p, TreeNode* q ) {
        if ( !root || root == p || root == q ) return root;
        TreeNode *left = lca( root->left, p, q );
        TreeNode *right = lca (root->right, p, q );

        return !left? right: !right? left: root;
    }
    public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return root;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int d=0;
        TreeNode *lm = root, *rm = root;
        while(!q.empty()){
            pair<TreeNode*, int> fr = q.front();
            q.pop();
            if(fr.second > d){
                lm = rm = fr.first;
                d = fr.second;
            }
            else rm = fr.first;
            if(fr.first->left != NULL) q.push({fr.first->left, fr.second+1});
            if(fr.first->right != NULL) q.push({fr.first->right, fr.second+1});
        }
        cout<<lm->val<<" "<<rm->val;
        return lca(root, lm, rm);
    }
};