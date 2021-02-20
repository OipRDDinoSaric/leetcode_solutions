/**
 * @file
 *
 * @details
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the
digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid
inputs such as "abc" or "zerone" are not permitted. Input length is less than 50,000. Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
 */
#include <vector>
#include <string>
#include <iostream>
#include <set>

class Solution
{
public:
    constexpr static size_t kNumOfDigits = 10U;

    static std::string
    originalDigits(std::string strIn)
    {
        std::multiset<size_t> multiDigits;
        bool                  isADigitFound;
        do
        {
            isADigitFound = false;
            for (size_t digit = 0U; digit < kNumOfDigits; digit++)
            {
                if (doesContainDigit(strIn, digit))
                {
                    isADigitFound = true;
                    multiDigits.insert(digit);
                }
            }
        }
        while (isADigitFound);
        std::string result;

        for (const auto elem : multiDigits)
        {
            result += std::to_string(elem);
        }
        return result;
    }

private:
    /**
     * @breif Check whether the string contains the word for digit.
     *
     * @param[in] strIn String to check. Characters of the number will be removed from the string.
     * @param[in] digit Digit for which to check. Valid digit is assumed.
     *
     * @return true if contains the digit, false otherwise.
     */
    static bool
    doesContainDigit(std::string& strIn, size_t digit)
    {
        std::string& strDigit    = digitToWord[digit];
        std::string  localStrIn  = strIn;
        bool         isContained = true;

        for (const auto letter : strDigit)
        {
            const auto posLetter = localStrIn.find(letter);
            if (posLetter == std::string::npos)
            {
                isContained = false;
                break;
            }
            localStrIn.erase(posLetter, 1);
        }

        if (isContained)
        {
            strIn = localStrIn;
        }

        return isContained;
    }

    static std::vector<std::string> digitToWord;
};

std::vector<std::string> Solution::digitToWord {"zero",
                                                "one",
                                                "two",
                                                "three",
                                                "four",
                                                "five",
                                                "six",
                                                "seven",
                                                "eight",
                                                "nine"};
int
main()
{

    return 0;
}