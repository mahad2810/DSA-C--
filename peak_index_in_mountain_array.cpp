/*
 * File: peak_index_in_mountain_array.cpp
 * Author: Mahad Iqbal
 * Date: October 19, 2025
 * Description:
 *   This program finds the peak index in a mountain array.
 *   A mountain array is defined as an array where elements strictly increase
 *   to a single peak element, then strictly decrease.
 *
 *   The algorithm uses a binary search approach to find the peak element
 *   in O(log n) time complexity.
 *
 * Example:
 *   Input:  arr = [0, 2, 1, 0]
 *   Output: 1
 *
 * Constraints:
 *   - 3 <= arr.length <= 10^5
 *   - 0 <= arr[i] <= 10^6
 *   - arr is guaranteed to be a mountain array.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the peak index in a mountain array
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int start = 1, end = n - 2;  // Avoid boundaries since peak cannot be at index 0 or n-1
        int mid = 0;

        while (start <= end) {
            mid = start + (end - start) / 2;

            // Check if mid is the peak element
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            }

            // If the slope is rising, move right
            if (arr[mid] < arr[mid + 1]) {
                start = mid + 1;
            }
            // If the slope is falling, move left
            else {
                end = mid - 1;
            }
        }

        // Should never reach here for a valid mountain array
        return -1;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> arr = {0, 2, 1, 0};
    cout << "Peak Index: " << sol.peakIndexInMountainArray(arr) << endl;
    return 0;
}
