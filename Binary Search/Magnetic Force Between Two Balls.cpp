/*
 * Title: Magnetic Force Between Two Balls
 * Problem: Rick and Morty Universe (Earth C-137)
 * Author: Mahad Iqbal
 * Description:
 *   In the universe Earth C-137, Rick discovered a special magnetic force between balls placed in baskets.
 *   Given 'n' baskets at different positions and 'm' balls, we must place the balls such that the 
 *   minimum magnetic force between any two balls is maximized.
 *
 *   The magnetic force between two balls at positions x and y is |x - y|.
 *
 * Approach:
 *   - Sort the basket positions.
 *   - Use Binary Search to determine the largest possible minimum distance (magnetic force)
 *     that can be achieved while still placing all m balls.
 *   - For each mid (candidate distance), check feasibility using the `isPossible` helper function.
 *
 * Time Complexity: O(n log(max_distance))
 * Space Complexity: O(1)
 *
 * Example:
 *   Input:  position = [1,2,3,4,7], m = 3
 *   Output: 3
 *   Explanation:
 *     Place balls at positions 1, 4, and 7 → distances = [3, 3, 6]
 *     Minimum magnetic force = 3
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Check if it is possible to place 'm' balls in the baskets such that
     *        the minimum magnetic force between any two balls is at least 'mid'.
     *
     * @param position Sorted vector of basket positions.
     * @param m Number of balls to place.
     * @param mid Candidate minimum magnetic force.
     * @return true if possible to place all balls with at least 'mid' distance apart.
     * @return false otherwise.
     */
    bool isPossible(vector<int>& position, int m, int mid) {
        int magnets = 1;                // Place the first ball in the first basket
        int lastPlaced = position[0];   // Track position of the last placed ball
        int n = position.size();

        for (int i = 1; i < n; i++) {
            // Place the next ball if distance >= mid
            if (position[i] - lastPlaced >= mid) {
                magnets++;
                lastPlaced = position[i];
            }

            // If all m balls are placed successfully, return true
            if (magnets == m) {
                return true;
            }
        }
        return false;  // Not possible to place all m balls with given mid
    }

    /**
     * @brief Find the largest minimum magnetic force between any two balls.
     *
     * @param position Vector containing basket positions.
     * @param m Number of balls to distribute.
     * @return int Maximum possible minimum magnetic force.
     */
    int maxDistance(vector<int>& position, int m) {
        // Step 1: Sort basket positions
        sort(position.begin(), position.end());

        int n = position.size();
        int start = 1;                         // Minimum possible distance
        int end = position[n - 1] - position[0]; // Maximum possible distance
        int ans = 0;                           // Store result

        // Step 2: Binary search to find the optimal (maximum minimum) distance
        while (start <= end) {
            int mid = start + (end - start) / 2;  // Candidate distance

            // If it’s possible to place balls with at least 'mid' distance
            if (isPossible(position, m, mid)) {
                ans = mid;         // Update result
                start = mid + 1;   // Try for a larger distance
            } else {
                end = mid - 1;     // Try for a smaller distance
            }
        }
        return ans;
    }
};

// Example driver code (optional, for testing)
/*
int main() {
    Solution sol;
    vector<int> position = {1, 2, 3, 4, 7};
    int m = 3;
    cout << "Maximum Magnetic Force: " << sol.maxDistance(position, m) << endl;
    return 0;
}
*/

