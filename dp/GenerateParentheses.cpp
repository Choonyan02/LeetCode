class Solution {
public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> dp[n + 1];
        dp[0].insert("");
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (const string& s1 : dp[j]) {
                    for (const string& s2 : dp[i - 1 - j]) {
                        dp[i].insert("(" + s1 + ")" + s2);
                    }
                }
            }
        }
        return vector<string>(dp[n].begin(), dp[n].end());
    }
};
