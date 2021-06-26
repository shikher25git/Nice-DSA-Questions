// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

// Anything remotely related to inversion counts, use merge sort

class Solution {
public:
    
    void merge(vector<pair<int, int>>&v, int n, int l, int r, int mid, vector<int>&ans){
        int a = l, b = mid + 1, ct = 0;
        vector<pair<int, int>> ta, tb;
        for(int i=l;i<=mid;i++)
            ta.push_back(v[i]);
        for(int i=mid+1;i<=r;i++)
            tb.push_back(v[i]);
        int ind = l;
        while(a <= mid and b <= r){
            if(ta[a-l].first > tb[b-mid-1].first){
                v[ind] = tb[b-mid-1];
                b++; ct++;
            }
            else{
                ans[ta[a-l].second] += ct;
                v[ind] = ta[a-l];
                a++;
            }
            ++ind;
        }
        while(b <= r){
            ++ct;
            v[ind++] = tb[b-mid-1];
            b++;
        }
        while(a <= mid){
            ans[ta[a-l].second] += ct;
            v[ind++] = ta[a-l];
            a++;
        }
    }
    
    void ms(vector<pair<int, int>>&v, int n, int l, int r, vector<int>&ans){
        if(l < r){
            int mid = l + (r-l)/2;
            ms(v, n, l, mid, ans);
            ms(v, n, mid+1, r, ans);
            merge(v, n, l, r, mid, ans);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<pair<int, int>> v(n);
        for(int i=0;i<n;i++)
            v[i] = {nums[i], i};
        ms(v, n, 0, n-1, ans);
        return ans;
    }
};