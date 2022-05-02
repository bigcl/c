//
// Created by joker on 2022/4/26.
//

#include <malloc.h>
#include <io.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1,struct  ListNode* l2){
    int sum = 0;
    struct ListNode *pre = malloc(sizeof (struct ListNode));
    struct ListNode *result = pre;
    result->next = NULL;
    while(l1||l2||sum!=0) {
        if(l1) {
            sum += l1->val;l1 = l1->next;
        }
        if(l2) {
            sum += l2->val;  l2 = l2->next;
        }
        struct ListNode *res = malloc(sizeof (struct ListNode));
        res->val = sum % 10;
        res->next = NULL;
        result->next = res;
        result = result->next;
        sum = sum / 10;
    }
    return pre->next;
}