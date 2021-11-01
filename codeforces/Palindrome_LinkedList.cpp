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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head,*pr=head,*ne=head;
        int l=0,n,i=1;
        while(temp!=NULL)
        {
            temp=temp->next;
            l++;
        }
        if(l==1)
            return true;
        n=l/2;
        cout<<l<<" "<<n<<"\n";
        
        temp=head;
          while(i<=n)
         {
             pr=temp;
             temp=temp->next;
             i++;
         }
        cout<<temp->val<<" "<<pr->val<<"\n";
        pr->next=NULL;
         while(temp!=NULL)
         {
             ne=temp->next;
             temp->next=pr;
             pr=temp;
             temp=ne;
         }
        cout<<pr->val<<"\n";
        i=1;
        temp=head;
        while(i<=n)
        {
            if(pr->val!=temp->val)
                return false;
            temp=temp->next;
            pr=pr->next;
            i++;
        }
        return true;
            
    }
};