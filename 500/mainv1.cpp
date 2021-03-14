/**
 * @file
 * @details
Given an array of strings words, return the words that can be typed using letters of the alphabet on
only one row of American keyboard like the image below.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".



Example 1:

Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]
Example 2:

Input: words = ["omk"]
Output: []
Example 3:

Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]


Constraints:

1 <= words.length <= 20
1 <= words[i].length <= 100
words[i] consists of English letters (both lowercase and uppercase).
 * @see https://leetcode.com/problems/keyboard-row/
 */

#include <array>
#include <algorithm>
#include <cctype>
#include <string_view>
#include <vector>
#include <iostream>

class Solution
{
public:
    std::vector<std::string>
    findWords(std::vector<std::string>& words)
    {
        constexpr uint8_t                             kNumOfRows {3};
        constexpr std::array<const char*, kNumOfRows> rows {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

        auto iterWord {words.begin()};
        while (iterWord != words.end())
        {
            /* Define the row. */
            const auto       firstLetter = static_cast<char>(std::tolower((*iterWord)[0]));
            std::string_view currRowView;
            for (const auto row : rows)
            {
                currRowView = row;
                if (currRowView.find(firstLetter) != std::string_view::npos)
                {
                    break;
                }
            }

            /* Check every other letters. */
            bool isToBeErased {false};
            for (auto iterLetter {iterWord->begin() + 1}; iterLetter < iterWord->end();
                 iterLetter++)
            {
                if (currRowView.find(std::tolower(*iterLetter)) == std::string_view::npos)
                {
                    isToBeErased = true;
                    break;
                }
            }

            /* Erase if the word is not valid. */
            if (isToBeErased)
            {
                words.erase(iterWord);
            }
            else
            {
                iterWord++;
            }
        }

        return words;
    }
};

int
main()
{
    Solution solution;
    std::vector<std::string>
    words {"Hello", "AlAska", "Dad", "Peace", "omk", "ssddsajdfh", "ed", "k"};

    for (const auto& word : solution.findWords(words))
    {
        std::cout << word << '\n';
    }

    return 0;
}