//
//

/*********************************
 * Add Two Numbes
 * You are given two linked lists representing two non-neagtive numbers. The digits are stored in reverse
 * order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * 
 * ******************************/

#include <iostream>

using namespace std;

struct ListNode {
    int m_iValue;
    ListNode* next;

    ListNode(int i): m_iValue(i), next(nullptr){}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        int carry = 0;
        ListNode *prev = &dummy;
        for (ListNode *pa = l1, *pb = l2;
                pa != nullptr || pb != nullptr;
                pa = pa == nullptr ? nullptr : pa->next,
                pb = pb == nullptr ? nullptr : pb->next,
                prev = prev->next) {
            const int ai = pa == nullptr ? 0 : pa->m_iValue;
            const int bi = pb == nullptr ? 0 : pb->m_iValue;
            const int value = (ai + bi + carry) % 10;
            carry = (ai + bi + carry) / 10;
            prev->next = new ListNode(value); //尾插
        }
        if (carry > 0)
            prev->next = new ListNode(carry);
        return dummy.next;
    }
};

int main()
{

    ListNode l1Dummy(-1);
    l1Dummy.next = new ListNode(2);
    l1Dummy.next->next = new ListNode(4);
    l1Dummy.next->next->next = new ListNode(3);

    ListNode l2Dummy(-1);
    l2Dummy.next = new ListNode(5);
    l2Dummy.next->next = new ListNode(6);
    l2Dummy.next->next->next = new ListNode(4);

    Solution s;
    ListNode* ret = s.addTwoNumbers(l1Dummy.next, l2Dummy.next);
    while (ret) {
        cout << ret->m_iValue;
        ret = ret->next;
    }
    cout << endl;

    return 0;
}
