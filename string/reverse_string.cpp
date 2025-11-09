/*
 * @file reverse_string.cpp
 * @brief Function to reverse a string in-place.
 *
 * This program defines a function that reverses a given string represented as 
 * an array (vector) of characters. The reversal is done in-place using O(1) 
 * extra memory, which means the input array itself is modified without using 
 * any additional data structures.
 *
 * Example:
 * Input:  s = ['h', 'e', 'l', 'l', 'o']
 * Output: ['o', 'l', 'l', 'e', 'h']
 *
 * Approach:
 * - Use two pointers: one starting from the beginning and one from the end.
 * - Swap characters at these positions.
 * - Move both pointers toward the center until they meet.
 *
 * Time Complexity:  O(n)  (where n is the length of the string)
 * Space Complexity: O(1)  (in-place reversal)
 *
 * Constraints:
 * - 1 <= s.length <= 10^5
 * - s[i] is a printable ASCII character.
 *
 * Author: Mahad Iqbal
 * Date: November 2025
 */

#include <iostream>
#include <vector>
#include <algorithm>  // For std::swap
using namespace std;

class Solution {
public:
    /**
     * @brief Reverses the input string (character vector) in-place.
     * 
     * @param s Vector of characters representing the string.
     */
    void reverseString(vector<char>& s) {
        int n = s.size();
        int start = 0, end = n - 1;

        // Swap elements until the middle is reached
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};

// Example usage (optional for testing)
int main() {
    Solution solution;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    cout << "Original string: ";
    for (char c : s) cout << c;
    cout << endl;

    solution.reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) cout << c;
    cout << endl;

    return 0;
}
