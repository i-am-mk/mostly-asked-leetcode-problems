// https://leetcode.com/problems/longest-repeating-character-replacement/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int left = 0;
        int maxFreq = 0;
        int result = 0;
        vector<int> charCount(26, 0);
        for(int right=0; right<n; right++)
        {
            int charIndex = s[right] - 'A';
            charCount[charIndex]++;
            maxFreq = max(maxFreq, charCount[charIndex]);
            int windowSize = right - left + 1;
            if(windowSize - maxFreq > k)
            {
                int leftCharIndex = s[left] - 'A';
                charCount[leftCharIndex]--;
                left++;
            }
            result = max(result, right - left + 1);
        }
        
        return result;
    }
};
