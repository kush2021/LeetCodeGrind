/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {

        /* Create an n x n table. */
        const int n = s.size();
        bool table[n][n];
        memset(table, 0, sizeof(table));

        /* All substrings of length one are palindromes. */
        int maxLength = 1;
        for (int i = 0; i < n; i++) {
            table[i][i] = true;
        }

        /* Check substrings of length two. */
        int start = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                table[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        /* Check for all other substrings. */
        for (int k = 3; k <= n; k++) {
            for (int i = 0; i < n - k + 1; i++) {
                int j = i + k - 1;
                if (table[i + 1][j - 1] == true && s[i] == s[j]) {
                    table[i][j] = true;
                    if (k > maxLength) {
                        start = i;
                        maxLength = k;
                    }
                }
            }
        }
        return s.substr(start, maxLength);
    }
};
// @lc code=end

