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
        int carry = 0; //��λ
        int sum = l1->val+l2->val+carry;
        //�ȴ������λ��Ŀ���Ǽ�����while�еĴ���
        ListNode* head = new ListNode(sum%10);//head�ǽ�������ͷ���
        ListNode* cur = head;//cur�ǽ������ĵ�ǰλ��
        carry = sum/10;
        ListNode* p = l1->next;
        ListNode* q = l2->next;
        while(p!=NULL||q!=NULL){
            int x = (p!=NULL)?p->val:0;//�������l1�϶̣�ȱʧ��λ��0
            int y = (q!=NULL)?q->val:0;//�������l2�϶̣�ȱʧ��λ��0
            sum = x+y+carry;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            carry = sum/10;
            if(p!=NULL)p = p->next;
            if(q!=NULL)q = q->next;
        }
        //�������λ�н�λ�����
        if(carry>0)
            cur->next = new ListNode(carry);
        return head;
    }
};
