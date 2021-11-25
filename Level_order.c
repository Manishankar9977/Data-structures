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
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node*root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void inorder(struct Node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int heightoftree(struct Node*root){
    if(root==NULL)
    return -1;
    int lt=heightoftree(root->left);
    int rt=heightoftree(root->right);
    if(lt>rt)
    return (lt+1);
    else
    return(rt+1);
    
}
void levelorder(struct Node*root,int level){
    if(root==NULL)
    return ;
    if(level==1)
    printf("%d ",root->data);
    else if(level>1){
        levelorder(root->left,level-1);
        levelorder(root->right,level-1);
    }
}
int main(){
    root=create();
    printf("printing the tree elements:\n");
    preorder(root);
    int ht=heightoftree(root);
    printf("Height of tree:%d",ht);
    printf("\nLevel order is:");
    for(int i=1;i<=ht+1;i++){
        levelorder(root,i);
    }

    return 0;
}




