/**
 * @file
 *
 * @details
Given a date, return the corresponding day of the week for that date.

The input is given as three integers representing the day, month and year respectively.

Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday",
"Thursday", "Friday", "Saturday"}.



Example 1:

Input: day = 31, month = 8, year = 2019
Output: "Saturday"
Example 2:

Input: day = 18, month = 7, year = 1999
Output: "Sunday"
Example 3:

Input: day = 15, month = 8, year = 1993
Output: "Sunday"


Constraints:

The given dates are valid dates between the years 1971 and 2100.
 *
 * @see https://leetcode.com/problems/day-of-the-week/
 */

#include <string>
#include <vector>
#include <iostream>

#include <chrono>
#include <ctime>
#include <cassert>

class Solution
{
public:
    std::vector<std::string> days =
    {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    std::string
    dayOfTheWeek(int day, int month, int year)
    {
        assert(day > 0 && day < 32);
        assert(month > 0 && month < 13);
        assert(year > 1970 && year < 2101);

        /* 1900 as that is the base year. */
        std::tm timeIn = {0, 0, 0, day, month - 1, year - 1900};

        std::time_t timeReal = std::mktime(&timeIn);

        const std::tm* timeReturn = std::localtime(&timeReal);

        return days[timeReturn->tm_wday];
    }
};

int
main()
{
    Solution solution;

    std::cout << solution.dayOfTheWeek(17, 1, 2021) << "\n";
    std::cout << solution.dayOfTheWeek(17, 1, 2020) << "\n";
    std::cout << solution.dayOfTheWeek(27, 12, 1996) << "\n";

    return 0;
}