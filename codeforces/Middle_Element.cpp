/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *temp=head;
        int count =0,l,i=1;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        l=count/2+1;
        temp=head;
        while(i!=l)
        {
            temp=temp->next;
            i++;
        }
        return temp;
    }
};