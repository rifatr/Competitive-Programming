#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

 struct node *G_root;

 void traverse_inorder(struct node *root)
 {
     if(root->left!='\0')
        traverse_inorder(root->left);
     printf("%d\t",root->data);

     if(root->right!='\0')
        traverse_inorder(root->right);
 }
 void traverse_preorder(struct node *root)
 {
      printf("%d\t",root->data);
     if(root->left!='\0')
        traverse_preorder(root->left);

     if(root->right!='\0')
        traverse_preorder(root->right);



 }
 void traverse_postorder(struct node *root)
 {


     if(root->left!='\0')
        traverse_postorder(root->left);
        if(root->right!='\0')
        traverse_postorder(root->right);
         printf("%d\t",root->data);


 }

 void insert_node(struct node *root, int val)
 {

     if(val<=root->data)
     {
         if(root->left=='\0')
         {
             struct node *new_node;
             int temp;
             new_node=(struct node*)malloc(sizeof(struct node));
             new_node->left=new_node->right='\0';
             new_node->data=val;
             root->left = new_node;

         }
         else
         {
             insert_node(root->left,val);

         }

     }

     else
     {
         if(root->right=='\0')
         {
         struct node *new_node;
             int temp;
             new_node=(struct node*)malloc(sizeof(struct node));
             new_node->left=new_node->right='\0';
             new_node->data=val;
             root->right = new_node;

         }
         else
         {
             insert_node(root->right,val);

         }
     }
 }

 int main ()
 {
     struct node *new_node,*curr_node,*root;
     int temp,i;
     for(i=1;i<=7;i++)
     {
         if(i==1)
         {
             new_node=(struct node*)malloc(sizeof(struct node));
             new_node->left=new_node->right='\0';
             scanf("%d",&temp);
             new_node->data=temp;
             G_root=new_node;

         }
         else
         {
             curr_node=G_root;
             scanf("%d",&temp);
             insert_node(curr_node,temp);
         }
     }
     printf("Traversing the tree INORDERLY\n");
     traverse_inorder(G_root);
      printf("\n");
      printf("Traversing the tree PRE-ORDERLY\n");
     traverse_preorder(G_root);
      printf("\n");
      printf("Traversing the tree POST-ORDERLY\n");
     traverse_postorder(G_root);
      printf("\n");
 }
