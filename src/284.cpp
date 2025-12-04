#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ____qcodep____ 
#include <iostream>
#include <algorithm>
#include <vector>
struct YellowPage{
   char name[21];
    int telNum;
    YellowPage* next;
};

bool compare(const YellowPage& a, const YellowPage& b){
    return strcmp(a.name, b.name) < 0;
}

YellowPage* create(){
    int N;
    std::cin >> N;
    char name[21];
    int telNum;
    std::vector<YellowPage> arr(N);
    YellowPage* head = NULL, * tail = NULL;
    for(int i = 0; i < N; ++i){
        std::cin >> name >> telNum;
        strcpy(arr[i].name, name);
        arr[i].telNum = telNum;
    }
    std::stable_sort(arr.begin(), arr.end(), compare);
    for(int i = 0; i < N; ++i){
        YellowPage* node = (YellowPage*)malloc(sizeof(YellowPage));
        strcpy(node->name, arr[i].name);
        node->telNum = arr[i].telNum;
        node->next = NULL;
        if(head == NULL)head = tail = node;
        else{
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void realse(YellowPage *head)
{
    YellowPage *p = head, *pre;
    while (p != NULL)
    {
        pre = p, p = p->next;
        pre->next = NULL;
        free(pre);
    }
}

void display(YellowPage *head)
{
    YellowPage *node = head;
    printf("display data \n");
    while (node != NULL)
    {
        printf("%s %d \n", node->name, node->telNum);
        node = node->next;
    }
    realse(head);
}
int main()
{
    display(create());
    return 0;
}