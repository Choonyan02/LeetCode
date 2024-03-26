class Solution {
public:

    pair<int, int> countZeroOnes(const string& str) {
        int zero = 0, one = 0;
        for (char c : str) {
            if (c == '0') {
                zero++;
            } else if (c == '1') {
                one++;
            }
        }
        return make_pair(zero, one);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        vector<int> zeroes = vector<int>(strs.size());
        vector<int> ones = vector<int>(strs.size());
        int zero, one;
        for (int i = 0; i < strs.size(); i++) {
            tie(zero, one) = countZeroOnes(strs[i]);
            zeroes[i] = zero;
            ones[i] = one;
        }
        for (int i = 0; i < strs.size(); i++) {
            for (int j = m; j >= 0; j--) {
                for (int k = n; k >= 0; k--) {
                    if (zeroes[i] <= j && ones[i] <= k) {
                        dp[j][k] = max(dp[j - zeroes[i]][k - ones[i]] + 1, dp[j][k]);
                    }
                }
            }
       }
       return dp[m][n];
    }
};
