/**
 * @file
 * @details
You are given an integer array nums where the largest integer is unique.

Determine whether the largest element in the array is at least twice as much as every other number
 in the array. If it is, return the index of the largest element, or return -1 otherwise.



Example 1:

Input: nums = [3,6,1,0]
Output: 1
Explanation: 6 is the largest integer. For every other number in the array x, 6 is at least twice as
 big as x.
The index of value 6 is 1, so we return 1.
Example 2:

       Input: nums = [1,2,3,4]
               Output: -1
                        Explanation: 4 is less than twice the value of 3, so we return -1.
               Constraints:
               2 <= nums.length <= 50
               0 <= nums[i] <= 100
                               The largest element in nums is unique.

 * @see https://leetcode.com/problems/largest-number-at-least-twice-of-others/
 */

#include <vector>
#include <print>
#include <cassert>
#include <algorithm>

class Solution
{
public:
    int
    dominantIndex(std::vector<int>& nums)
    {
        constexpr static int kDoesNotQualify {-1};

        if (nums.size() < 2)
        {
            return kDoesNotQualify;
        }

        int iLargest {};
        int iSecondLargest {};

        if (nums[0] > nums[1])
        {
            iLargest       = 0;
            iSecondLargest = 1;
        }
        else
        {
            iLargest       = 1;
            iSecondLargest = 0;
        }

        for (int iNum = 2; iNum < nums.size(); ++iNum)
        {
            int currentNumber {nums[iNum]};
            int largest {nums[iLargest]};
            int secondLargest {nums[iSecondLargest]};

            if (currentNumber > largest)
            {
                iSecondLargest = iLargest;
                iLargest = iNum;
            }
            else if (currentNumber > secondLargest)
            {
                iSecondLargest = iNum;
            }
        }

        return (nums[iLargest] >= (2 * nums[iSecondLargest])) ? iLargest : kDoesNotQualify;
    }
};

int
main()
{
    Solution solution {};
    {
        std::vector<int> candidate1 {3, 6, 1, 0};

        int dominantIndexValue {solution.dominantIndex(candidate1)};

        std::println("1 == {}.", dominantIndexValue);
    }

    {
        std::vector<int> candidate1 {1, 2, 3, 4};

        int dominantIndexValue {solution.dominantIndex(candidate1)};

        std::println("-1 == {}", dominantIndexValue);
    }

    {
        std::vector<int> candidate1 {1, 2, 10, 4};

        int dominantIndexValue {solution.dominantIndex(candidate1)};

        std::println("2 == {}", dominantIndexValue);
    }

    {
        std::vector<int> candidate1 {1, 2, 10, 50};

        int dominantIndexValue {solution.dominantIndex(candidate1)};

        std::println("3 == {}", dominantIndexValue);
    }

    {
        std::vector<int> candidate1 {1, 7};

        int dominantIndexValue {solution.dominantIndex(candidate1)};

        std::println("1 == {}", dominantIndexValue);
    }

    {
        std::vector<int> candidate1 {7, 1};

        int dominantIndexValue {solution.dominantIndex(candidate1)};

        std::println("0 == {}", dominantIndexValue);
    }

    {
        std::vector<int> candidate1 {0, 1};

        int dominantIndexValue {solution.dominantIndex(candidate1)};

        std::println("1 == {}", dominantIndexValue);
    }

    {
        std::vector<int> candidate1 {7, 8};

        int dominantIndexValue {solution.dominantIndex(candidate1)};

        std::println("-1 == {}", dominantIndexValue);
    }

    {
        std::vector<int> candidate1 {8, 5};

        int dominantIndexValue {solution.dominantIndex(candidate1)};

        std::println("-1 == {}", dominantIndexValue);
    }

    return 0;
}