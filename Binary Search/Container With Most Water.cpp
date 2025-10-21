/*
    Problem: Container With Most Water
    ----------------------------------
    You are given an integer array 'height' of length n. 
    There are n vertical lines drawn such that the two endpoints of the ith line 
    are (i, 0) and (i, height[i]).

    Find two lines that, together with the x-axis, form a container such that 
    the container holds the maximum amount of water.

    Return the maximum amount of water a container can store.

    Note:
    -----
    - You cannot slant the container.
    - Each line’s width (distance between indices) contributes to the area calculation.

    Example 1:
    -----------
    Input:  height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    Explanation:
        The maximum area is formed between lines at indices 1 and 8:
        width = 8 - 1 = 7
        height = min(8, 7) = 7
        area = 7 * 7 = 49

    Example 2:
    -----------
    Input:  height = [1,1]
    Output: 1
    Explanation:
        Only two lines available:
        width = 1
        height = 1
        area = 1 * 1 = 1

    Constraints:
    ------------
    - n == height.length
    - 2 <= n <= 10^5
    - 0 <= height[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int start = 0;          // Left pointer
        int end = n - 1;        // Right pointer
        int maxCapacity = 0;    // To store the maximum area found

        // Two-pointer approach
        while (start < end) {
            int length = end - start;                        // Distance between lines
            int breadth = min(height[start], height[end]);    // Shorter line limits the height
            int capacity = length * breadth;                  // Area = width * height

            // Update maximum area if current is greater
            maxCapacity = max(maxCapacity, capacity);

            // Move the pointer pointing to the shorter line
            if (height[start] <= height[end]) {
                start++;
            } else {
                end--;
            }
        }

        return maxCapacity;
    }
};

// Example driver code
int main() {
    Solution sol;
    vector<int> height1 = {1,8,6,2,5,4,8,3,7};
    vector<int> height2 = {1,1};

    cout << "Example 1 Output: " << sol.maxArea(height1) << endl;  // Expected: 49
    cout << "Example 2 Output: " << sol.maxArea(height2) << endl;  // Expected: 1

    return 0;
}
