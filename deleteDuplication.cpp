/*************************************************************************
	> File Name: deleteDuplication.cpp
	> Author: sukingw 
	> Mail: wangshujingu@163.com
	> Created Time: Thu 24 Aug 2017 06:01:38 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution{
public:
    ListNode* deleteDuplication(ListNode* pHead){
        // 判断输入是否是空指针
        if(pHead == nullptr){
            return nullptr;
        }
        ListNode *pre = nullptr;
        ListNode *cur = pHead;
        ListNode *nex = pHead->next;
        ListNode *nh = new ListNode(0);
        ListNode *pos = nh;
        while(nex != nullptr){
            if(pre == nullptr && cur->val != nex->val){
                pos->next = cur;
                pos = pos->next;
                pos->next = nullptr;
            }
            if(pre != nullptr && pre->val != cur->val && cur->val != nex->val){
                pos->next = cur;
                pos = pos->next;
                pos->next = nullptr;
            }
            pre = cur;
            cur = nex;
            nex = nex->next;
        }
        if(pre->val != cur->val){
            pos->next = cur;
        }
        return nh->next;
    }
};





