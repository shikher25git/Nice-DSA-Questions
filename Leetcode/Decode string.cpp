class Solution {
public:
    string decodeString(string s) {
        stack<string> a;
        stack<int> b;
        string ans;
        int num=0;
        for(auto i: s){
            if(isalpha(i)){
                ans+=i;
            }
            else if(isdigit(i)){
                num = num*10 + (i - '0');
            }
            else if(i == '['){
                a.push(ans);
                b.push(num);
                ans="";
                num=0;
            }
            else{
                string temp = ans;
                for(int i=0;i<b.top()-1;i++){
                    ans += temp;
                }
                ans = a.top() + ans;
                a.pop(); b.pop();
            }
        }
        return ans;
    }
};