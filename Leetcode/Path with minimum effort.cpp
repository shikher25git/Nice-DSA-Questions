class Solution {

    private:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool valid(int x, int y, int r, int c){
        return (x>=0 and y>=0 and x<r and y<c);
    }
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& vis, int& mid, int r, int c, int& row, int& col){
        vis[r][c] = true;
        for(auto [x, y]: dir){
            if(valid(x+r, y+c, row, col) and !vis[x+r][y+c]){
                if(abs(h[x+r][y+c] - h[r][c]) <= mid){
                    dfs(h, vis, mid, r+x, c+y, row, col);
                }
            }
        }
    }
    
    public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        int beg = 0, end = 1e6+5;
        int ans = -1;
        while(beg <= end){
            int mid = beg + (end-beg)/2;
            vector<vector<bool>> vis(row, vector<bool>(col, false));
            dfs(heights, vis, mid, 0, 0, row, col);
            if(vis[row-1][col-1]){
                ans = mid;
                end = mid-1;
            }
            else{
                beg = mid+1;
            }
        }
        return ans;
    }
};