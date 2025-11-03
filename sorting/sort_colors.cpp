/*
 * Title: Sort Colors (Dutch National Flag Problem)
 * Author: Mahad Iqbal
 * Date: November 2025
 * 
 * Problem Description:
 * --------------------
 * Given an array 'nums' containing n objects colored red, white, or blue,
 * sort them in-place so that objects of the same color are adjacent,
 * with the colors in the order red, white, and blue.
 * 
 * We use integers to represent colors:
 *     0 → Red
 *     1 → White
 *     2 → Blue
 * 
 * The goal is to sort the array without using the built-in sort function,
 * in one pass, and with constant extra space.
 * 
 * Example:
 * --------
 * Input:  nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Approach:
 * ----------
 * This is a classic application of the Dutch National Flag Algorithm
 * proposed by Edsger W. Dijkstra.
 * 
 * We maintain three pointers:
 *   - low:   marks the boundary of 0s (red)
 *   - mid:   current element being examined
 *   - high:  marks the boundary of 2s (blue)
 * 
 * Algorithm Steps:
 * ----------------
 * 1. Initialize: low = 0, mid = 0, high = n - 1
 * 2. Traverse the array while mid <= high:
 *      - If nums[mid] == 0 → swap(nums[low], nums[mid]); low++; mid++;
 *      - If nums[mid] == 1 → mid++;
 *      - If nums[mid] == 2 → swap(nums[mid], nums[high]); high--;
 * 
 * 3. The array is sorted in-place with all 0s, then 1s, then 2s.
 * 
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 * 
 * Constraints:
 * ------------
 * 1 <= n <= 300
 * nums[i] ∈ {0, 1, 2}
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        // Traverse the array and sort based on the three pointers
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } 
            else if (nums[mid] == 1) {
                mid++;
            } 
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Before sorting: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    sol.sortColors(nums);

    cout << "After sorting:  ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}
