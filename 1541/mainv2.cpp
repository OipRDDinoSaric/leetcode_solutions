/**
 * @file
 *
 * @details
Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is
balanced if:

Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
In other words, we treat '(' as openning parenthesis and '))' as closing parenthesis.

For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not
balanced.

You can insert the characters '(' and ')' at any position of the string to balance it if needed.

Return the minimum number of insertions needed to make s balanced.

Example 1:

Input: s = "(()))"
Output: 1
Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching. We need
to to add one more ')' at the end of the string to be "(())))" which is balanced. Example 2:

Input: s = "())"
Output: 0
Explanation: The string is already balanced.
Example 3:

Input: s = "))())("
Output: 3
Explanation: Add '(' to match the first '))', Add '))' to match the last '('.
Example 4:

Input: s = "(((((("
Output: 12
Explanation: Add 12 ')' to balance the string.
Example 5:

Input: s = ")))))))"
Output: 5
Explanation: Add 4 '(' at the beginning of the string and one ')' at the end. The string becomes
"(((())))))))".

Constraints:

1 <= s.length <= 10^5
s consists of '(' and ')' only.
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>

class Solution
{
public:
    static int
    minInsertions(std::string str)
    {
        int    numOfInsertions {0};
        size_t numOfPrecedingOpens {0UL};
        /* Unprocessed means it hasn't been added to numOfInsertions. */
        bool isLastUnprocessedClose {false};

        for (size_t iStr {0UL}; iStr < str.size(); ++iStr)
        {
            if ('(' == str[iStr])
            {
                if (isLastUnprocessedClose)
                {
                    if (numOfPrecedingOpens > 0)
                    {
                        numOfPrecedingOpens--;
                        /* Needed for the missing consecutive ')'. */
                        numOfInsertions++;
                    }
                    else
                    {
                        /* No preceding open brackets and consecutive close bracket. */
                        numOfInsertions += 2;
                    }
                }

                numOfPrecedingOpens++;
                isLastUnprocessedClose = false;
            }
            else
            {
                if (isLastUnprocessedClose)
                {
                    isLastUnprocessedClose = false;
                    if (numOfPrecedingOpens > 0)
                    {
                        /* Valid pair "())". */
                        numOfPrecedingOpens--;
                    }
                    else
                    {
                        /* No preceding open brackets, but two consecutive close brackets. */
                        numOfInsertions++;
                    }
                }
                else
                {
                    isLastUnprocessedClose = true;
                }
            }
        }

        if (isLastUnprocessedClose)
        {
            if (numOfPrecedingOpens > 0)
            {
                numOfPrecedingOpens--;
                /* Needed for the missing consecutive ')'. */
                numOfInsertions++;
            }
            else
            {
                /* No preceding open brackets and consecutive close bracket. */
                numOfInsertions += 2;
            }
        }

        numOfInsertions += static_cast<int>(numOfPrecedingOpens * 2);
        return numOfInsertions;
    }
};

int
main()
{
    std::cout << Solution::minInsertions(")))()))))))((()))())))()))))()))()())((()()))()(())()())("
                                         ")()))))))()()((()))(");
    return 0;
}