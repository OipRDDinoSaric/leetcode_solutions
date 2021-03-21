/**
 * @file
 *
 * @details
Given an array of distinct integers nums and a target integer target, return the number of possible
combinations that add up to target.

The answer is guaranteed to fit in a 32-bit integer.



Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:

Input: nums = [9], target = 3
Output: 0


Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 1000
All the elements of nums are unique.
1 <= target <= 1000
 */

#include <vector>
#include <numeric>
#include <iostream>
#include <map>

class Solution
{
public:
    int
    combinationSum4(std::vector<int>& nums, int target)
    {
        std::vector<uint32_t> count(target + 1, 0);
        count[0] = 1;
        std::sort(nums.begin(), nums.end());
        for (int iCount = 1U; iCount < count.size(); iCount++)
        {
            for (const auto num : nums)
            {
                if ((iCount - num) < 0)
                {
                    break;
                }
                count[iCount] += count[iCount - num];
            }
        }
        return count[target];
    }
};

int
main()
{
    Solution         solution {};
    std::vector<int> nums {3, 1, 2};
    std::cout << solution.combinationSum4(nums, 4) << '\n';
    return 0;
}