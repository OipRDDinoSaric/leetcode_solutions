/**
 * @file
 *
 * @details
Given an integer array nums where every element appears three times except for one, which appears
exactly once. Find the single element and return it.

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99


Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.


Follow up: Your algorithm should have a linear runtime complexity. Could you implement it without
using extra memory?

 * @see https://leetcode.com/problems/single-number-ii/
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
    int
    singleNumber(std::vector<int>& nums)
    {
        std::unordered_map<int, int> numOfOccurences;
        for (const auto& num : nums)
        {
            if (numOfOccurences.end() == numOfOccurences.find(num))
            {
                numOfOccurences[num] = 1;
            }
            else
            {
                numOfOccurences[num]++;
            }
        }

        return std::find_if(numOfOccurences.begin(),
                            numOfOccurences.end(),
                            [](const auto& pair)
                            {
                                return pair.second == 1;
                            })
        ->first;
    }
};

int
main()
{
    Solution         solution;
    std::vector<int> nums1 {2, 2, 3, 2};
    std::vector<int> nums2 {3, 3, 3, 2};
    std::vector<int> nums3 {1, 1, 0, 0, 1, 0, 9};
    std::vector<int> nums4 {0, 1, 2, 1, 0, 0, 1};

    std::cout << solution.singleNumber(nums1) << '\n';
    std::cout << solution.singleNumber(nums2) << '\n';
    std::cout << solution.singleNumber(nums3) << '\n';
    std::cout << solution.singleNumber(nums4) << '\n';

    return 0;
}