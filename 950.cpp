// Daily 10.4.2024
// 950. Reveal Cards In Increasing Order
// https://leetcode.com/problems/reveal-cards-in-increasing-order/submissions/1228342858/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), greater<int>());
        deque<int> order;
        order.push_back(deck[0]);
        for(int i = 1; i<deck.size(); i++){
            order.push_front(order.back());
            order.pop_back();
            order.push_front(deck[i]);
        }
        vector<int> res(order.begin(), order.end());
        return res;
    }
};