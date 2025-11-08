/**
 * @file next_permutation.cpp
 * @brief Compute the next lexicographical permutation of a sequence of integers.
 *
 * This program defines a function to rearrange a given vector of integers
 * into its next lexicographically greater permutation. If no such permutation
 * exists (i.e., the array is in descending order), it rearranges the array
 * into the smallest possible order (ascending order).
 *
 * Problem Statement:
 * ------------------
 * A permutation of an array is an arrangement of its members in a sequence.
 * The "next permutation" is the next greater arrangement in lexicographical order.
 * If the array is the largest permutation, the next permutation is the smallest (sorted ascending).
 *
 * Example:
 * --------
 * Input:
 *   nums = [1, 2, 3]
 * Output:
 *   [1, 3, 2]
 *
 * Input:
 *   nums = [3, 2, 1]
 * Output:
 *   [1, 2, 3]
 *
 * Input:
 *   nums = [1, 1, 5]
 * Output:
 *   [1, 5, 1]
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Constraints:
 * ------------
 * - 1 <= nums.length <= 100
 * - 0 <= nums[i] <= 100
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Rearranges the numbers into the next lexicographically greater permutation.
     *
     * If such arrangement is not possible, it rearranges it as the lowest possible order
     * (sorted in ascending order). The algorithm modifies the input vector in place.
     *
     * @param nums The input vector of integers.
     */
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // Step 1: Find the rightmost element that is smaller than its next element
        // This identifies the "pivot" where the next permutation change occurs.
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: If no such pivot exists, the array is the last permutation.
        // Reverse it to get the smallest (sorted) permutation.
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the rightmost element greater than the pivot element
        // and swap them to make the sequence just larger.
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 4: Reverse the subarray to the right of the pivot
        // to get the smallest lexicographical order for that part.
        int i = pivot + 1;
        int j = n - 1;
        while (i < j) {
            swap(nums[i++], nums[j--]);
        }
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    sol.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
