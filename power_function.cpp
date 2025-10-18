/*
    Title: Implement Power Function (LeetCode Problem 50)
    Author: Mahad Iqbal
    Date: October 2025

    Description:
        Implement pow(x, n), which calculates x raised to the power n (i.e., xⁿ).

        The function handles both positive and negative exponents efficiently 
        using the fast exponentiation (binary exponentiation) technique.

    Problem Statement:
        Given a floating-point number x and an integer n,
        compute and return the value of xⁿ.

    Examples:
        Input:  x = 2.00000, n = 10
        Output: 1024.00000

        Input:  x = 2.10000, n = 3
        Output: 9.26100

        Input:  x = 2.00000, n = -2
        Output: 0.25000  (Explanation: 2⁻² = 1/(2²) = 1/4 = 0.25)

    Constraints:
        -100.0 < x < 100.0
        -2³¹ <= n <= 2³¹ - 1
        Either x is not zero, or n > 0
        -10⁴ <= xⁿ <= 10⁴

    Approach (Fast Exponentiation / Binary Exponentiation):
        → Use a long long type for the exponent to avoid overflow.
        → Handle negative exponents by taking the reciprocal of x (1/x)
          and negating n.
        → Repeatedly square x and halve n to compute power efficiently:
            - If n is odd, multiply ans by x.
            - Square x and divide n by 2 each iteration.
        → Runs in O(log n) time and O(1) space.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long binform = n;  // Convert to long long to handle INT_MIN
        double ans = 1.0;

        // Handle negative exponent
        if (binform < 0) {
            x = 1 / x;
            binform = -binform;
        }

        // Edge cases
        if (x == 0) return 0.0;
        if (x == 1.0 || n == 0) return 1.0;

        // Fast exponentiation
        while (binform > 0) {
            if (binform % 2 == 1) {
                ans *= x;          // Multiply result when exponent is odd
            }
            x *= x;                // Square the base
            binform /= 2;          // Divide exponent by 2
        }

        return ans;
    }
};

// Example usage (for local testing)
int main() {
    Solution s;

    cout << "Example 1: " << s.myPow(2.00000, 10) << endl; // 1024.00000
    cout << "Example 2: " << s.myPow(2.10000, 3) << endl;  // 9.26100
    cout << "Example 3: " << s.myPow(2.00000, -2) << endl; // 0.25000

    return 0;
}
