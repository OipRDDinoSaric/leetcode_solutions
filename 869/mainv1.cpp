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

/*
 * Scratchpad:
 * a)
 * 1234
 * num of digits: 4
 * num of alterations = (num of digits - 1) * num of digits + 1 - duplicates / 2
 *                    = digits^2 - digits + 1 - duplicates / 2
 *
 * Move pos 0 to every position:
 * 2134 a - duplicate
 * 2314 b
 * 2341 c
 *
 * Move pos 1 to every position:
 * 1324 d - duplicate
 * 1342 e
 * 2134 a - duplicate
 *
 * Move pos 2 to every position:
 * 3124 f
 * 1324 d - duplicate
 * 1243 g - duplicate
 *
 * Move pos 3 to every position:
 * 4123 h
 * 1423 i
 * 1243 g - duplicate
 *
 * b)
 * How to extract a digit from integer?
 * num = 543210, extract digit in position posDigit = 2.
 *
 * digit = num / 10^posDigit = 5432
 * digit = num % 10 = 2
 * => digit = (num / 10^posDigit) % 10
 */

#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
    static bool
    reorderedPowerOf2(int num)
    {
        auto vecOfDigits = toVectorOfDigits(num);
        std::sort(vecOfDigits.begin(), vecOfDigits.end());
        do
        {
            if (vecOfDigits[0] != 0)
            {
                const auto permutatedNum = toNum(vecOfDigits);
                if(isPowOf2(permutatedNum))
                {
                    return true;
                }
            }
        }
        while (std::next_permutation(vecOfDigits.begin(), vecOfDigits.end()));

        return false;
    }

private:
    static std::vector<int>
    toVectorOfDigits(const int num)
    {
        std::vector<int> vec;
        for (size_t posNum = 0; posNum < getNumOfDigits(num); posNum++)
        {
            vec.push_back(getDigit(num, posNum));
        }
        return std::move(vec);
    }

    static int
    toNum(const std::vector<int>& vec)
    {
        int num = 0;
        for (size_t iVec = 0; iVec < vec.size(); iVec++)
        {
            num += (static_cast<int>(pow(10, iVec)) * vec[vec.size() - iVec - 1]);
        }
        return num;
    }

    static bool
    isPowOf2(int num)
    {
        auto logOfNum = log2(num);
        if (logOfNum == floor(logOfNum))
        {
            return true;
        }
        return false;
    }

    static size_t
    getNumOfDigits(int num)
    {
        size_t numOfDigits = 0;

        do
        {
            numOfDigits++;
            num /= 10U;
        }
        while (num != 0U);

        return numOfDigits;
    }

    /**
     * @brief Swaps digits in a number. Position 0 denotes the digit in place of 10^0, e.g., 1234
     * that is the number 4, position 1 will denote 3...
     *
     * @param[in] posDigitOne First digit to replace in base 10.
     * @param[in] posDigitTwo Second digit to replace in base 10.
     *
     * @return Number with the digits swapped.
     */
    static int
    swapDigits(int num, size_t posDigitOne, size_t posDigitTwo)
    {
        auto digitOne = getDigit(num, posDigitOne);
        auto digitTwo = getDigit(num, posDigitTwo);

        /* Remove digits from num. */
        num -= (static_cast<int>(pow(10, posDigitOne)) * digitOne);
        num -= (static_cast<int>(pow(10, posDigitTwo)) * digitTwo);

        /* Add digits in the new order. */
        num += (static_cast<int>(pow(10, posDigitOne)) * digitTwo);
        num += (static_cast<int>(pow(10, posDigitTwo)) * digitOne);

        return num;
    }

    /**
     * @brief Retruns the digit of the number. Position 0 denotes the digit in place of 10^0, e.g.,
     * 1234 that is the number 4, position 1 will denote 3...
     *
     * @note If the position is greater than the number of digits, unspecified behavior.
     *
     * @param[in] num
     * @param[in] posDigit
     *
     * @return Digit in position posDigit.
     */
    static int
    getDigit(int num, size_t posDigit)
    {
        auto digit = (num / static_cast<int>(pow(10, posDigit))) % 10U;
        return digit;
    }
};

int
main()
{
    std::cout << std::boolalpha << Solution::reorderedPowerOf2(10);
    return 0;
}