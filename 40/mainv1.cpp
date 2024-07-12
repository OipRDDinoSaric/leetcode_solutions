/**
* @file
* @details
Given a collection of candidate numbers (candidates) and a target number (target), find all unique
 combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.



       Example 1:

        Input: candidates = [10,1,2,7,6,1,5], target = 8
                Output:
        [
            [1,1,6],
            [1,2,5],
            [1,7],
            [2,6]
        ]
        Example 2:

        Input: candidates = [2,5,2,1,2], target = 5
                         Output:
        [
            [1,2,2],
            [5]
        ]


        Constraints:

        1 <= candidates.length <= 100
        1 <= candidates[i] <= 50
        1 <= target <= 30
* @see https://leetcode.com/problems/combination-sum-ii/
*/

#include <vector>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>>
    combinationSum2(std::vector<int>& candidates, int target)
    {
        std::vector<std::vector<int>> validSumCombinations {};
        std::vector<int>              currentCombination {};

        std::ranges::sort(candidates);

        recurse(target,
                validSumCombinations,
                candidates.end(),
                candidates.begin(),
                0,
                currentCombination);

        std::ranges::sort(validSumCombinations);
        std::ranges::for_each(validSumCombinations,
                              [](auto combination)
                              {
                                  std::ranges::sort(combination);
                              });
        validSumCombinations.erase(std::unique(validSumCombinations.begin(),
                                               validSumCombinations.end()),
                                   validSumCombinations.end());

        return validSumCombinations;
    }

private:
    void
    recurse(const int                              target,
            std::vector<std::vector<int>>&         validSumCombinations,
            const std::vector<int>::const_iterator candidatesSentinel,
            std::vector<int>::const_iterator       currentCandidate,
            int                                    currentSum,
            std::vector<int>&                      currentCombination)
    {
        if (currentSum == target)
        {
            validSumCombinations.push_back(currentCombination);
            return;
        }
        if (currentSum > target)
        {
            return;
        }
        if (currentCandidate == candidatesSentinel)
        {
            return;
        }

        currentCombination.push_back(*currentCandidate);
        const auto nextCandidate {std::next(currentCandidate)};
        const auto nextSum {currentSum + *currentCandidate};

        recurse(target,
                validSumCombinations,
                candidatesSentinel,
                nextCandidate,
                nextSum,
                currentCombination);

        currentCombination.pop_back();

        auto backtrackedCandidate {currentCandidate};
        while ((backtrackedCandidate != candidatesSentinel) &&
               (*currentCandidate == *backtrackedCandidate))
        {
            backtrackedCandidate++;
        }
        const auto backtrackedSum {currentSum};
        recurse(target,
                validSumCombinations,
                candidatesSentinel,
                backtrackedCandidate,
                backtrackedSum,
                currentCombination);
    }
};

int
main()
{
    Solution solution {};

    {
        std::vector candidates {10, 1, 2, 7, 6, 1, 5};
        int         target {8};

        const auto result {solution.combinationSum2(candidates, target)};
        fmt::println("");
        fmt::println("Result: {}", result);
    }

    return 0;
}
