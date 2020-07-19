
int height(node *N)
{
    if (N == NULL)
        return -1;

    return N->ht;
}

void setHeight(node *nd)
{
    if (nd == NULL) nd->ht = -1;
    else nd->ht = max(height(nd->left), height(nd->right)) + 1;
}

node* newNode(int key)
{
    node* nod = new node();
    nod->val = key;
    nod->left = NULL;
    nod->right = NULL;
    setHeight(nod);
    return (nod);
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;
    x->right = y;
    y->left = T2;
    setHeight(x);
    setHeight(y);
    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;
    y->left = x;
    x->right = T2;
    setHeight(x);
    setHeight(y);
    return y;
}

int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

node * insert(node * root, int val)
{
    if (root == NULL) return newNode(val);
    if (root->val < val)
    {
        root->right = insert(root->right, val);
    }
    else if (root->val > val)
    {
        root->left = insert(root->left, val);
    }
    else return root;
    setHeight(root);

    int balance = getBalance(root);
    if (balance > 1 && val < root->left->val)
        return rightRotate(root);
    if (balance < -1 && val > root->right->val)
        return leftRotate(root);
    if (balance > 1 && val > root->left->val)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && val < root->right->val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}