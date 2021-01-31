class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int ans = -1;
        for(int i=0;i<heights.size();i++){
            if(s.empty() or heights[i] >= heights[s.top()]){
                s.push(i);
            }
            else{
                while(!s.empty() and heights[i] < heights[s.top()]){
                    int tp = s.top();
                    s.pop();
                    int lef = (s.empty()) ? -1 : s.top();
                    ans = max(ans, heights[tp]*(i - lef - 1));
                    // cout<<ans<<' '<<heights[tp]<<" "<<i<<" "<<lef<<"\n";
                }
                s.push(i);
            }
        }
        while(!s.empty()){
            int tp = s.top();
            s.pop();
            int lef = (s.empty()) ? -1 : s.top();
            ans = max(ans, (int)(heights[tp]*(heights.size() - lef - 1)));
            // cout<<ans<<'\n';
        }
        return ans;
    }
};