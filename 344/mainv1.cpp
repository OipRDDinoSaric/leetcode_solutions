/**
 * @file
 *
 * @details
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array
in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.



Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 */
#include <vector>
#include <iostream>

class Solution
{
public:
    void
    reverseString(std::vector<char>& str)
    {
        for (size_t iStr = 0; iStr < str.size() / 2; iStr++)
        {
            std::swap(str[iStr], str[str.size() - iStr - 1]);
        }
    }

    void
    printString(std::vector<char>& str)
    {
        for (const auto& elem : str)
        {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }
};
int
main()
{
    Solution          solution;
    std::vector<char> data1 {'a', 'b', 'c', 'd', 'e'};
    std::vector<char> data2 {'a', 'b', 'c', 'd', 'e', 'f'};

    solution.reverseString(data1);
    solution.reverseString(data2);

    solution.printString(data1);
    solution.printString(data2);

    return 0;
}