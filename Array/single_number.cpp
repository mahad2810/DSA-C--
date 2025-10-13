/*
 * Problem: Single Number
 * -------------------------------------
 * Given a non-empty array of integers `nums`,
 * every element appears twice except for one.
 * Find that single one.
 *
 * You must implement a solution with:
 *  - Linear runtime complexity (O(n))
 *  - Constant extra space (O(1))
 *
 * Example:
 *  Input:  nums = [4,1,2,1,2]
 *  Output: 4
 *
 * Approach:
 *  - We use the XOR (^) bitwise operator.
 *  - XOR of a number with itself is 0 (a ^ a = 0)
 *  - XOR of a number with 0 is the number itself (a ^ 0 = a)
 *  - Hence, XORing all numbers cancels out the pairs,
 *    leaving only the single number.
 *
 * Author: Mahad Iqbal
 * Date: October 2025
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNum = 0;

        // XOR all elements in the array
        for (int num : nums) {
            singleNum ^= num; // Cancels duplicates, leaves unique one
        }

        return singleNum;
    }
};

// Test the solution
int main() {
    Solution solution;

    // Example test cases
    vector<int> nums1 = {2, 2, 1};
    vector<int> nums2 = {4, 1, 2, 1, 2};
    vector<int> nums3 = {1};

    cout << "Test Case 1: [2, 2, 1] -> " << solution.singleNumber(nums1) << endl;
    cout << "Test Case 2: [4, 1, 2, 1, 2] -> " << solution.singleNumber(nums2) << endl;
    cout << "Test Case 3: [1] -> " << solution.singleNumber(nums3) << endl;

    return 0;
}
