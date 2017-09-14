
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        stack<int>s1,s2;
        ListNode *p1=l1,*p2=l2;
        while(p1){
            s1.push(p1->val);
            p1 = p1->next;
        }
        while(p2){
            s2.push(p2->val);
            p2=p2->next;
        }


        ListNode *p = NULL;

        ListNode node(5);
        //p = &node;
        //ListNode *head=NULL;
        //node.next = head;
        /*
        int val;
        while(!s1.empty()&&!s2.empty()){
            val = s1.top()+s2.top();
            s1.pop();
            s2.pop();
            ListNode node(val);
            node.next = p;
            p = &node;
        }

        while(!s1.empty()){
            val = s1.top();
            s1.pop();
            ListNode node(val);
            node.next = p;
            p = &node;
        }

        while(!s2.empty()){
            val = s2.top();
            s2.pop();
            ListNode node(val);
            node.next = p;
            p = &node;
        }
        */
        return p;
    }
};


int main(){

    ListNode *headA,*headB;
    int a[4]={7,2,4,3};
    int b[3]={5,6,4};
    int i;
    ListNode node(0);
    ListNode *p;
    headA = &p;

    for(i=0;i<4;i++){
        ListNode node(a[i]);
    }



}
