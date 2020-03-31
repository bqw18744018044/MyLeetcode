#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates_1(ListNode* head){
    if(head==NULL||head->next==NULL)return head;
    //删除链表开头的重复元素
    while(head->next!=NULL&&head->val==head->next->val){//如果开头是重复元素
        while(head->next!=NULL&&head->val==head->next->val){//将head移动到重复元素的末尾
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        if(head->next==NULL)return NULL;
        head = head->next;//将head移动到下一个元素
    }
    ListNode* pre = head;//上一个不重复的元素
    ListNode* cur = head->next;
    while(cur!=NULL&&cur->next!=NULL){
        if(cur->val!=cur->next->val){//如果cur中的元素不重复
            pre = pre->next;
            cur = cur->next;
        }else{
            while(cur->val==cur->next->val){
                cur = cur->next;
                if(cur->next==NULL){
                    pre->next = NULL;
                    return head;
                }
            }
            cur = cur->next;
            pre->next = cur;
        }
    }
    return head;
}

// 哑节点
ListNode* deleteDuplicates_2(ListNode* head){
    if(head==NULL||head->next==NULL)return head;
    ListNode* p = new ListNode(0);
    p->next = head;
    head = p;
    ListNode* cur = p->next;
    while(cur!=NULL&&cur->next!=NULL){
        if(cur->val!=cur->next->val){
            p = p->next;
            cur = cur->next;
        }else{
            while(cur->val==cur->next->val){
                cur = cur->next;
                if(cur->next==NULL){
                    p->next = NULL;
                    return head->next;
                }
            }
            cur = cur->next;
            p->next = cur;
        }
    }
    return head->next;
}

// 递归
ListNode* deleteDuplicates_3(ListNode* head){
    if(head==NULL||head->next==NULL)return head;
    if(head->val==head->next->val){// 开头是重复元素
        while(head->next!=NULL&&head->val==head->next->val)head = head->next;
        return deleteDuplicates_3(head->next);
    }else head->next = deleteDuplicates_3(head->next);//开头不是重复元素
    return head;
}

int main(){
    vector<int> nums = {1,1,2,3,3,3,4};
    ListNode* head = new ListNode(nums[0]);
    ListNode* p = head;
    for(int i=1;i<nums.size();i++){
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    //p = deleteDuplicates_1(head);
    //p = deleteDuplicates_2(head);
    p = deleteDuplicates_3(head);
    while(p!=NULL){
        cout<<p->val<<endl;
        p = p->next;
    }
    return 0;
}
