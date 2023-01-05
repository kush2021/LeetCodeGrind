/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
       const int n = numRows;
        string str;

        // Trivial case.
        if (n == 1) {
            return s;
        }
        
        // First line.
        for (int i = 0; i < s.length(); i += (n - 1) * 2) {
            str += s[i];
        }
        
        // Middle lines.
        for (int j = 1; j < n - 1; j++) {
            bool goDown = true;
            for (int i = j; i < s.length();){
                str += s[i];
                if (goDown) {
                    i += (n - j - 1) * 2;
                } else{
                    i += (n - 1) * 2 - (n - j - 1) * 2;
                }
                goDown = !goDown;
            }
            
        }
        
        // Last line.
        for (int i = n - 1; i < s.length(); i += (n - 1) * 2) {
            str += s[i];
        }
        return str;
    }
};
// @lc code=end