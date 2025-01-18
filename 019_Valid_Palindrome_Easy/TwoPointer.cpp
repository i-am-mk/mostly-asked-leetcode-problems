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