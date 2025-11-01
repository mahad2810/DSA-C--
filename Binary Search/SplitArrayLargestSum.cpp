/**
 * @file SplitArrayLargestSum.cpp
 * @brief Solution for LeetCode Problem 410: Split Array Largest Sum.
 * * This file contains the implementation of a class `Solution` that solves
 * the "Split Array Largest Sum" problem. The problem asks to split a given
 * array `nums` into `k` contiguous subarrays such that the maximum sum
 * of any subarray is minimized.
 * * The approach used is Binary Search on the Answer.
 * * Problem Link: https://leetcode.com/problems/split-array-largest-sum/
 */

#include <vector>
#include <numeric>      // For std::accumulate (though we sum manually)
#include <algorithm>    // For std::max
#include <iostream>     // For std::cout (if main is added for testing)

using namespace std;

/**
 * @class Solution
 * @brief Implements the solution for the Split Array Largest Sum problem.
 */
class Solution {
private:
    /**
     * @brief Helper function to check if a given max sum is feasible.
     * * This function greedily checks if it's possible to partition the `nums`
     * array into `k` or fewer subarrays, where no subarray has a sum
     * greater than `target_max_sum`.
     * * @param nums The input array of numbers.
     * @param k The maximum number of subarrays allowed.
     * @param target_max_sum The potential answer (the max sum limit we are testing).
     * @return true if the array can be split into `k` or fewer subarrays
     * adhering to the `target_max_sum` limit.
     * @return false if more than `k` subarrays are required.
     */
    bool can_split(vector<int>& nums, int k, long long target_max_sum) {
        // Start with the first subarray
        int subarrays_needed = 1;
        long long current_sum = 0;

        for (int num : nums) {
            // This is a key check: if a single element is larger than the
            // target sum, it's impossible to split, even by itself.
            // Note: Our main function's `low` initialization already handles this,
            // but this check adds robustness.
            if (num > target_max_sum) {
                return false;
            }

            // If adding the current number to the current subarray
            // exceeds the limit...
            if (current_sum + num > target_max_sum) {
                // ...we must start a new subarray.
                subarrays_needed++;
                // The new subarray starts with the current number.
                current_sum = num;

                // If we've already exceeded the allowed number of subarrays,
                // we can stop early and return false.
                if (subarrays_needed > k) {
                    return false;
                }
            } else {
                // Otherwise, just add the number to the current subarray.
                current_sum += num;
            }
        }

        // After checking all numbers, the total number of subarrays
        // needed must be within the allowed limit 'k'.
        return subarrays_needed <= k;
    }

public:
    /**
     * @brief Finds the minimized largest sum of the split.
     * * This function uses binary search on the range of possible answers.
     * The smallest possible answer is the largest element in the array.
     * The largest possible answer is the sum of all elements in the array.
     * * We binary search within this range [low, high] to find the
     * smallest value for which `can_split` returns true.
     * * @param nums A vector of integers to be split.
     * @param k The number of non-empty subarrays to split into.
     * @return The minimized largest sum among the 'k' subarrays.
     */
    int splitArray(vector<int>& nums, int k) {
        
        // 1. Define the search space for our answer.
        // We use 'long long' to prevent overflow when calculating 'high' and 'mid'.
        
        long long low = 0;  // Lower bound: the largest single element in nums.
        long long high = 0; // Upper bound: the total sum of all elements in nums.

        for (int num : nums) {
            high += num;
            low = max(low, (long long)num);
        }

        // This variable will store the best possible answer we've found.
        long long min_largest_sum = high;

        // 2. Binary search for the smallest 'mid' (target_max_sum)
        //    for which can_split(mid) is true.
        while (low <= high) {
            // Calculate mid to avoid potential overflow: low + (high - low) / 2
            long long mid = low + (high - low) / 2;

            if (can_split(nums, k, mid)) {
                // This 'mid' is a *possible* answer.
                // We store it as our current best...
                min_largest_sum = mid;
                
                // ...and try to find an even smaller answer. We search
                // in the lower half: [low, mid - 1].
                high = mid - 1;
            } else {
                // This 'mid' is too small. We can't split the array
                // into 'k' subarrays with this max sum.
                // We must increase our 'mid', so we search
                // in the upper half: [mid + 1, high].
                low = mid + 1;
            }
        }

        // 3. The loop terminates when low > high.
        // The last valid 'mid' we found (stored in min_largest_sum)
        // is the smallest possible maximum sum.
        // Alternatively, 'low' also ends up holding this value.
        // return (int)low; // This also works.
        return (int)min_largest_sum;
    }
};

/*
// --- Example Usage (Optional: for testing) ---
// You can uncomment this main function to test the code.
int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {7, 2, 5, 10, 8};
    int k1 = 2;
    cout << "Example 1 Output: " << sol.splitArray(nums1, k1) << endl; // Expected: 18

    // Example 2
    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 2;
    cout << "Example 2 Output: " << sol.splitArray(nums2, k2) << endl; // Expected: 9

    // Example 3
    vector<int> nums3 = {1, 4, 4};
    int k3 = 3;
    cout << "Example 3 Output: " << sol.splitArray(nums3, k3) << endl; // Expected: 4

    return 0;
}
*/