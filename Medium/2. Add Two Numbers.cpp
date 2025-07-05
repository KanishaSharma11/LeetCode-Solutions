class Solution{
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
      vector<int> one, two;

      while(l1 != NULL){
        one.push_back(l1->val);
        l1 = l1->next;
      }

      while(l2 != NULL){
        two.push_back(l1->val);
        l2 = l2->next;
      }

      ListNode* dummy = new ListNode(0);
      ListNode* current = dummy;
      int carry = 0, i = 0;

      while(i < one.size() || i < two.size() || carry > 0){
        int digit1 = (i < one.size()) ? one[i] : 0;
        int digit2 = (i < two.size()) ? two[i] : 0;
        int sum = digit1 + digit2 + carry;

        carry = sum / 10;

        current->next = new ListNode(sum % 10);
        current = current->next;
        i++;
      }

      return dummy->next;
    }
};
