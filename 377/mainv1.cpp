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
#include <unordered_map>

class Solution
{
public:
    int
    combinationSum4(std::vector<int>& nums, int newTarget)
    {
        startNums = {nums};
        target    = newTarget;
        return impl(0);
    }

private:
    std::vector<int> startNums;
    int              target;
    std::unordered_map<int, uint32_t> mapSumToCount;
    /**
     * @brief Recursive implementation of the combinations.
     *
     * @param[in] sum
     * @param[in] target
     *
     * @return Number of combinations that match under the root.
     */
    int
    impl(uint64_t sum)
    {
        if (sum > target)
        {
            return 0;
        }
        else if (sum == target)
        {
            return 1;
        }
        if(mapSumToCount.find(sum) != mapSumToCount.end())
        {
            return mapSumToCount[sum];
        }
        int count {0};
        for (const auto num : startNums)
        {
            count += impl(sum + num);
        }
        mapSumToCount[sum] = count;
        return count;
    }
};

int
main()
{
    Solution         solution {};
    std::vector<int> nums {1, 2, 3};
    std::cout << solution.combinationSum4(nums, 32);
    return 0;
}