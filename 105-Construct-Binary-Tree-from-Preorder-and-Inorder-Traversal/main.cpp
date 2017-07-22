#include "tree.h"

int main() {
//    TreeNode* n1 = new TreeNode(1);
//    TreeNode* n2 = new TreeNode(2);
//    TreeNode* n3 = new TreeNode(3);
//    TreeNode* n4 = new TreeNode(4);
//    TreeNode* n5 = new TreeNode(5);
//    TreeNode* n6 = new TreeNode(6);
//    TreeNode* n7 = new TreeNode(7);
//    n1->right = n3;
//    n1->left = n2;
//    n2->right = n5;
//    n2->left = n4;
//    n4->right = n6;
//    n5->left = n7;

    std::vector<int> nums1{1,2,4,6,5,7,3};
    std::vector<int> nums2{4,6,2,7,5,1,3};
    Solution *s = new Solution();
    TreeNode* res = s->buildTree(nums1, nums2);
    s->preorder(res);
    std::cout << std::endl;
    s->inorder(res);
    return 0;
}