/**
 * @file
 * @details
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any node sequence from some starting node to any node in the
tree along the parent-child connections. The path must contain at least one node and does not need
to go through the root.

Example 1:

Input: root = [1,2,3]
Output: 6
Example 2:

Input: root = [-10,9,20,null,null,15,7]
Output: 42

Constraints:

The number of nodes in the tree is in the range [0, 3 * 104].
-1000 <= Node.val <= 1000

 * @see
https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/973312/My-Solution-with-proper-comments-and-reasoning
 * @see https://www.youtube.com/watch?v=TO5zsKtc1Ic
 */

#include <iostream>

/** Definition for a binary tree node. */
struct TreeNode
{
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
    {}
};

class Solution
{
public:
    int
    maxPathSum(TreeNode* root)
    {
        return 1;
    }
};

int
main()
{
    Solution solution {};
    TreeNode leftLeft2(4);
    TreeNode rightRight2(5);
    TreeNode left1(2, &leftLeft2, nullptr);
    TreeNode right1(3, &rightRight2, nullptr);
    TreeNode root0(1, &left1, &right1);

    std::cout << solution.maxPathSum(&root0);
}