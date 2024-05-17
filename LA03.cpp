/*
Beginning with an empty binary search tree, Construct binary search tree by
inserting the values in the order given. After constructing a binary tree - i. Insert
new node ii. Find number of nodes in longest path iii. Minimum data value found
in the tree iv. Change a tree so that the roles of the left and right pointers are
swapped at every node v. Search a value.
*/
// Binary search tree
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void addNode()
{
    struct node *temp = new node;
    cout << "\nENTER DATA : ";
    cin >> temp->data;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p = root;
        struct node *q;
        while (p != NULL)
        {
            q = p;
            if (p->data < temp->data)
            {
                p = p->right;
            }
            else
            {
                p = p->left;
            }
        }
        if (q->data < temp->data)
        {
            q->right = temp;
        }
        else
        {
            q->left = temp;
        }
    }
}

void inorderTraversal(struct node *p)
{
    if (p == NULL)
    {
        cout << "\nEMPTY TREE \n";
    }
    else
    {
        if (p->left != NULL)
        {
            inorderTraversal(p->left);
        }
        cout << p->data << " ";
        if (p->right != NULL)
        {
            inorderTraversal(p->right);
        }
    }
}

void preorderTraversal(struct node *p)
{

    cout << p->data << " ";
    if (p->left != NULL)
    {
        preorderTraversal(p->left);
    }
    if (p->right != NULL)
    {
        preorderTraversal(p->right);
    }
}

void postorderTraversal(struct node *p)
{
    if (p->left != NULL)
    {
        postorderTraversal(p->left);
    }
    if (p->right != NULL)
    {
        postorderTraversal(p->right);
    }
    cout << p->data << " ";
}

int height = 0;
int heightOfTree(struct node *p)
{
    if (p->left != NULL)
    {
        height++;
        heightOfTree(p->left);
    }

    if (p->right != NULL)
    {
        height++;
        heightOfTree(p->right);
    }
    return height;
}

int minValue(struct node *p)
{
    int min = p->data;
    while (p != NULL)
    {
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->left;
    }
    return min;
}

int maxValue(struct node *p)
{
    int max = 0;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->right;
    }
    return max;
}

int flag = 0;
void search1(struct node *p, int data)
{
    while (p != NULL)
    {
        if (p->data == data)
        {
            flag = 1;
            break;
        }
        if (p->data < data)
        {
            p = p->right;
        }

        if (p->data > data)
        {
            p = p->left;
        }
    }
    if (flag == 1)
    {
        cout << "FOUND";
    }
    else
    {
        cout << "NOT FOUND";
    }
}

void mirror(struct node *p)
{
    struct node *temp;
    if (p != NULL)
    {
        mirror(p->left);
        mirror(p->right);
        node *temp = p->left;
        p->left = p->right;
        p->right = temp;
    }
}

int flag1 = 0;
void deleteNode(struct node *p, int data)
{
    struct node *q;
    while (p != NULL)
    {
        q = p;
        if (p->data < data)
        {
            p = p->right;
        }
        if (p->data > data)
        {
            p = p->left;
        }
        if (p->data == data)
        {
            flag1 = 1;
            break;
        }
        else if (p == NULL)
        {
            cout << "\nNO NOde FOUND\n";
            break;
        }
    }

    if (flag1 == 1)
    {
        while (1)
        {
            // Condition 1
            if (p == q && p->left == NULL && p->right == NULL)
            {
                root = NULL;
                delete p;
                break;
            }


            // Condition 2
            if (p == q && p->left != NULL && p->right == NULL)  
            {
                p->data = p->left->data;
                p->left = NULL;
                struct node *r = p->left;
                delete r;       
                break;
            }
            // Condition 3
            if (p == q && p->left == NULL && p->right != NULL)  
            {
                p->data = p->right->data;
                p->right = NULL;
                struct node *r = p->right;
                delete r;
                break;
            }


            // Condition 4
            if (p != q && p->left == NULL && p->right == NULL)  //To delete leaf node
            {
                if (q->right == p)
                {
                    q->right = NULL;
                    delete p;
                    break;
                }
                if (q->left == p)
                {
                    q->left = NULL;
                    delete p;
                    break;
                }
            }


            // Condition 5
            if (p->right != NULL && p->left == NULL)  //To delete node with one child
            {
                if (q->right == p)
                {
                    q->right = p->right;
                    p->right = NULL;
                    delete p;
                    break;
                }
                if (q->left == p)
                {
                    q->left = p->right;
                    p->right = NULL;
                    delete p;
                    break;
                }
            }
            // Condition 6
            if (p->right == NULL && p->left != NULL)
            {
                if (q->right == p)
                {
                    q->right = p->left;
                    p->left = NULL;
                    delete p;
                    break;
                }
                if (q->left == p)
                {
                    q->left = p->left;
                    p->left = NULL;
                    delete p;
                    break;
                }
            }


            // Condition 7
            if (p->right != NULL && p->left != NULL)
            {
                struct node *t = p;
                struct node *r;
                p = p->right;
                int min = p->data;
                while (p != NULL)
                {
                    if (p->data < min)
                    {
                        min = p->data;
                        r = p;
                    }
                    p = p->left;
                }
                deleteNode(root, min);
                t->data = min;
                break;
            }
        }
    }
}

int main()
{
    int n, nodes, value, no;
    for (char y = 'y'; y == '1' || y == 'y' || y == 'Y';)
    {
        cout << "\nENTER YOUR CHOICE\n1]ADD NODES\n2]DISPLAY TRAVERSAL\n3]LARGEST ELEMENT\n4]SMALLEST ELEMENT\n5]HEIGHT OF TREE\n6]SEARCH ELEMENT\n7]SWAP POINTERS\n8]DELETE NODE\n";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "\nHOW MANY NODES YOU WANT TO ADD : ";
            cin >> nodes;
            for (int i = 0; i < nodes; i++)
            {
                addNode();
            }
            break;
        case 2:
            cout << "\nINORDER TRAVERSAL : ";
            inorderTraversal(root);
            cout << "\nPREORDER TRAVERSAL : ";
            preorderTraversal(root);
            cout << "\nPOSTORDER TRAVERSAL : ";
            postorderTraversal(root);
            break;
        case 3:
            cout << "\nLARGEST ELEMENT : " << maxValue(root);
            break;
        case 4:
            cout << "\nSMALLEST ELEMENT : " << minValue(root);
            break;
        case 5:
            cout << "\nHEIGHT OF TREE : " << heightOfTree(root);
            break;
        case 6:
            cout << "\nENTER ELEMENT TO BE SEARCHED : ";
            cin >> value;
            search1(root, value);
            break;
        case 7:
            cout << "\nINORDER TRAVERSAL(BEFORE) : ";
            inorderTraversal(root);
            cout << "\nMIRROR ELEMENTS : ";
            mirror(root);
            cout << "\nINORDER TRAVERSAL(AFTER) : ";
            inorderTraversal(root);
            break;
        case 8:
            cout << "\nENTER NODE VALUE TO DELETE : \n";
            cin >> no;
            deleteNode(root, no);
            inorderTraversal(root);
            break;
        default:
            cout << "\nINVALID CHOICE";
        }
        cout << "\nENTER 1 TO CONTINUE : ";
        cin >> y;
    }
    return 0;
}