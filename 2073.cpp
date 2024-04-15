// Daily 9.4.2024
// 2073. Time Needed to Buy Tickets
// https://leetcode.com/problems/time-needed-to-buy-tickets/submissions/1227711686


class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int rotations = tickets[k];
        int seconds = 0;
        int i;
        for(i = 0; i<=k; i++){
            int add = min(tickets[i], rotations);
            seconds += add;
        }
        rotations--;
        for(; i<tickets.size(); i++){
            int add = min(tickets[i], rotations);
            seconds += add;
        }
        return seconds;
    }
};