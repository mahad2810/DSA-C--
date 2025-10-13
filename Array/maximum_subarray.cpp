/*
 * Problem: Maximum Subarray
 * -------------------------------------
 * Given an integer array `nums`, find the subarray
 * with the largest sum and return its sum.
 *
 * Example:
 *  Input:  nums = [-2,1,-3,4,-1,2,1,-5,4]
 *  Output: 6
 *  Explanation: The subarray [4, -1, 2, 1] has the largest sum = 6.
 *
 * Approach (Kadane's Algorithm - O(n)):
 * -------------------------------------
 * - Initialize two variables:
 *      currentSum = 0
 *      maxSum = INT_MIN
 * - Traverse the array and add each element to currentSum.
 * - If currentSum becomes greater than maxSum → update maxSum.
 * - If currentSum becomes negative → reset it to 0 (since a negative prefix
 *   will only reduce future subarray sums).
 * - At the end, maxSum holds the maximum subarray sum.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Follow-up:
 * ----------
 * A divide and conquer approach (O(n log n)) also exists but is more complex.
 *
 * Author: Mahad Iqbal
 * Date: October 2025
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int maxSum = INT_MIN;

        for (int num : nums) {
            currentSum += num;
            maxSum = max(maxSum, currentSum);

            // Reset if current sum drops below 0
            if (currentSum < 0) {
                currentSum = 0;
            }
        }

        return maxSum;
    }
};

// Test the solution
int main() {
    Solution solution;

    // Example test cases
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums2 = {1};
    vector<int> nums3 = {5, 4, -1, 7, 8};

    cout << "Test Case 1: [-2,1,-3,4,-1,2,1,-5,4] -> "
         << solution.maxSubArray(nums1) << endl;
    cout << "Test Case 2: [1] -> "
         << solution.maxSubArray(nums2) << endl;
    cout << "Test Case 3: [5,4,-1,7,8] -> "
         << solution.maxSubArray(nums3) << endl;

    return 0;
}
