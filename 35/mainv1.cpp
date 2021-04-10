/**
 * @file
 *
 * @details
Given a sorted array of distinct integers and a target value, return the index if the target is
found. If not, return the index where it would be if it were inserted in order.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
Example 4:

Input: nums = [1,3,5,6], target = 0
Output: 0
Example 5:

Input: nums = [1], target = 0
Output: 0


Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
 */

#include <vector>
#include <numeric>
#include <iostream>
#include <unordered_map>
#include <set>

class Solution
{
public:
    static int
    searchInsert(std::vector<int>& nums, int target)
    {
        std::set<int> numsSet{nums.begin(), nums.end()};
        const auto iter = numsSet.find(target);
        if(numsSet.end() == iter)
        {
            numsSet.insert(target);

            return std::distance(numsSet.begin(), numsSet.find(target));
        }
        else
        {
            return std::distance(numsSet.begin(), iter);
        }
    }
};

int
main()
{
    std::vector<int> nums {1, 3, 5, 6};
    std::cout << Solution::searchInsert(nums, 5);
    return 0;
}