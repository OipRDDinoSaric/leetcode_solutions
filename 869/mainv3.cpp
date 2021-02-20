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

#include <iostream>
#include <array>

class Solution
{
public:
    constexpr static size_t kNumOfPowsOf2 = 30U;
    constexpr static size_t kNumOfDigits  = 10U;

    static bool
    reorderedPowerOf2(int num)
    {
        const auto numOfDigitsInNum  = getNumOfDigits(num);
        bool       isSameNumOfDigits = true;

        for (const auto& numOfDigits : numberOfDigitsInPowersOf2)
        {
            isSameNumOfDigits = true;
            for (size_t iDigit = 0U; iDigit < kNumOfDigits; iDigit++)
            {
                if (numOfDigits[iDigit] != numOfDigitsInNum[iDigit])
                {
                    isSameNumOfDigits = false;
                    break;
                }
            }
            if (isSameNumOfDigits)
            {
                break;
            }
        }

        return isSameNumOfDigits;
    }

#if 0
    /**
     * @brief Returns all powers of 2 lower than the limit.
     *
     * @note Used for getting the array of powers of 2.
     *
     * @return All powers of 2 lower than the limit.
     */
    static std::string
    getAllPowersOf2(long long int limit)
    {
        std::string result;
        result += '{';
        for (long long int iii = 1; iii <= limit; iii *= 2)
        {
            result += std::to_string(iii);
            result += ", ";
        }
        result.erase(result.end() - 1);
        result.erase(result.end() - 1);
        result += '}';
        return result;
    }

    /**
     * @brief Returns the number of individual digits in powers of two from 0 to 10^9.
     *
     * @return The number of individual digits in powers of two from 0 to 10^9.
     */
    static std::array<std::array<int, kNumOfDigits>, kNumOfPowsOf2>
    getNumOfDigitsInPowersOf2()
    {
        std::array<std::array<int, kNumOfDigits>, kNumOfPowsOf2> digits {0};

        for (size_t iPows = 0; iPows < kNumOfPowsOf2; iPows++)
        {
            digits[iPows] = getNumOfDigits(powersOf2[iPows]);
        }

        return digits;
    }
#endif

    /**
     * @brief Gets the number of individual digits in a number.
     *
     * @param[in] num Number to check.
     *
     * @return Array with the number of individual digits.
     */
    static std::array<int, kNumOfDigits>
    getNumOfDigits(int num)
    {
        std::array<int, kNumOfDigits> count {0};

        do
        {
            count[num % 10]++;
            num /= 10;
        }
        while (num);

        return count;
    }

private:
#if 0
    constexpr static std::array<int, kNumOfPowsOf2> powersOf2 {
    1,        2,        4,        8,         16,        32,       64,      128,
    256,      512,      1024,     2048,      4096,      8192,     16384,   32768,
    65536,    131072,   262144,   524288,    1048576,   2097152,  4194304, 8388608,
    16777216, 33554432, 67108864, 134217728, 268435456, 536870912};
#endif

    constexpr static std::array<std::array<int, kNumOfDigits>, kNumOfPowsOf2>
    numberOfDigitsInPowersOf2 {{{0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                                {0, 1, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0, 0, 1, 0},
                                {0, 0, 1, 0, 0, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
                                {1, 1, 1, 0, 1, 0, 0, 0, 0, 0}, {1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                                {1, 0, 0, 0, 1, 0, 1, 0, 0, 1}, {0, 1, 1, 0, 0, 0, 0, 0, 1, 1},
                                {0, 1, 0, 1, 1, 0, 1, 0, 1, 0}, {0, 0, 1, 1, 0, 0, 1, 1, 1, 0},
                                {0, 0, 0, 1, 0, 2, 2, 0, 0, 0}, {1, 2, 1, 1, 0, 0, 0, 1, 0, 0},
                                {0, 1, 2, 0, 2, 0, 1, 0, 0, 0}, {0, 0, 2, 0, 1, 1, 0, 0, 2, 0},
                                {1, 1, 0, 0, 1, 1, 1, 1, 1, 0}, {1, 1, 2, 0, 0, 1, 0, 1, 0, 1},
                                {1, 1, 0, 1, 3, 0, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 1, 0, 4, 0},
                                {0, 2, 1, 0, 0, 0, 2, 3, 0, 0}, {0, 0, 1, 3, 2, 2, 0, 0, 0, 0},
                                {1, 1, 0, 0, 1, 0, 2, 1, 2, 0}, {0, 2, 2, 1, 1, 0, 0, 2, 1, 0},
                                {0, 0, 1, 1, 2, 2, 2, 0, 1, 0}, {1, 1, 1, 1, 0, 1, 1, 1, 1, 1}}};
};

int
main()
{
    std::cout << std::boolalpha << '\n'
              << Solution::reorderedPowerOf2(10) << '\n'
              << Solution::reorderedPowerOf2(268435457) << '\n'
              << Solution::reorderedPowerOf2(53687912) << '\n'
              << Solution::reorderedPowerOf2(268435456) << '\n'
              << Solution::reorderedPowerOf2(536870912);

    return 0;
}
