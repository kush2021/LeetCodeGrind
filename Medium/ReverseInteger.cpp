/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {

        // Check if the number is 0.
        if (x == 0) {
            return x;
        }

        // Check if the number is negative.
        bool neg = false;
        if (x < 0) {
            neg = true;
        }

        // Reverse the int into a string and remove leading 0s.
        auto num = std::to_string(x);
        num.erase(num.find_last_not_of('0') + 1, string::npos);
        if (neg) {
            std::reverse(num.begin() + 1, num.end());
        } else {
            std::reverse(num.begin(), num.end());
        }
        
        // Check for overflow.
        auto min = to_string(INT_MIN);
        auto max = to_string(INT_MAX);
        if ((!neg && num.length() == 10) || (neg && num.length() == 11)) {
            if ((neg && num > min) || (!neg && num > max)) {
                return 0;
            }
        }
        return stoi(num); 
    }
};
// @lc code=end