// Daily 1.4.2024
// 58. Length of Last Word
// https://leetcode.com/problems/length-of-last-word/submissions/1220460144/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while(i >= 0 && isspace(s[i])) i--;
        int endIndex = i;
        while(i >= 0 && !isspace(s[i])) i--;
        return endIndex - i;
    }
};