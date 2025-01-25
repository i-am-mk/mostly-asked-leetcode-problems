// https://leetcode.com/problems/longest-repeating-character-replacement/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            char hash[26] = {0};
            int maxFreq = 0;
            for (int j = i; j < n; j++) {
                hash[s[j] - 'A']++;
                maxFreq = max(maxFreq, (int)hash[s[j] - 'A']);
                int changes = (j - i + 1) - maxFreq;
                if (changes <= k)
                    maxLen = max(maxLen, j - i + 1);
                else
                    break;
            }
        }
        return maxLen;
    }
};
