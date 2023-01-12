/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {

         /* Convert the integer to a string. */
        string strX = to_string(x);
        string strReverseX = strX;

        /* Reverse the string. */
        reverse(strReverseX.begin(), strReverseX.end());

        /* Check if the reverse and the original are the same. */
        return !strX.compare(strReverseX);

    }
};
// @lc code=end

