/**
 * @file
 *
 * @details
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"


Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
 */

#include <vector>
#include <numeric>
#include <iostream>
#include <unordered_map>

class Solution
{
public:
    static std::string
    reverseVowels(std::string str)
    {
        constexpr std::string_view vowels {"aeiouAEIOU"};
        size_t           iStr {0U};
        size_t           jStr {str.size() - 1};

        while (true)
        {
            iStr = str.find_first_of(vowels, iStr);
            jStr = str.find_last_of(vowels, jStr);
            if ((std::string::npos == iStr) || (std::string::npos == jStr) || (iStr >= jStr))
            {
                break;
            }
            std::swap(str[iStr], str[jStr]);
            iStr++;
            jStr--;
        }
        return str;
    }
};

int
main()
{
    std::cout << Solution::reverseVowels("aeiou");
    return 0;
}