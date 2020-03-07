/*
5339. 二叉搜索子树的最大键值和
给你一棵以 root 为根的 二叉树 ，请你返回 任意 二叉搜索子树的最大键值和。

二叉搜索树的定义如下：

任意节点的左子树中的键值都 小于 此节点的键值。
任意节点的右子树中的键值都 大于 此节点的键值。
任意节点的左子树和右子树都是二叉搜索树。
 

示例 1：



输入：root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
输出：20
解释：键值为 3 的子树是和最大的二叉搜索树。
示例 2：



输入：root = [4,3,null,1,2]
输出：2
解释：键值为 2 的单节点子树是和最大的二叉搜索树。
示例 3：

输入：root = [-4,-2,-5]
输出：0
解释：所有节点键值都为负数，和最大的二叉搜索树为空。
示例 4：

输入：root = [2,1,3]
输出：6
示例 5：

输入：root = [5,4,8,3,null,6,3]
输出：7
 

提示：

每棵树最多有 40000 个节点。
每个节点的键值在 [-4 * 10^4 , 4 * 10^4] 之间。
通过次数325提交次数966
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int my_max;
    struct answer{
        bool flag;
        int val;
    };
    
    struct answer visit(TreeNode *root)
    {
        answer temp;
        temp.flag=true;
        temp.val=0;
        cout<<root->val<<endl;
        if(root->left==NULL&&root->right==NULL)
        {
           
            temp.flag=true;
            temp.val=root->val;
            if(temp.val>my_max&&temp.flag)
            {
                
                my_max=temp.val;
            }
            
            return temp;
        }
        if(root->left==NULL)
        {
            
            if(root->val >= root->right->val)
            {
                temp.flag=false;
            }
            answer temp2=visit(root->right);
            temp.flag=temp.flag&&temp2.flag;
            temp.val=root->val+temp2.val;
            if(temp.val>my_max&&temp.flag)
            {
                my_max=temp.val;
            }
            //cout<<"val"<<temp.val<<endl;
            return temp;
        }
        if(root->right==NULL)
        {
            
             if(root->val <= root->left->val)
            {
                temp.flag=false;
            }
            answer temp3=visit(root->left);
            temp.flag=temp.flag&&temp3.flag;
            temp.val=root->val+temp3.val;
            if(temp.val>my_max&&temp.flag)
            {
                my_max=temp.val;
            }
           //cout<<"val"<<temp.val<<endl;
            return temp;
        }
        if(root->val >= root->right->val)
        {
            temp.flag=false;
        }
         if(root->val <= root->left->val)
        {
            temp.flag=false;
        }
        
        answer temp2=visit(root->right);
        answer temp3=visit(root->left);
        temp.flag=temp.flag&&temp2.flag&&temp3.flag;
        temp.val=root->val+temp2.val+temp3.val;
        if(temp.val>my_max&&temp.flag)
        {
            my_max=temp.val;
        }
        //cout<<"val"<<temp.val<<endl;
        return temp;
    }
    int maxSumBST(TreeNode* root) {
        my_max=INT_MIN;
        visit(root);
        if(my_max<0)
            return 0;
        return my_max;
        
    }
};