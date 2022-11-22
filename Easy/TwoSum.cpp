/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        /* Use a hashmap to store complements that provide a solution. */
        std::unordered_map<int, int> found;
        std::vector<int> solution;
        for (int i = 0; i < nums.size(); i++) {
            if (found.find(nums[i]) != found.end()) {
                solution.push_back(found.find(nums[i]) -> second);
                solution.push_back(i);
                return solution;
            }
            found.insert({target - nums[i], i});
        }
        return solution;
    }
};
// @lc code=end

