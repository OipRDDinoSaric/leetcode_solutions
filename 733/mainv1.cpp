/**
 * @file
 * @details
An image is represented by a 2-D array of integers, each integer representing the pixel value of the
image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and
a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to
the starting pixel of the same color as the starting pixel, plus any pixels connected
4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace
the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input:
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation:
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

 * @see https://leetcode.com/problems/flood-fill/
 */

#include <vector>
#include <iostream>

class Solution
{
public:
    std::vector<std::vector<int>>
    floodFill(std::vector<std::vector<int>>& image, int startRow, int startColumn, int newColor)
    {
        auto      columnSz {image[startRow].size()};
        auto      rowSz {image.size()};
        const int curColor {image[startRow][startColumn]};

        if(newColor == curColor)
        {
            return image;
        }

        image[startRow][startColumn] = newColor;

        if ((startRow < (rowSz - 1)) && (curColor == image[startRow + 1][startColumn]))
        {
            floodFill(image, startRow + 1, startColumn, newColor);
        }
        if ((startRow > 0) && (curColor == image[startRow - 1][startColumn]))
        {
            floodFill(image, startRow - 1, startColumn, newColor);
        }
        if ((startColumn < (columnSz - 1)) && (curColor == image[startRow][startColumn + 1]))
        {
            floodFill(image, startRow, startColumn + 1, newColor);
        }
        if ((startColumn > 0) && (curColor == image[startRow][startColumn - 1]))
        {
            floodFill(image, startRow, startColumn - 1, newColor);
        }

        return image;
    }
};

int
main()
{
    Solution                      solution;
    std::vector<std::vector<int>> image {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    constexpr int                 startRow {0};
    constexpr int                 startColumn {0};
    constexpr int                 newColor {1};

    solution.floodFill(image, startRow, startColumn, newColor);

    for(const auto& row : image)
    {
        for(const auto& elem : row)
        {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}