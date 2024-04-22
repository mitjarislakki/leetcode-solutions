// Daily 22.4.2024
// 752. Open the Lock
// https://leetcode.com/problems/open-the-lock/submissions/1238868785/
// Could be further optimized by using shorts in the queue via stoi()

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        bitset<10000> ends;
        /// Mark dead ends as already visited
        for(auto s : deadends){
            ends[stoi(s)] = true;
        }
        
        if(ends[0]) return -1;

        int result = 0;

        // BFS
        queue<string> q{{"0000"}};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                const string cur = q.front();
                q.pop();
                if(cur == target) return result;
                for(int i = 0; i <4; i++){
                    string inc = cur;
                    string dec = cur;
                    inc[i] = (cur[i] == '9' ? '0' : cur[i]+1);
                    dec[i] = (cur[i] == '0' ? '9' : cur[i]-1);
                    short u = stoi(inc);
                    short d = stoi(dec);
                    if(!ends[u]){
                        q.push(inc);
                        ends[u] = true;
                    }
                    if(!ends[d]){
                        q.push(dec);
                        ends[d] = true;
                    }
                } 
            }
            result++;
        }
        return -1;
    }
};