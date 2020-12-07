//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//
//
// 示例：
//
// 输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4

#ifndef ALGORITHM_MERGE_TWO_LISTS_H
#define ALGORITHM_MERGE_TWO_LISTS_H

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;

    ListNode* head = new ListNode;
    ListNode* p = head;
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    while(p1 != nullptr && p2 != nullptr) {
        int val;
        if(p1->val <= p2->val) {
            val = p1->val;
            p1 = p1->next;
        } else {
            val = p2->val;
            p2 = p2->next;
        }
        p->next = new ListNode{val};
        p = p->next;
    }
    while(p1 != nullptr) {
        p->next = new ListNode{p1->val};
        p = p->next;
        p1 = p1->next;
    }
    while(p2 != nullptr) {
        p->next = new ListNode{p2->val};
        p = p->next;
        p2 = p2->next;
    }
    return head->next;
}

/**
 * 牛逼的算法（迭代）
 */
ListNode* mergeTwoLists_1(ListNode* l1, ListNode* l2) {
    auto* head = new ListNode;
    ListNode* prev = head;
    while(l1 != nullptr && l2 != nullptr) {
        if(l1->val <= l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }

    prev->next = l1 ? l1 : l2;
    ListNode* result = head->next;
    delete head;
    return result;
}

void print_list(ListNode* l) {
    while(l != nullptr) {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}

void test_mergeTwoLists() {
    ListNode* l1 = new ListNode{1};
    l1->next = new ListNode{2};
    l1->next->next = new ListNode{4};
    print_list(l1);

    ListNode* l2 = new ListNode{1};
    l2->next = new ListNode{3};
    l2->next->next = new ListNode{4};
    print_list(l2);

    ListNode* result = mergeTwoLists_1(l1, l2);
    print_list(result);
}

#endif //ALGORITHM_MERGE_TWO_LISTS_H
