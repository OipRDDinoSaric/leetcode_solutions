/**
 * @file
 *
 * @details
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and
each integer appears once or twice, return an array of all the integers that appears twice.

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []


Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.

Follow up: Could you do it without extra space and in O(n) runtime?
 */

#include <vector>
#include <numeric>
#include <iostream>
#include <unordered_map>
#include <memory>

class Solution
{
public:
    static std::vector<int>
    findDuplicates(std::vector<int>& nums)
    {
        std::vector<bool> isSeen(nums.size() + 1, false);
        std::vector<int> duplicates;

        for(const auto& num : nums)
        {
            if(isSeen[num])
            {
                duplicates.push_back(num);
            }
            else
            {
                isSeen[num] = true;
            }
        }

        return duplicates;
    }
};

int
main()
{
    return 0;
}