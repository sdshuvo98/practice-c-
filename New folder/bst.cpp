#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int value;
    node* Right;
    node* Left;
};

class BST
{
public:
    node* root;

    BST()
    {
        root = NULL;
    }

    node* CreateNewNode(int value)
    {
        node* newNode = new node;
        newNode->value = value;
        newNode->Right = NULL;
        newNode->Left = NULL;
        return newNode;
    }
    void BFS()
    {
        queue<node*>q;
        q.push(root);

        while(!q.empty())
        {
            node* a = q.front();
            q.pop();
            int p = -1, l = -1, r = -1;
            if(a->Left != NULL)
            {
                l = a->Left->value;
                q.push(a->Left);
            }
            if(a->Right != NULL)
            {
                r = a->Right->value;
                q.push(a->Right);
            }
            cout << "Node value = " << a->value << " Left child = " << l << " Right child = " << r << "\n";
        }
    }
    void Insert(int value)
    {
        node* newNode = CreateNewNode(value);

        if(root == NULL)
        {
            root = newNode;
            return;
        }

        node* cur = root;
        node* prv = NULL;

        while(cur != NULL)
        {
            if(newNode->value > cur->value)
            {
                prv = cur;
                cur = cur->Right;
            }
            else
            {
                prv = cur;
                cur = cur->Left;
            }
        }
        if(newNode->value > prv->value)
            prv->Right = newNode;
        else
            prv->Left = newNode;
    }
    bool Search(int value)
    {
        node* cur = root;
        while(cur != NULL)
        {
            if(value > cur->value)
                cur = cur->Right;
            else if(value < cur->value)
                cur = cur->Left;
            else
                return true;
        }
        return false;
    }
    void Delete(int value)
    {
        node* cur = root;
        node* prv = NULL;

        while(cur != NULL)
        {
            if(value > cur->value)
            {
                prv = cur;
                cur = cur->Right;
            }
            else if(value < cur->value)
            {
                prv = cur;
                cur = cur->Left;
            }
            else
                break;
        }
        if(cur == NULL)
        {
            cout << "Value is not present in BST\n";
            return;
        }
        // Case 1: no child
        if(cur->Left == NULL && cur->Right == NULL)
        {
            if(prv->Left->value == cur->value)
                prv->Left = NULL;
            else
                prv->Right = NULL;
            delete cur;
            return;
        }
        // Case 2: node has one child
        if(cur->Left == NULL && cur->Right != NULL)
        {
            if(prv->Left->value == cur->value)
                prv->Left = cur->Right;
            else
                prv->Right = cur->Right;
            delete cur;
            return;
        }
        if(cur->Left != NULL && cur->Right == NULL)
        {
            if(prv->Left->value == cur->value)
                prv->Left = cur->Left;
            else
                prv->Right = cur->Left;
            delete cur;
            return;
        }
        // Case 3: node has two child
        node* tmp = cur->Right;
        while(tmp->Left != NULL)
            tmp = tmp->Left;
        int saved = tmp->value;
        Delete(saved);
        cur->value = saved;
    }
    void Inorder(node* a)
    {
        if(a == NULL)
            return;
        Inorder(a->Left);
        cout << a->value << " ";
        Inorder(a->Right);
    }
    void Preorder(node* a)
    {
        if(a == NULL)
            return;
        cout << a->value << " ";
        Preorder(a->Left);
        Preorder(a->Right);
    }
    void Postorder(node* a)
    {
        if(a == NULL)
            return;
        Postorder(a->Left);
        Postorder(a->Right);
        cout << a->value << " ";
    }

};

int main()
{
    BST bst;
    bst.Insert(20);
    bst.Insert(10);
    bst.Insert(22);
    bst.Insert(5);
    bst.Insert(12);
    bst.Insert(21);
    bst.Insert(25);
    bst.Insert(3);
    bst.Insert(15);

    bst.BFS();

//    cout << bst.Search(9) << "\n";
//    cout << bst.Search(7) << "\n";

//    bst.Delete(5);
//    bst.Delete(7);
//    bst.Delete(6);
//    bst.BFS();
//    bst.Inorder(bst.root);
//    bst.Preorder(bst.root);
    bst.Postorder(bst.root);

    return 0;
}
