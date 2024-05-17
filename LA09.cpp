/*
A Dictionary stores keywords & its meanings. Provide facility for adding
new keywords, deleting keywords, updating values of any entry. Provide facility to
display whole data sorted in ascending/ Descending order. Also find how many
maximum comparisons may require for finding any keyword. Use Height balance
tree and find the complexity for finding a keyword.
AVL
*/ 


#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Tree
{
    typedef struct node
    {
        char key[10];
        char meaning[10];
        struct node *left;
        struct node *right;
    } btree;

public:
    btree *New, *root;
    Tree();
    void create();
    void insert(btree *root, btree *New);
    void inorder();
    void inorder_rec(btree *root);
    void postorder();
    void postorder_rec(btree *root);
};

Tree::Tree()
{
    root = NULL;
}

void Tree::inorder()
{
    inorder_rec(root);
}
void Tree::inorder_rec(btree *root)
{
    if (root != NULL)
    {
        inorder_rec(root->left);
        cout << "\n\t" << root->key << "\t" << root->meaning;
        inorder_rec(root->right);
    }
}

void Tree::postorder()
{
    postorder_rec(root);
}
void Tree::postorder_rec(btree *root)
{
    if (root != NULL)
    {

        postorder_rec(root->right);
        cout << "\n\t" << root->key << "\t" << root->meaning;
        postorder_rec(root->left);
    }
}

void Tree::create()
{
    New = new btree;
    New->left = New->right = NULL;
    cout << "\nEnter the Keyword: ";
    cin >> New->key;
    cout << "\nEnter the Meaning of " << New->key << ": ";
    cin >> New->meaning;
    if (root == NULL)
    {
        root = New;
    }
    else
    {
        insert(root, New);
    }
}

void Tree::insert(btree *root, btree *New)
{

    if (strcmp(root->key, New->key) > 0)
    {
        if (root->left == NULL)
            root->left = New;
        else
            insert(root->left, New);
    }
    else        
    {
        if (root->right == NULL)
            root->right = New;
        else
            insert(root->right, New);
    }
}

int main()
{
    Tree tr;
    int ch, ans;
    int flag;
    cout << "\n***** BST Operations *****";
    do
    {
        flag=0;
        cout << "\n1. Create\n2. Display\n3. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:

            do
            {
                tr.create();
                cout << "To add more, press 1: ";
                cin >> ans;
            } while (ans == 1);
            flag = 1;
            break;
        case 2:
            cout << "1.Ascending\n2.Descending\nEnter Your Choice: ";
            cin >> ch;
            cout << "\nKeyword Meaning";

            switch (ch)
            {
            case 1:
                tr.inorder();
                break;
            case 2:
                tr.postorder();
                break;
            }
            break;
        case 3:
            break;
        }
        cout << "\nDo You Want to Continue? Press 1: ";
        cin >> ans;
    } while (ans== 1);
}
