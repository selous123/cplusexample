#include<iostream>
using namespace std;
#include<cstdlib>
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if(head==NULL||head->next==NULL) return true;
        ListNode*fast=head,*slow=head;
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = slow->next;
        ListNode *new_head = reverseLink(slow);

        while(new_head){
            if(new_head->val!=head->val){
                return false;
            }
            new_head = new_head->next;
            head = head->next;
        }
        return true;

    }

    ListNode *reverseLink(ListNode *head){
        ListNode *h = head;
        ListNode *pcurr = h->next;
        while(pcurr){
            h->next = pcurr->next;
            pcurr->next = head;
            head = pcurr;
            pcurr = h->next;
        }
        return head;
    }

    ListNode *reverseBetween(ListNode*head,int m,int n){

        int index=1;
        ListNode *pcurr = head;
        ListNode *pnext;
        if (m==1){
             pnext = pcurr->next;
             //将p_next拿到链表头部
             while(index<n){
                pcurr->next = pnext->next;
                pnext->next = head;
                head = pnext;
                pnext = pcurr->next;
                index++;
             }
             return head;
        }

        ListNode *pre_head=head;
        while(index<m-1){
            pre_head = pre_head->next;
            index++;
        }

        pcurr = pre_head->next;
        cout<<pcurr->val<<"reverse\n";
        pnext = pcurr->next;
        index+=2;
        while(index<=n){
            pcurr->next = pnext->next;
            pnext->next = pre_head->next;
            pre_head->next = pnext;
            pnext = pcurr->next;
            index++;
        }
        return head;
    }

};


int main(){
    ListNode *head;
    int num=1;
    int i;
    cin>>i;
    head = (ListNode*)malloc(sizeof(ListNode));
    head->val = i;
    head->next = NULL;
    ListNode *temp = head;
    while(num--){
        cin>>i;
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp = temp->next;
        temp->val = i;
        temp->next =NULL;
    }

    /*
    temp = head;
    while(temp){
        cout<<temp->val<<" "<<endl;
        temp = temp->next;
    }
*/

    Solution s;

    head = s.reverseBetween(head,2,2);
    temp = head;
    while(temp){
        cout<<temp->val<<"hello"<<endl;
        temp = temp->next;
    }
    return 0;
}
