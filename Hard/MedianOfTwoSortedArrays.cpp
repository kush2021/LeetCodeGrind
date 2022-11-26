/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        /* Trivial cases. */
        const int size1 = nums1.size(), size2 = nums2.size();
        if (size1 == 0 && size2 == 0) {
            return 0;
        } else if (size1 == 0) {
            if (size2 % 2 == 0) {
                return (nums2[size2 / 2] + nums2[size2 / 2 - 1]) / 2.0;
            } else {
                return nums2[size2 / 2];
            }
        } else if (size2 == 0) {
            if (size1 % 2 == 0) {
                return (nums1[size1 / 2] + nums1[size1 / 2 - 1]) / 2.0;
            } else {
                return nums1[size1 / 2];
            }
        }

        /* Case 1: Arrays are the same size. */
        if (size1 == size2) {
            int start1 = 0, start2 = 0, end1 = size1, end2 = size2;
            while (start1 <= end1) {
                const int n = end1 - start1;
                if (n == 2) {
                    return (max(nums1[start1], nums2[start2]) + min(nums1[start1 + 1], nums2[start2 + 1])) / 2.0;
                }
                if (n == 1) {
                    return (nums1[start1] + nums2[start2]) / 2.0;
                }
                float median1, median2;
                if ((end1 - start1) % 2 == 0) {
                    median1 = (nums1[n / 2 + start1] + nums1[n / 2 - 1 + start1]) / 2.0;
                    median2 = (nums2[n / 2 + start2] + nums2[n / 2 - 1 + start2]) / 2.0;
                } else {
                    median1 = nums1[n / 2 + start1];
                    median2 = nums2[n / 2 + start2];
                }
                if (median1 == median2) {
                    return median1;
                } else if (median1 < median2) {
                    if (n % 2 == 0) {
                        start1 = n / 2 - 1 + start1;
                        end2 = end2 - n / 2 + 1;
                    } else {
                        start1 = n / 2 + start1;
                        end2 = end2 - n / 2;
                    }
                } else {
                    if (n % 2 == 0) {
                        start2 = n / 2 - 1 + start2;
                        end1 = end1 - n / 2 + 1;
                    } else {
                        start2 = n / 2 + start2;
                        end1 = end1 - n / 2;
                    }
                }
            }
        }

        /* Case 2: Arrays are different sizes. */
        else {
            if (size1 > size2) {
                return (findMedianSortedArrays(nums2, nums1));
            }
            int start1 = 0, end1 = size1, partitionX, partitionY, realMid = (size1 + size2 + 1) / 2;
            while (start1 <= end1) {
                int mid = (start1 + end1) / 2;
                int partitionX = mid;
                int partitionY = realMid - mid;
                int leftX = (partitionX > 0) ? nums1[partitionX - 1] : INT_MIN;
                int leftY = (partitionY > 0) ? nums2[partitionY - 1] : INT_MIN;
                int rightX = (partitionX < size1) ? nums1[partitionX] : INT_MAX;
                int rightY = (partitionY < size2) ? nums2[partitionY] : INT_MAX;
                if (leftX <= rightY && rightX >= leftY) {
                    if ((size1 + size2) % 2 == 0) {
                        return (max(leftX, leftY) + min(rightX, rightY)) / 2.0;
                    }
                    return max(leftX, leftY);
                } else if (leftX > rightY) {
                    end1 = mid - 1;
                } else {
                    start1 = mid + 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

