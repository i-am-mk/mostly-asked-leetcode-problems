// https://leetcode.com/problems/fizz-buzz/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for(int i=1; i<=n; i++)
        {
            answer.push_back(
                (i % 15 == 0) ? "FizzBuzz" :
                (i % 5 == 0)  ? "Buzz" :
                (i % 3 == 0)  ? "Fizz" :
                to_string(i)
            );
        }
        return answer;
    }
};