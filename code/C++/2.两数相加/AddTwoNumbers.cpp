/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL||l2==NULL)return NULL;
        int carry = 0; //进位
        int sum = l1->val+l2->val+carry;
        //先处理最低位，目的是简化下面while中的代码
        ListNode* head = new ListNode(sum%10);//head是结果链表的头结点
        ListNode* cur = head;//cur是结果链表的当前位置
        carry = sum/10;
        ListNode* p = l1->next;
        ListNode* q = l2->next;
        while(p!=NULL||q!=NULL){
            int x = (p!=NULL)?p->val:0;//如果链表l1较短，缺失的位补0
            int y = (q!=NULL)?q->val:0;//如果链表l2较短，缺失的位补0
            sum = x+y+carry;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            carry = sum/10;
            if(p!=NULL)p = p->next;
            if(q!=NULL)q = q->next;
        }
        //处理最高位有进位的情况
        if(carry>0)
            cur->next = new ListNode(carry);
        return head;
    }
};
