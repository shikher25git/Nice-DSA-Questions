class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<pair<int, int>> q;
        for(int i=0;i<k-1;i++){
            int sec = 0;
            while(!q.empty() and q.back().first < nums[i]){
                sec += q.back().second + 1;
                q.pop_back();
            }
            q.push_back({nums[i], sec});
        }
        for(int i=k-1;i<nums.size();i++){
            int sec = 0;
            while(!q.empty() and q.back().first < nums[i]){
                sec += q.back().second + 1;
                q.pop_back();
            }
            q.push_back({nums[i], sec});
            ans.push_back(q.front().first);
            if(q.front().second == 0){
                q.pop_front();
            }
            else{
                --q.front().second;
            }
        }
        return ans;
    }
};