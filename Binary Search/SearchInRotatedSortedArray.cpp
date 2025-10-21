/*
----------------------------------------
    Problem: Search in Rotated Sorted Array
----------------------------------------
There is an integer array `nums` sorted in ascending order 
(with distinct values). The array may have been rotated 
at an unknown index `k` (1 <= k < nums.length).

After rotation, the array looks like:
    [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]

You are given the rotated array `nums` and an integer `target`. 
Your task is to return the index of `target` if it exists, 
otherwise return -1.

----------------------------------------
Example 1:
Input:  nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input:  nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input:  nums = [1], target = 0
Output: -1

----------------------------------------
Constraints:
1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is sorted in ascending order but possibly rotated.
-10^4 <= target <= 10^4
----------------------------------------
Approach (Binary Search):
----------------------------------------
To achieve O(log n) runtime:
1. Use binary search with pointers `start` and `end`.
2. Find `mid` = start + (end - start) / 2.
3. If nums[mid] == target → return mid.
4. Determine which half (left or right) is sorted:
   - If left half [start..mid] is sorted:
        If target lies within this range → move to left half.
        Else → move to right half.
   - Else (right half [mid..end] is sorted):
        If target lies within this range → move to right half.
        Else → move to left half.
5. If not found after the loop → return -1.

----------------------------------------
Time Complexity:  O(log n)
Space Complexity: O(1)
----------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[start] <= nums[mid]) {
                if (target >= nums[start] && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            } 
            // Right half is sorted
            else {
                if (target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return -1;
    }
};

// -----------------------------
// Example main() for testing
// -----------------------------
int main() {
    Solution obj;

    vector<int> nums1 = {4,5,6,7,0,1,2};
    vector<int> nums2 = {4,5,6,7,0,1,2};
    vector<int> nums3 = {1};

    cout << "Example 1: " << obj.search(nums1, 0) << endl;  // Output: 4
    cout << "Example 2: " << obj.search(nums2, 3) << endl;  // Output: -1
    cout << "Example 3: " << obj.search(nums3, 0) << endl;  // Output: -1

    return 0;
}
