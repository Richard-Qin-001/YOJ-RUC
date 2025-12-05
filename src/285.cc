#include <bits/stdc++.h>
using namespace std;

struct node
{
    int m;
    node* next;
};


node* insertNode(node* head, int n, int m){
    node* p = head;
    node* q = (node *)malloc(sizeof(node));
    q->m = m;
    q->next = NULL;
    if(n == 0){
        q->next = head;
        head =q;
        return head;
    }
    int node_counts = 1;
    while(p != NULL && node_counts < n){
        node_counts++;
        p = p->next;
    }
    if(p == NULL){
        free(q);
        return head;
    }
    q->next = p -> next;
    p->next = q;
    return head;
}

node* delNode(node* head, int n){
    if(head == NULL)return NULL;
    if (n == 1){
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int delCount = 1;
    node* p = head;
    while(p && delCount < n - 1){
        delCount++;
        p = p->next;
    }
    if(p == NULL || p->next == NULL)return head;
    node* temp = p->next;
    p->next = temp->next;
    free(temp);
    return head;
}

void printList(node* head){
    node* p = head;
    while(p){
        printf("%d ", p->m);
        p = p -> next;
    }
    printf("\n");
}

int main(){
    node* head = NULL;
    head = insertNode(head, 0, 1);
    head = insertNode(head, 1, 2);
    printList(head);
    return 0;
}