/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {

        /* Trivial case. */
        if (s == "" || s == "-" || s == "+") {
            return 0;
        }

        /* Remove whitespace. */
        const auto strBegin = s.find_first_not_of(" ");
        if (strBegin == std::string::npos) {
            return 0;
        }
        s = s.substr(strBegin);

        /* Determine the sign. */
        bool neg = false;
        bool trim = false;
        if (s[0] == '-') {
            neg = true;
            trim = true;
        } else if (s[0] == '+') {
            trim = true;
        }

        /* Remove the sign. */
        if (trim) {
            s = s.substr(1);
        }

        /* Remove leading zeroes. */
        const regex pattern("^0+(?!$)");
        s = regex_replace(s, pattern, "");

        /* Read in all consecutive numbers. */
        const auto last = s.find_first_not_of("0123456789");
        s = s.substr(0, last);

        /* Check if the value is zero. */
        if (s == "0" || last == 0) {
            return 0;
        }

        /* Check for overflow. */
        bool overflow = false;
        std::string max = std::to_string(INT_MAX);
        std::string min = std::to_string(INT_MIN).substr(1);
        if (s.size() > 10) {
            overflow = true;
        } else if (s.size() == 10) {
            if (s.compare(max) >= 0 && !neg) {
                overflow = true;
            } else if (s.compare(min) >= 0 && neg) {
                overflow = true;
            }
        }
        
        /* Convert the string. */
        if (neg) {
            if (overflow) {
                return INT_MIN;
            }
            return -1 * stoi(s);
        }
        if (overflow) {
            return INT_MAX;
        }
        return stoi(s);
    }
};
// @lc code=end