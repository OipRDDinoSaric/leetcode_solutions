/**
 * @file
 *
 * @details
Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some
(can be none) of the characters without disturbing the relative positions of the remaining
characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by
one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false

Constraints:

0 <= s.length <= 100
0 <= t.length <= 10^4
Both strings consists only of lowercase characters.

 * @see https://leetcode.com/problems/is-subsequence/
 */

#include <string>
#include <iostream>

class Solution
{
public:
    bool
    isSubsequence(std::string substring, std::string sourceString)
    {
        constexpr size_t kStartLetterPos = -1;
        bool isSubsequenceVar = true;
        size_t letterPos = kStartLetterPos;

        for(const auto &letter : substring)
        {
            letterPos = sourceString.find(letter, letterPos + 1);
            if(std::string::npos == letterPos)
            {
                isSubsequenceVar = false;
            }
        }

        return isSubsequenceVar;
    }
};

int
main()
{
    Solution solution;

    std::cout << std::boolalpha;
    std::cout << solution.isSubsequence("hello", "hekkcxlvdvlvafsfofvs") << '\n';
    std::cout << solution.isSubsequence("dino", "jdivnddijvndjoinvaos") << '\n';
    std::cout << solution.isSubsequence("axc", "ahbgdc") << '\n';
    std::cout << solution.isSubsequence("abs", "") << '\n';
    std::cout << solution.isSubsequence("", "fff") << '\n';

    return 0;
}