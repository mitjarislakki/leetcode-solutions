// Daily 30.3.2024
// 948. Bag of Tokens
// https://leetcode.com/problems/bag-of-tokens/submissions/1218315921/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int highScore = score;
        int left = 0, right = tokens.size() -1;
        while(left <= right){
            if(power >= tokens[left]){
                power -= tokens[left++];
                score++;
                highScore = max(score, highScore);
            }
            else{
                power += tokens[right--];
                score--;
                if(score < 0 ) return 0;
            }
        }
        return highScore;
    }
};