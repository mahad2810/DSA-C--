/*
 * File: single_element_in_sorted_array.cpp
 * Author: Mahad Iqbal
 * Date: October 19, 2025
 * Description:
 *   This program finds the single non-duplicate element in a sorted array
 *   where every other element appears exactly twice.
 *
 *   The algorithm uses a binary search approach to achieve O(log n) time
 *   complexity and O(1) space complexity.
 *
 * Example:
 *   Input:  nums = [1,1,2,3,3,4,4,8,8]
 *   Output: 2
 *
 *   Input:  nums = [3,3,7,7,10,11,11]
 *   Output: 10
 *
 * Constraints:
 *   - 1 <= nums.length <= 10^5
 *   - 0 <= nums[i] <= 10^5
 *   - The input array is sorted and follows the described property.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the single non-duplicate element using binary search
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int start = 0, end = n - 1;

        // If there's only one element, return it directly
        if (n == 1) {
            return arr[0];
        }

        int mid = 0;
        while (start <= end) {
            mid = start + (end - start) / 2;

            // Edge cases: check boundaries
            if (mid == 0 && arr[0] != arr[1]) {
                return arr[0];
            }
            if (mid == n - 1 && arr[n - 1] != arr[n - 2]) {
                return arr[n - 1];
            }

            // Found the unique element
            if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
                return arr[mid];
            }

            /*
             * Logic:
             * Since elements appear in pairs, the first instance of the pair
             * occurs at an even index and the second at an odd index before
             * the single element. After the single element, this pattern flips.
             *
             * We use this property to decide which half to discard.
             */
            if (mid % 2 == 0) {
                if (arr[mid - 1] == arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (arr[mid - 1] == arr[mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        // Should never reach here for a valid input
        return -1;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Single Non-Duplicate Element: " << sol.singleNonDuplicate(nums) << endl;
    return 0;
}
