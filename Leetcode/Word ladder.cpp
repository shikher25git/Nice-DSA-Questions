class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<string> q, t;
        if(s.find(endWord) == s.end()){
            return 0;
        }
        q.push(beginWord);
        t.push(endWord);
        int ans = 1, d = 0;
        while(!q.empty() and !t.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                string fr = q.front();
                q.pop();
                if(fr == endWord) return ans;
                s.erase(fr);
                for(int j=0;j<fr.size();j++){
                    char c = fr[j];
                    for(int k=0;k<26;k++){
                        fr[j] = 'a' + k;
                        if(s.find(fr) != s.end()){
                            q.push(fr);
                            s.erase(fr);
                        }
                    }
                    fr[j] = c;
                }
            }
            ++ans;
        }
        return 0;
    }
};