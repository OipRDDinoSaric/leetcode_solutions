/**
 * @file
 * @details
On a table are N cards, with a positive integer printed on the front and back of each card (possibly
different).

We flip any number of cards, and after we choose one card.

If the number X on the back of the chosen card is not on the front of any card, then this number X
is good.

What is the smallest number that is good?  If no number is good, output 0.

Here, fronts[i] and backs[i] represent the number on the front and back of card i.

A flip swaps the front and back numbers, so the value on the front is now on the back and vice
versa.

Example:

Input: fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
Output: 2
Explanation: If we flip the second card, the fronts are [1,3,4,4,7] and the backs are [1,2,4,1,3].
We choose the second card, which has number 2 on the back, and it isn't on the front of any card, so
2 is good.


Note:

1 <= fronts.length == backs.length <= 1000.
1 <= fronts[i] <= 2000.
1 <= backs[i] <= 2000.

 * @see https://leetcode.com/problems/card-flipping-game/
 */
#include <vector>
#include <unordered_set>

class Solution
{
public:
    static constexpr int kMaximumCardValue {2000};
    static constexpr int kNoGoodNumber = 0;
    int
    flipgame(std::vector<int> fronts, std::vector<int> backs)
    {
        /* Value higher than any value in the deck. */
        int                     minValidInDeck {kMaximumCardValue + 1};
        std::unordered_set<int> invalidValues {};

        for (auto iii {0U}; iii < fronts.size(); iii++)
        {
            if(fronts[iii] == backs[iii])
            {
                invalidValues.insert(fronts[iii]);
            }
        }

        for (auto iii {0U}; iii < fronts.size(); iii++)
        {
            bool isFrontValid = false;
            bool isBackValid  = false;
            if (invalidValues.find(fronts[iii]) == invalidValues.end())
            {
                isFrontValid = true;
            }

            if (invalidValues.find(backs[iii]) == invalidValues.end())
            {
                isBackValid = true;
            }

            if (isFrontValid && isBackValid)
            {
                const int minOnCard {std::min(fronts[iii], backs[iii])};
                minValidInDeck = std::min(minOnCard, minValidInDeck);
            }
            else if (isFrontValid)
            {
                minValidInDeck = std::min(minValidInDeck, fronts[iii]);
            }
            else if (isBackValid)
            {
                minValidInDeck = std::min(minValidInDeck, backs[iii]);
            }
        }

        if (minValidInDeck > kMaximumCardValue)
        {
            return kNoGoodNumber;
        }
        else
        {
            return minValidInDeck;
        }
    }
};

int
main()
{
    Solution solution;
    return 0;
}