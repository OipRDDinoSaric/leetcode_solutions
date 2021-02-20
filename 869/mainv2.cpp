/**
 * @file
 *
 * @details
Starting with a positive integer N, we reorder the digits in any order (including the original
order) such that the leading digit is not zero.

Return true if and only if we can do this in a way such that the resulting number is a power of 2.

Example 1:

Input: 1
Output: true
Example 2:

Input: 10
Output: false
Example 3:

Input: 16
Output: true
Example 4:

Input: 24
Output: false
Example 5:

Input: 46
Output: true

Note:

1 <= N <= 10^9
 */

#include <cmath>
#include <iostream>

class Solution
{
public:
    static bool
    reorderedPowerOf2(int num)
    {
        auto numStr = std::to_string(num);
        std::sort(numStr.begin(), numStr.end());
        do
        {
            if (numStr[0] != '0')
            {
                auto permutatedNum = atoi(numStr.c_str());
                auto logNum = std::log2(permutatedNum);
                if(logNum == std::floor(logNum))
                {
                    return true;
                }
            }
        }
        while (std::next_permutation(numStr.begin(), numStr.end()));

        return false;
    }
};

int
main()
{
    std::cout << std::boolalpha << Solution::reorderedPowerOf2(125);
    return 0;
}