/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {

        bool isMatch(string s, string p) {
        const int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector(n + 1, false));
        dp[m][n] = true;
        for (int i = m; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                bool match1 = (i < m) && (p[j] == '.' || p[j] == s[i]);
                if (j + 1 < n && p[j + 1] == '*') {
                    dp[i][j] = (match1 && dp[i + 1][j] || dp[i][j + 2]);
                } else {
                    dp[i][j] = match1 && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

