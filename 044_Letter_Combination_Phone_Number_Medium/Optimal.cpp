// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    void makeLetterCombination(string digits, int index, string mapping[], string output, vector<string>& ans)
    {
        if(index==digits.length())
        {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];
        for(int i=0; i<value.length(); i++)
        {
            output.push_back(value[i]);
            makeLetterCombination(digits, index+1, mapping, output, ans);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int index=0;
        string output;
        vector<string> ans;
        string mapping[10] = {"","", "abc", "def","ghi", "jkl", "mno","pqrs", "tuv", "wxyz"};
        
        if(digits.size()<=0)
            return ans;
        makeLetterCombination(digits, index, mapping, output, ans);
        return ans;
    }
};