#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//create struct
struct  Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

//Global data initialization
struct Node *root;
struct Node *control;

bool isEmpty(){
    return root == NULL;
}

struct Node* create_node(int key)
{
    struct Node *the_node = (struct Node *)malloc(sizeof(struct Node));
    the_node->key = key;
    the_node->left = NULL;
    the_node->right = NULL;
    return the_node;
}


void insert(int key, struct Node *curr_control){
    //check if empty
    if (isEmpty()){
        //create node;
        struct Node *new_node;
        new_node = create_node(key);
        root = new_node;
        control = new_node;
        printf("Root created!\n");
    }
    else{
        // printf("Masuk else insert\n");
        if (key >= curr_control->key)
        {
            //go right
            // printf("Go right!\n");
            if (curr_control->right != NULL)
            {
                // printf("Kanan Tidak Null\n");
                curr_control = curr_control->right;
                insert(key, curr_control);
            }
            else
            {
                //create new_node;
                //then link right of curr node to new node;
                // printf("Kanan Null, bikin leaf kanan\n");
                struct Node *new_leaf_node = create_node(key);
                curr_control->right = new_leaf_node;
            }
        }
        else if (key < curr_control->key)
        {
            //go left
            // printf("Go left!\n");
            if (curr_control->left != NULL)
            {
                // printf("Kiri Tidak Null\n");
                curr_control = curr_control->left;
                insert(key, curr_control);
            }
            else
            {
                // printf("Kiri Null, bikin leaf kiri\n");
                struct Node *new_leaf_node = create_node(key);
                curr_control->left = new_leaf_node;
            }
        }
    }
}

void show_tree(struct Node *control){
    //show current control key
    printf("%d\n", control->key); 
    
    //show the left tree
    if (control->left != NULL){
        show_tree(control->left);
    }

    //show the right tree
    if (control->right != NULL){
        show_tree(control->right);
    }

}

void show_asc(struct Node *control){
    //show the left tree first
    if (control->left != NULL)
    {
        show_asc(control->left);
    }

    printf("%d, ", control->key);

    //show the right tree
    if (control->right != NULL)
    {
        show_asc(control->right);
    }
}

void show_desc(struct Node *control)
{
    //show the right tree
    if (control->right != NULL)
    {
        show_desc(control->right);
    }

    printf("%d, ", control->key);

    //show the left tree first
    if (control->left != NULL)
    {
        show_desc(control->left);
    }
}

int main(){
    root = NULL;
    int pil, key;
    do{
        printf("Program tree main menu:\n");
        printf("1. Insert node\n");
        printf("2. Show tree\n");
        printf("3. Show tree ascending\n");
        printf("4. Show tree descending\n");
        printf("Masukkan pilihan, pilih 0 bila ingin keluar: ");
        scanf("%d",&pil);
        if (pil == 1){
            printf("Masukkan key: ");
            scanf("%d",&key);
            insert(key, root);
        }
        else if(pil== 2){
            if (root != NULL){
                show_tree(root);
                printf("\n\n");
            }
            else{
                printf("There is no tree here!\n\n");
            }
        }
        else if(pil == 3){
            if (root != NULL){
                show_asc(root);
                printf("\n\n");
            }
            else
            {
                printf("There is no tree here!\n\n");
            }
            
        }
        else if (pil == 4)
        {
            if (root != NULL)
            {
                show_desc(root);
                printf("\n\n");
            }
            else
            {
                printf("There is no tree here!\n\n");
            }
        }
        else if(pil == 0)
        {
            printf("Terimakasih telah menggunakan program ini!\n");
        }
        else
        {
            printf("Input salah!\n\n");
        }
    }while (pil != 0);
    return 0;
}