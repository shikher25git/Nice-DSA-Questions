class Solution {

    private:
    void inorder(TreeNode* node, vector<pair<int, TreeNode*>>&v){
        if(node->left!=NULL)
            inorder(node->left, v);
        v.push_back({node->val, node});
        if(node->right!=NULL)
            inorder(node->right, v);
    }
    public:
    void recoverTree(TreeNode* root) {
        vector<pair<int, TreeNode*>> v;
        inorder(root, v);
        int pos1=-1, pos2=-1;
        for(auto i: v) cout<<i.first<<" ";
        for(int i=0;i<v.size()-1;i++){
            if(v[i].first>v[i+1].first){
                if(pos1==-1){
                    pos1=i;
                }
                pos2=i+1;
            }
        }
        int tmp=v[pos1].second->val;
        v[pos1].second->val=v[pos2].second->val;
        v[pos2].second->val=tmp;
    }
};