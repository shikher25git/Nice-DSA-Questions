// Course Schedule 3
// Variation: https://codeforces.com/problemset/problem/1526/C2

class Solution {
public:
    static bool cmp(const vector<int>&a, const vector<int>&b){
        if(a[1] == b[1]){
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int> pq;
        int curr = 1, ans = 0;
        for(int i=0;i<courses.size();i++){
            if(curr + courses[i][0] - 1 <= courses[i][1]){
                ++ans;
                curr += courses[i][0];
                pq.push(courses[i][0]);
            }
            else{
                if(!pq.empty() and pq.top() > courses[i][0]){
                    curr -= pq.top() - courses[i][0];
                    pq.pop();
                    pq.push(courses[i][0]);
                }
            }
        }
        return ans;
    }
};