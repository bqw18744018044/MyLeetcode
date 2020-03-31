#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ͷ�巨
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(head==NULL||head->next==NULL)return head;
    if(m==n)return head;
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    head = dummy;
    for(int i=1;i<m;i++)head = head->next;
    ListNode* p = head->next;
    ListNode* tmp = NULL;
    for(int i=m;i<n;i++){
        tmp = p->next;
        p->next = p->next->next;
        tmp->next = head->next;
        head->next = tmp;
    }
    return dummy->next;;
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    ListNode* head = new ListNode(nums[0]);
    ListNode* p = head;
    for(int i=1;i<nums.size();i++){
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    p = reverseBetween(head,2,4);
    while(p!=NULL){
        cout<<p->val<<endl;
        p = p->next;
    }
    return 0;
}
