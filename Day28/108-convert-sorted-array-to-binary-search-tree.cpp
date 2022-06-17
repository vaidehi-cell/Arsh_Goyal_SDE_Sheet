/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* BST(vector<int>& nums, int start, int end) 
    {       
        if(start < 0 || start >= nums.size() || end < 0 || end >= nums.size() || start > end)   
            return NULL;
        int mid = (start + end) / 2;  
        if(mid >= nums.size())
            return NULL;
        TreeNode* head = new TreeNode(nums[mid]);
        head->left = BST(nums, start, mid - 1);
        head->right = BST(nums, mid + 1, end);
        return head;
    }
    TreeNode* sortedArrayToBST(vector<int> & nums)
    {
        if(nums.size() == 0)
            return NULL;
        return BST(nums, 0, nums.size()-1);
    }
};
