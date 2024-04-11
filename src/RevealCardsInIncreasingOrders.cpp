class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(begin(deck), end(deck));
        int n = deck.size(), i;
        queue<int> mQ;
        for (i = 0; i < n; i++) mQ.push(i);
        vector<int> ans(n, 0);
        for (i = 0; i < n; i++) {
            ans[mQ.front()] = deck[i];
            mQ.pop();
            mQ.push(mQ.front());
            mQ.pop();
        }
        return ans;
    }
};
