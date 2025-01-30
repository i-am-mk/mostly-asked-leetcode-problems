// https://leetcode.com/problems/valid-palindrome/
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left<right)
        {
            while(left<right && !isalnum(s[left]))
                left++;
            while(left<right && !isalnum(s[right]))
                right--;
            if(tolower(s[left])!=tolower(s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
};

// Approach:
// 1. Use two pointers: one at the start (`left`) and one at the end (`right`) of the string.
// 2. Skip over non-alphanumeric characters using `isalnum`.
// 3. Compare the characters at `left` and `right` after converting both to lowercase using `tolower`.
// 4. If the characters match, move the pointers inward (`left++`, `right--`).
// 5. If any characters do not match, return `false`.
// 6. Continue this until the two pointers cross each other, indicating the string is a valid palindrome.
// 7. Return `true` if no mismatches were found.

// Complexity Analysis
// Time Complexity: O(n), where n is the length of the string. We only iterate through the string once, performing constant-time operations for each character.
// Space Complexity: O(1), since we are using only two pointers and no extra data structures for storing the string or intermediate results.