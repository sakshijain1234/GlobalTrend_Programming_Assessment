#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node *converter(queue<string> &q)
{
    if (q.empty())
        return NULL;

    string s = q.front();
    q.pop();
    if (s == "NULL")
        return NULL;

    Node *root = new Node(stoi(s));
    root->left = converter(q);
    root->right = converter(q);

    return root;
}

Node *buildTree(const string &str)
{
    queue<string> q;
    stringstream ss(str);
    string s;

    while (getline(ss, s, ','))
    {
        q.push(s);
    }

    return converter(q);
}

int helper(Node *root, int &maxi)
{
    if (!root)
        return 0;

    int left = max(helper(root->left, maxi), 0);
    int right = max(helper(root->right, maxi), 0);

    maxi = max(maxi, root->data + left + right);

    return root->data + max(left, right);
}

// function to find the maximum path sum
int findMaxSum(Node *root)
{
    int maxi = INT_MIN;
    helper(root, maxi);
    return maxi;
}

int main()
{
    string treeString;
    getline(cin, treeString);
    Node *root = buildTree(treeString);
    cout << findMaxSum(root) << "\n";
    return 0;
}
