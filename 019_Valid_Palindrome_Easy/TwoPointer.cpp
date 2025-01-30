// https://leetcode.com/problems/valid-palindrome/
class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        for(char c : s)
        {
            if(isalnum(c))
                filtered+=tolower(c);
        }

        int start = 0;
        int end = filtered.size() - 1;
        while(start<end)
        {
            if(filtered[start]!=filtered[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};

// Approach:
// 1. Iterate over the string and filter out non-alphanumeric characters while converting the rest to lowercase.
// 2. Use two pointers: one at the start (`start`) and one at the end (`end`) of the filtered string.
// 3. Compare the characters at `start` and `end`. If they don’t match, return `false`.
// 4. If the characters match, move both pointers towards the center and continue comparing.
// 5. If all characters match, return `true`.

// Complexity Analysis
// Time Complexity: O(n), where n is the length of the input string. We iterate through the string twice: once to filter and once to compare characters.
// Space Complexity: O(n), since we store a filtered version of the input string, which may be up to the same size as the original string.