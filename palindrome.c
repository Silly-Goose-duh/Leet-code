#include <limits.h> // For INT_MAX and INT_MIN

bool isPalindrome(int x) {
    if (x < 0) return false; // Negative numbers are not palindromes
    int d;
    long long rev = 0; // Use long long to handle large values
    int temp = x;

    while (x != 0) {
        d = x % 10;

        // Check for overflow before updating rev
        if (rev > (INT_MAX - d) / 10) {
            return false; // Overflow detected, not a valid palindrome
        }

        rev = (rev * 10) + d;
        x = x / 10;
    }

    return temp == rev;
}
