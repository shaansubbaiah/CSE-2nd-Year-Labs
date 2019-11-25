#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *left;
    int data;
    struct Node *right;
}*node;


node getnode(int item){
    node temp = (node)malloc(sizeof(struct Node));

    temp->left = NULL;
    temp->data = item;
    temp->right = NULL;

    return temp;
}


node insert(node root, int ele){
    if(root == NULL)
        return getnode(ele);
    else if(ele < root->data)
        root->left = insert(root->left, ele);
    else if(ele > root->data)
        root->right = insert(root->right, ele);

    return root;
}


void inorder(node root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


void preorder(node root){
    if(root == NULL)
        return;
    
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}


void postorder(node root){
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}


int search(node root, int ele){
    if(root == NULL)
        return 0;
    
    node temp = root;
    while(temp != NULL){
        if(ele == temp->data)
            return 1;
        else if(ele < temp->data)
            temp = temp->left;
        else // if ele > temp->data
            temp = temp->right;
    }
    // if not found within while loop, ret 0;
    return 0;
}


int max(node root){
    if(root == NULL)
        return -1;
    
    int maxval;
    node temp = root;
    while(root != NULL){
        maxval = root->data;
        root = root->right;
    }
    return maxval;
}


int min(node root){
    if(root == NULL)
        return -1;
    
    int minval;
    node temp = root;
    while(root != NULL){
        minval = root->data;
        root = root->left;
    }
    return minval;
}


void main(){
    node root = NULL;
    int e, ch = 1;
    
    while(ch!=10){
        printf("\n\n1.Insert\n2.Search\n3.PreOrder\n4.InOrder\n5.PostOrder\n");
        printf("6.Max\n7.Min\n10.Exit\n");
        scanf("%d", &ch);
        printf("\n");

        switch(ch){
            case 1:
                printf("Element:");
                scanf("%d", &e);
                root = insert(root, e);
                break;
            
            case 2:
                printf("Element:");
                scanf("%d", &e);
                if(search(root, e))
                    printf("Found %d.", e);
                else
                    printf("Couldn't find %d.", e);
                break;
            
            case 3:
                preorder(root);
                break;
            
            case 4:
                inorder(root);
                break;
            
            case 5:
                postorder(root);
                break;
            
            case 6:
                printf("Max: %d", max(root));
                break;
            
            case 7:
                printf("Min: %d", min(root));        
                break;
            
            case 10:
                printf("Exiting.");
                exit(1);
            
            default:
                printf("Wrong input!");
        }
    }
}