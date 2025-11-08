/**
 * @file merge_sorted_arrays.cpp
 * @brief Merge two sorted integer arrays into one sorted array in-place.
 *
 * This program defines a function to merge two sorted arrays, nums1 and nums2,
 * into a single sorted array stored in nums1. The function works in O(m + n) time,
 * using a reverse two-pointer approach.
 *
 * Problem Statement:
 * ------------------
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
 * and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 *
 * Merge nums1 and nums2 into a single sorted array stored inside nums1.
 * nums1 has a size of m + n, where the first m elements are valid and the remaining n are zeros.
 *
 * Example:
 * --------
 * Input:
 *  nums1 = [1,2,3,0,0,0], m = 3
 *  nums2 = [2,5,6], n = 3
 * Output:
 *  nums1 = [1,2,2,3,5,6]
 *
 * Time Complexity: O(m + n)
 * Space Complexity: O(1)
 *
 * Constraints:
 * ------------
 * - nums1.length == m + n
 * - nums2.length == n
 * - 0 <= m, n <= 200
 * - 1 <= m + n <= 200
 * - -10^9 <= nums1[i], nums2[j] <= 10^9
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Merges two sorted arrays nums1 and nums2 into nums1 in non-decreasing order.
     *
     * @param nums1 The first sorted array, with extra space at the end (size = m + n).
     * @param m The number of valid elements in nums1.
     * @param nums2 The second sorted array (size = n).
     * @param n The number of elements in nums2.
     */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;       // Pointer for last valid element in nums1
        int j = n - 1;       // Pointer for last element in nums2
        int idx = m + n - 1; // Pointer for the final position in nums1

        // Merge from the end to avoid overwriting values in nums1
        while (i >= 0 && j >= 0) {
            if (nums2[j] >= nums1[i]) {
                nums1[idx] = nums2[j];
                j--;
            } else {
                nums1[idx] = nums1[i];
                i--;
            }
            idx--;
        }

        // Copy remaining elements of nums2 (if any)
        while (j >= 0) {
            nums1[idx] = nums2[j];
            idx--;
            j--;
        }
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    sol.merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
