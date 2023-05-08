struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* start = new ListNode;

    ListNode* now = start;

    bool is_carry_up = false;
    while (1) {
      int v1 = 0;
      int v2 = 0;
      if (l1 != nullptr) v1 = l1->val;
      if (l2 != nullptr) v2 = l2->val;

      now->val = v1 + v2;
      if (is_carry_up) now->val++;
      if (now->val >= 10) {
        is_carry_up = true;
        now->val %= 10;
      } else {
        is_carry_up = false;
      }

      if (l1 != nullptr) l1 = l1->next;
      if (l2 != nullptr) l2 = l2->next;
      if (l1 == nullptr && l2 == nullptr && !is_carry_up) break;

      ListNode* new_node = new ListNode;
      now->next = new_node;
      now = new_node;
    }

    return start;
  }
};

#include <bits/stdc++.h>
using namespace std;
int main() {
  ListNode ln1(2);
  ListNode ln2(5);

  Solution sl;
  ListNode* ans = sl.addTwoNumbers(&ln1, &ln2);

  cout << ans->val << endl;
  ;
}