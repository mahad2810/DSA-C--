/*
 * @file check_inclusion.cpp
 * @brief Check if one string's permutation is a substring of another.
 *
 * This program defines a function that checks whether any permutation 
 * of the string `s1` is present as a contiguous substring within the string `s2`.
 *
 * Problem Description:
 * --------------------
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 *
 * In simpler terms:
 *  - We need to find whether any rearrangement of `s1` exists as a substring in `s2`.
 *
 * Example 1:
 * ----------
 * Input:  s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains "ba", which is a permutation of "ab".
 *
 * Example 2:
 * ----------
 * Input:  s1 = "ab", s2 = "eidboaoo"
 * Output: false
 * Explanation: No substring of s2 is a permutation of s1.
 *
 * Approach:
 * ----------
 * 1. Count the frequency of each character in s1 (using an array of size 26 for lowercase letters).
 * 2. Slide a window of length equal to s1 over s2.
 * 3. For each window, count the character frequencies and compare with s1’s frequency array.
 * 4. If at any point they match, return true.
 * 5. If the entire string is traversed without a match, return false.
 *
 * Helper Function:
 * ----------------
 * - `isSame(f[], w[])`: Compares two frequency arrays (each of size 26).
 *   Returns true if they are identical.
 *
 * Time Complexity:  O(26 * (n - m))  ≈ O(n)
 *     where n = s2.length(), m = s1.length()
 * Space Complexity: O(1)
 *     (Only fixed-size arrays of size 26 are used)
 *
 * Constraints:
 * - 1 <= s1.length, s2.length <= 10^4
 * - s1 and s2 consist of lowercase English letters.
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
     * @brief Compares two frequency arrays of size 26.
     * 
     * @param f Frequency array for s1.
     * @param w Frequency array for current window in s2.
     * @return true if both arrays are identical, false otherwise.
     */
    bool isSame(int f[], int w[]) {
        for (int i = 0; i < 26; i++) {
            if (f[i] != w[i]) {
                return false;
            }
        }
        return true;
    }

    /**
     * @brief Checks if s2 contains any permutation of s1 as a substring.
     * 
     * @param s1 The source string whose permutation we are looking for.
     * @param s2 The target string in which we search for the permutation.
     * @return true if any permutation of s1 exists as a substring of s2.
     * @return false otherwise.
     */
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }

        int windowLength = s1.length();

        // Slide over s2
        for (int i = 0; i < s2.length(); i++) {
            int windowIndex = 0, idx = i;
            int windowFreq[26] = {0};

            // Build frequency for current window
            while (windowIndex < windowLength && idx < s2.length()) {
                windowFreq[s2[idx] - 'a']++;
                windowIndex++;
                idx++;
            }

            // Compare frequency arrays
            if (isSame(freq, windowFreq)) {
                return true;
            }
        }

        return false;
    }
};

// Example usage (optional for testing)
int main() {
    Solution solution;

    string s1 = "ab", s2 = "eidbaooo";
    cout << "Input: s1 = " << s1 << ", s2 = " << s2 << endl;
    cout << "Output: " << (solution.checkInclusion(s1, s2) ? "true" : "false") << endl;
    cout << "----------------------------" << endl;

    string s3 = "ab", s4 = "eidboaoo";
    cout << "Input: s1 = " << s3 << ", s2 = " << s4 << endl;
    cout << "Output: " << (solution.checkInclusion(s3, s4) ? "true" : "false") << endl;

    return 0;
}
