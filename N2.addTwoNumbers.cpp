#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
   public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *res = new ListNode(0); // head node
      ListNode *tail = res;
      int up = 0;
      while(l1 || l2 || up){
         int now_sum = up;
         now_sum += l1 ? l1->val : 0;
         l1 = l1 ? l1 -> next : l1;
         now_sum += l2 ? l2->val : 0;
         l2 = l2 ? l2 -> next : l2;
         up = now_sum / 10;
         now_sum %= 10;
         tail -> next = new ListNode(now_sum);
         tail = tail -> next;
      }
      tail = res;
      res = res -> next;
      delete tail;
      return res;
   }
}; 

class Solution2 {
public:
   int up = 0;
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      if(!up && !l1 && !l2){
         return nullptr;
      }
      int now = up + (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0);
      up = now / 10;
      return new ListNode(now % 10, addTwoNumbers(l1 ? l1 -> next : l1, l2 ? l2 -> next : l2));
   }
}; // 重复使用会导致进位残留

class Solution3 {
public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      return addhelper(l1, l2, 0);
   }
private:
   ListNode* addhelper(ListNode* l1, ListNode* l2, int carry) {
      if (!l1 && !l2 && !carry) return nullptr;
      int now = carry + (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0);
      return new ListNode(now % 10, addhelper(l1 ? l1 -> next : l1, l2 ? l2 -> next : l2, now / 10));
   }
};
