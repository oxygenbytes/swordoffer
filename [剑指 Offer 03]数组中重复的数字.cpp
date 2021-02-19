/*
---
title: "[剑指 Offer 03]数组中重复的数字"
date: 2021-02-18 11:26:59
draft: false
toc: true
tags:
  - SwordOffer
  - Leetcode
---
*/
//找出数组中重复的数字。 
//
// 
//在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请
//找出数组中任意一个重复的数字。 
//
// 示例 1： 
//
// 输入：
//[2, 3, 1, 0, 2, 5, 3]
//输出：2 或 3 
// 
//
// 
//
// 限制： 
//
// 2 <= n <= 100000 
// Related Topics 数组 哈希表 
// 👍 271 👎 0

/*
* 剑指 Offer 03 数组中重复的数字
* 2021-02-18 11:26:59
* @author oxygenbytes
*/ 
#include "leetcode.h" 
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        // 遍历一遍，判断是否存在不属于0-（n-1)的元素
        for(int i = 0;i < n;i++){
            if(nums[i] < 0 || nums[i] >= n)
                return -1;
        }
        // 重新遍历，将值为i的节点，放置到下标为i的位置，若有冲突，则说明重复元素存在
        for(int i = 0;i < n;i++){
            if(nums[i] == i) continue;
            else if(nums[i] != i){
                if(nums[i] != nums[nums[i]])
                    swap(nums[i], nums[nums[i]]);
                else
                    return nums[i];
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
     