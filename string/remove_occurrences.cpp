/*
 * @file remove_occurrences.cpp
 * @brief Removes all occurrences of a substring from a given string.
 *
 * This program defines a function that removes all occurrences of a specified
 * substring (`part`) from a given string (`s`) by repeatedly finding and 
 * erasing the leftmost occurrence until none remain.
 *
 * Problem Description:
 * --------------------
 * Given two strings s and part, perform the following operation on s 
 * until all occurrences of the substring part are removed:
 *   1. Find the leftmost occurrence of part in s.
 *   2. Remove that occurrence from s.
 *
 * Return the resulting string after all occurrences are removed.
 *
 * Example 1:
 * ----------
 * Input:  s = "daabcbaabcbc", part = "abc"
 * Output: "dab"
 * Explanation:
 *   - Remove "abc" at index 2 → s = "dabaabcbc"
 *   - Remove "abc" at index 4 → s = "dababc"
 *   - Remove "abc" at index 3 → s = "dab"
 *
 * Example 2:
 * ----------
 * Input:  s = "axxxxyyyyb", part = "xy"
 * Output: "ab"
 * Explanation:
 *   - Remove "xy" at index 4 → "axxxyyyb"
 *   - Remove "xy" at index 3 → "axxyyb"
 *   - Remove "xy" at index 2 → "axyb"
 *   - Remove "xy" at index 1 → "ab"
 *
 * Approach:
 * ----------
 * - Use a loop to repeatedly search for the substring `part` using `s.find(part)`.
 * - If found, remove it using `s.erase(position, length_of_part)`.
 * - Continue until no more occurrences are found.
 *
 * Time Complexity:  O(n * m)
 *     (where n = length of s, m = length of part; because `find()` and `erase()` 
 *      may each take linear time per iteration)
 *
 * Space Complexity: O(1)
 *     (in-place modification of the input string)
 *
 * Constraints:
 * - 1 <= s.length <= 1000
 * - 1 <= part.length <= 100
 * - s and part consist of lowercase English letters only.
 *
 * Author: Mahad Iqbal
 * Date: November 2025
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * @brief Removes all occurrences of substring `part` from string `s`.
     * 
     * @param s The original string.
     * @param part The substring to remove from `s`.
     * @return The string after removing all occurrences of `part`.
     */
    string removeOccurrences(string s, string part) {
        while (s.length() > 0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

// Example usage (for demonstration and testing)
int main() {
    Solution solution;

    string s1 = "daabcbaabcbc", part1 = "abc";
    cout << "Input:  " << s1 << " | Part: " << part1 << endl;
    cout << "Output: " << solution.removeOccurrences(s1, part1) << endl;
    cout << "----------------------------" << endl;

    string s2 = "axxxxyyyyb", part2 = "xy";
    cout << "Input:  " << s2 << " | Part: " << part2 << endl;
    cout << "Output: " << solution.removeOccurrences(s2, part2) << endl;

    return 0;
}
