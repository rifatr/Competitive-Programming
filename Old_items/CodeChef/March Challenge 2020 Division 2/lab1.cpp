#include<bits/stdc++.h>

using namespace std;

struct node
{
  int data;
  struct node *next;
};
 class linked_list
 {
     node *head, *tail;
     public:
     linked_list()
     {
         head=NULL;
         tail=NULL;
     }
 };


node *getnode(int data)
{
    node *new_node=new_node();
    new_node->data=data;
    new_node->next = NULL;
    return new_node;
}

void add_node(int n)
{
    node *tmp=new_node;
    tmp->data=n;
    tmp->next=NULL;

    if(head==NULL)
    {
        head=tmp;
        tail=tmp;
    }
    else
    {
       tail->next=tmp;
       tail=tail->next;
    }
}
 node* gethead()
 {
     return head;
 }

 void display(node* head)
 {
     if (head== NULL)
     {
         printf("NULL\n");
     }
 }
