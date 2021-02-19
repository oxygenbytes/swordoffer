/*
---
title: "[剑指 Offer 36]二叉搜索树与双向链表"
date: 2021-02-18 11:39:03
draft: false
toc: true
tags:
  - SwordOffer
  - Leetcode
---
*/
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。 
//
// 
//
// 为了让您更好地理解问题，以下面的二叉搜索树为例： 
//
// 
//
// 
//
// 
//
// 我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是
//第一个节点。 
//
// 下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。 
//
// 
//
// 
//
// 
//
// 特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。 
//
// 
//
// 注意：本题与主站 426 题相同：https://leetcode-cn.com/problems/convert-binary-search-tree-
//to-sorted-doubly-linked-list/ 
//
// 注意：此题对比原题有改动。 
// Related Topics 分治算法 
// 👍 181 👎 0

/*
* 剑指 Offer 36 二叉搜索树与双向链表
* 2021-02-18 11:39:03
* @author oxygenbytes
*/ 
#include "leetcode.h" 
//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node *pre, *head;
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

    void dfs(Node* root){
        if(!root) return ;
        dfs(root->left);

        if(pre) pre->right = root;
        else head = root;
        root->left = pre;
        pre = root;

        dfs(root->right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
     