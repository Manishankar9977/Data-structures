#include <stdio.h>
#include<stdlib.h>
struct node{
    int key;
    struct node*left,*right;
};
struct node*newnode(int value){
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->key=value;
    temp->left=temp->right=NULL;
    return temp;
}
struct node*insert(struct node*node,int key){
    if(node==NULL){
        return newnode(key);
    }
    if(key<node->key){
        node->left=insert(node->left,key);
    }
    else if(key>node->key)
    node->right=insert(node->right,key);
    
    return node;
}
void preorder(struct node*root){
    if(root!=NULL){
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
struct node*search(struct node*root,int key){
    if(root==NULL||root->key==key)
    return root;
    if(root->key<key){
        return search(root->right,key);
    }
    else
    return search(root->left,key);
}
struct node*min(struct node*t){
    if(t->left==NULL){
        return t;
    }
    else
    return min(t->left);
}
struct node*max(struct node*t){
    if(t->right==NULL){
        return t;
    }
    else
    return max(t->right);
}
struct node*deletenode(struct node*root,int key){
    if(root==NULL)
    return root;
    if(key<root->key)
    root->left=deletenode(root->left,key);
    else if(key>root->key)
    root->right=deletenode(root->right,key);
    else{
        if(root->left==NULL){
            struct node*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node*temp=root->left;
            free(root);
            return temp;
        }
        else {
            struct node*temp=min(root->right);
            root->key=temp->key;
            root->right=deletenode(root->right,temp->key);
        }
    }
    return root;
}
int main(){
    struct node *root=NULL,*temp,*temp2,*temp3;
    root=insert(root,43);
    insert(root,10);
    insert(root,79);
    insert(root,90);
    insert(root,12);
    insert(root,54);
    insert(root,11);
    insert(root,9);
    insert(root,50);
    preorder(root);
    //For searchin an element
    temp=search(root,10);
    if(temp->key==10){
        printf("\nthe element is present");
    }
    else{
        printf("not present");
    }
    //for finding min number 
    temp2=min(root);
    printf("\nThe min element is %d ",temp2->key);
    //for finding max
    temp3=max(root);
    printf("\nThe max element is %d \n",temp3->key);
    deletenode(root,79);
    preorder(root);
    return 0;
}

