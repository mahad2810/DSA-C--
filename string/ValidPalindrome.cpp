/*
----------------------------------------
    Problem: Valid Palindrome
----------------------------------------
A phrase is a palindrome if, after converting all uppercase 
letters into lowercase letters and removing all non-alphanumeric 
characters, it reads the same forward and backward.

Alphanumeric characters include letters and numbers.

----------------------------------------
Example 1:
Input:  s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input:  s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input:  s = " "
Output: true
Explanation: After cleaning, the string is empty. 
An empty string is considered a palindrome.

----------------------------------------
Constraints:
1 <= s.length <= 2 * 10^5
s consists only of printable ASCII characters.
----------------------------------------
Approach:
----------------------------------------
1. Use two-pointer technique:
   - Initialize `start` = 0, `end` = s.length() - 1.
2. Skip all non-alphanumeric characters using `isalnum()`.
3. Compare lowercase versions of valid characters.
4. If any mismatch occurs → return false.
5. If loop completes → return true.

Time Complexity:  O(n)
Space Complexity: O(1)
----------------------------------------
*/

#include <iostream>
#include <string>
#include <cctype>   // For isalnum() and tolower()

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;

        while (start < end) {
            // Skip non-alphanumeric characters
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }

            // Compare lowercase versions of both characters
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
};

// -----------------------------
// Example main() for testing
// -----------------------------
int main() {
    Solution obj;
    
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";

    cout << boolalpha;  // Print "true"/"false" instead of 1/0
    cout << "Input: \"" << s1 << "\" -> Output: " << obj.isPalindrome(s1) << endl;
    cout << "Input: \"" << s2 << "\" -> Output: " << obj.isPalindrome(s2) << endl;
    cout << "Input: \"" << s3 << "\" -> Output: " << obj.isPalindrome(s3) << endl;

    return 0;
}
