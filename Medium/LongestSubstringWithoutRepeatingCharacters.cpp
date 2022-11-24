/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        /* Base case. */
        if (s.length() == 0) {
            return 0;
        } else if (s.length() == 1) {
            return 1;
        }

        /* Use a dynamic sliding window. */
        int left = 0, right = 1, maxSubstr = 1;
        std::unordered_map<char, int> indexes = {{s[0], 0}};
        while (right <= s.length() - 1) {
            if (indexes.find(s[right]) != indexes.end() && indexes.find(s[right]) -> second >= left) {
                left = 1 + indexes.find(s[right]) -> second;
                indexes.find(s[right]) -> second = right;
            } else if (indexes.find(s[right]) != indexes.end()) {
                indexes.find(s[right]) -> second = right;
            } else {
                indexes.insert({{s[right], right}});
            }
            maxSubstr = max(maxSubstr, right - left + 1);
            right++;
        }
        return maxSubstr;
    }
};
// @lc code=end

