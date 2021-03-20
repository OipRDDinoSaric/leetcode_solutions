/**
 * @file
 *
 * @details
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of
trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.



Example 1:

Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]

Example 2:

Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]


Constraints:

The number of nodes in the given tree is at most 1000.
Each node has a distinct value between 1 and 1000.
to_delete.length <= 1000
to_delete contains distinct values between 1 and 1000.
 */

#include <vector>
#include <algorithm>

/** Definition for a binary tree node. */
struct TreeNode
{
    int       val;
    TreeNode* left;
    TreeNode* right;
};

class Solution
{
public:
    static std::vector<TreeNode*>
    delNodes(TreeNode* root, std::vector<int>& valuesToDelete)
    {
        std::vector<TreeNode*> forest {};
        impl(root, valuesToDelete, forest);
        if(0 != root->val)
        {
            forest.push_back(root);
        }
        return forest;
    }

private:
    static void
    impl(TreeNode* root, std::vector<int>& valuesToDelete, std::vector<TreeNode*>& forest)
    {
        if (nullptr == root)
        {
            return;
        }
        impl(root->left, valuesToDelete, forest);
        impl(root->right, valuesToDelete, forest);

        if ((nullptr != root->left) && (0 == root->left->val))
        {
            root->left = nullptr;
        }
        if ((nullptr != root->right) && (0 == root->right->val))
        {
            root->right = nullptr;
        }
        if (std::find(valuesToDelete.begin(), valuesToDelete.end(), root->val) !=
            valuesToDelete.end())
        {
            root->val = 0;
            if ((nullptr != root->left) && (0 != root->left->val))
            {
                forest.push_back(root->left);
            }
            if ((nullptr != root->right) && (0 != root->right->val))
            {
                forest.push_back(root->right);
            }
        }
    }
};

int
main()
{
    std::vector<int> valuesToDelete {1, 2};
    TreeNode         rightright {.val = 6, .left = nullptr, .right = nullptr};
    TreeNode         leftleft {.val = 4, .left = nullptr, .right = nullptr};
    TreeNode         leftright {.val = 5, .left = nullptr, .right = nullptr};
    TreeNode         right {.val = 3, .left = nullptr, .right = &rightright};
    TreeNode         left {.val = 2, .left = &leftleft, .right = &leftright};
    TreeNode         root {.val = 1, .left = &left, .right = &right};
    Solution::delNodes(&root, valuesToDelete);
    return 0;
}