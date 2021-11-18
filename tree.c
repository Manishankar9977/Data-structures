#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*left,*right;
}*root;
struct Node*create(){
    struct Node*newnode;
    int value;
    printf("Enter the numer (-1 for NUll)");
    scanf("%d",&value);
    if(value==-1){
        return NULL;
    }
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    printf("Enter the left child:\n");
    newnode->left=create();
    printf("Enter the right child:\n");
    newnode->right=create();
    
    return newnode;
    
}
void preorder(struct Node*root){
    if(root!=NULL){
        printf("%d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    root=create();
    printf("printing the tree elements:\n");
    preorder(root);

    return 0;
}

