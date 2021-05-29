// https://leetcode.com/contest/biweekly-contest-53/problems/minimum-xor-sum-of-two-arrays/
// https://www.youtube.com/watch?v=685x-rzOIlY

class Solution {
public:
    int n;
    int dp[15][30000];
    int rec(int mask, vector<int>&nums1, vector<int>&nums2, int i){
        // cout<<mask<<'\n';
        if(i == n){
            return 0;
        }
        if(dp[i][mask] != -1){
            return dp[i][mask];
        }
        int ans = INT_MAX;
        for(int k=0;k<n;k++){
            if(mask&(1<<k)){
                ans = min(ans, ((nums1[i] ^ nums2[k]) + rec(mask^(1<<k), nums1, nums2, i+1)));
            }
        }
        // cout<<i<<" "<<mask<<" "<<ans<<'\n';
        return dp[i][mask] = ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        int mask = (1<<n) - 1;
        memset(dp, -1, sizeof(dp));
        rec(mask, nums1, nums2, 0);
        return dp[0][mask];
    }
};