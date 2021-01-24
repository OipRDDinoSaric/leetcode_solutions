/**
 * @file
 * @details
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7


 * @see https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 */
#include <vector>
#include <iostream>

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

std::vector<int> vecPostorder {};
std::vector<int> vecInorder {};
std::vector<int> vecPreorder {};

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void
printPostorder(TreeNode* node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    std::cout << node->val << " ";
    vecPostorder.emplace_back(node->val);
}

/* Given a binary tree, print its nodes in inorder*/
void
printInorder(TreeNode* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    std::cout << node->val << " ";
    vecInorder.emplace_back(node->val);

    /* now recur on right child */
    printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void
printPreorder(TreeNode* node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    std::cout << node->val << " ";
    vecPreorder.emplace_back(node->val);

    /* then recur on left sutree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}

class Solution
{
public:
    TreeNode*
    buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
    {
        if (preorder.empty() || (preorder.size() != inorder.size()))
        {
            return nullptr;
        }

        auto* root = new TreeNode {preorder[0]};
        std::cout << preorder[0];

        auto inorderRootIndex = std::find(inorder.begin(), inorder.end(), preorder[0]) -
                                inorder.begin();
        auto preorderRightIndex = inorderRootIndex + 1;

        if (0 != inorderRootIndex)
        {
            std::vector<int> preorderLeft {&preorder[1], &preorder[preorderRightIndex]};
            std::vector<int> inorderLeft {&inorder[0], &inorder[inorderRootIndex]};
            root->left = buildTree(preorderLeft, inorderLeft);
        }
        else
        {
            root->left = nullptr;
        }

        if (preorderRightIndex < preorder.size())
        {
            std::vector<int> preorderRight {&preorder[preorderRightIndex], &(*preorder.end())};
            std::vector<int> inorderRight {&inorder[inorderRootIndex + 1], &(*inorder.end())};
            root->right = buildTree(preorderRight, inorderRight);
        }
        else
        {
            root->right = nullptr;
        }

        return root;
    }
};

int
main()
{
    auto* root       = new TreeNode(1);
    root->left       = new TreeNode(2);
    root->left->left = new TreeNode(3);

    std::cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);

    std::cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);

    std::cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);

    std::cout << "\n";

    Solution solution;

    root = solution.buildTree(vecPreorder, vecInorder);

    std::cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);

    std::cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);

    std::cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);

    return 0;
}