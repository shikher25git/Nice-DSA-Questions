class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // for(auto i: wrdDict) wordDict.insert(i);
        vector<bool> dp(s.length()+1, false);
        dp[0]=true;
        for(int i=1;i<=s.length();i++) {
            for(int j=i;j>0;j--) {
                // cout<<j-1<<" "<<i<<" "<<s.substr(j-1,i-j+1)<<'\n';
                if(wordDict.find(wordDict.begin(), wordDict.end(), s.substr(j-1,i-j+1)) !=  wordDict.end()){
                    if(dp[j-1]==true) 
                        dp[i]=true;
                }
            }
        }
        return dp[s.length()];
    }
};