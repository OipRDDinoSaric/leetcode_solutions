/**
* @file
* @details
Given an array of distinct integers candidates and a target integer target, return a list of all
unique combinations of candidates where the chosen numbers sum to target. You may return the
combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are
unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is
less than 150 combinations for the given input.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
* @see https://leetcode.com/problems/merge-sorted-array/
*/

#include <vector>
#include <fmt/format.h>
#include <fmt/ranges.h>

class Solution
{
public:
    std::vector<std::vector<int>>
    combinationSum(const std::vector<int>& candidates, int target)
    {
        std::vector<std::vector<int>> validSumCombinations {};

        for (int iCandidate = 0; iCandidate < candidates.size(); iCandidate++)
        {
            std::vector<int> workingCombination {};
            recurse(candidates.cend(),
                    candidates.cbegin() + iCandidate,
                    0,
                    workingCombination,
                    target,
                    validSumCombinations);
        }

        return validSumCombinations;
    }

private:
    void
    recurse(const std::vector<int>::const_iterator candidatesSentinel,
            std::vector<int>::const_iterator       currentCandidate,
            int                                    currentSum,
            std::vector<int>&                      currentCombination,
            const int                              target,
            std::vector<std::vector<int>>&         validSumCombinations)
    {
        auto nextCandidate {currentCandidate};
        currentSum = currentSum + *currentCandidate;
        currentCombination.push_back(*currentCandidate);

        if (currentSum > target)
        {
            currentCombination.pop_back();
            return;
        }
        if (currentSum == target)
        {
            validSumCombinations.push_back(currentCombination);
            currentCombination.pop_back();
            return;
        }

        while (nextCandidate != candidatesSentinel)
        {
            recurse(candidatesSentinel,
                    nextCandidate,
                    currentSum,
                    currentCombination,
                    target,
                    validSumCombinations);
            nextCandidate++;
        }
        currentCombination.pop_back();
    }
};

int
main()
{
    Solution solution {};

    {
        std::vector candidates {2, 3, 6, 7};
        int         target {7};

        const auto result {solution.combinationSum(candidates, target)};
        fmt::println("");
        fmt::println("Result: {}", result);
    }

    return 0;
}
