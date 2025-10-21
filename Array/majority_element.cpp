/*
    Title: Majority Element (LeetCode Problem 169)
    Author: Mahad Iqbal
    Date: October 2025
    Description:
        Given an array nums of size n, return the majority element.
        The majority element is the element that appears more than ⌊n / 2⌋ times.

        You may assume that the majority element always exists in the array.

    Approach:
        → This solution uses the Boyer-Moore Voting Algorithm.
        → It runs in O(n) time and O(1) space.

    Steps:
        1. Initialize a frequency counter (freq = 0) and a candidate (ans = nums[0]).
        2. Traverse through the array:
            - If freq == 0, set current element as candidate.
            - If current element equals candidate, increment freq.
            - Else, decrement freq.
        3. (Optional) Verify if the candidate actually appears more than n/2 times.
        4. Return the candidate if it satisfies the condition; otherwise, return -1.

    Example:
        Input: nums = [2, 2, 1, 1, 1, 2, 2]
        Output: 2

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0;           // Frequency counter
        int ans = nums[0];      // Potential majority candidate
        int n = nums.size();
        int c = 0;              // Counter for verification

        // Step 1: Find the candidate using Boyer-Moore Voting Algorithm
        for (int val : nums) {
            if (freq == 0) {
                ans = val;
            }
            if (ans == val) {
                freq++;
            } else {
                freq--;
            }
        }

        // Step 2: Verify if candidate is majority
        for (int val : nums) {
            if (ans == val) {
                c++;
            }
        }

        if (c > n / 2) {
            return ans;
        }

        return -1;  // Should not happen as per problem statement
    }
};

// Example usage (for testing before pushing to GitHub)
int main() {
    Solution s;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << s.majorityElement(nums) << endl;
    return 0;
}
