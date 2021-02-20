/**
 * @file
 *
 * @details
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also
in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.
Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.



Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]


Constraints:

1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
All the elements of arr2 are distinct.
Each arr2[i] is in arr1.
 */

#include <vector>
#include <iostream>

class Solution
{
public:
    static std::vector<int>
    relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2)
    {
        std::vector<int> result;

        for(const auto elem2 : arr2)
        {
            for(const auto elem1 : arr1)
            {
                if(elem1 == elem2)
                {
                    result.push_back(elem1);
                }
            }
        }
        for(const auto elemR : result)
        {
            arr1.erase(std::remove(arr1.begin(), arr1.end(), elemR), arr1.end());
        }
        std::sort(arr1.begin(), arr1.end());
        for(const auto elem1 : arr1)
        {
            result.push_back(elem1);
        }

        return result;
    }
};
int
main()
{
    std::cout << std::boolalpha << Solution::relativeSortArray(10);
    return 0;
}