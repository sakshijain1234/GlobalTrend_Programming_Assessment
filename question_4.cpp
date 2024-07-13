#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Serialization
string serialize(TreeNode *root)
{
    if (!root)
        return "NULL";
    return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

TreeNode *helper(queue<string> &q)
{
    string s = q.front();
    q.pop();
    if (s == "NULL")
        return NULL;
    TreeNode *root = new TreeNode(stoi(s));
    root->left = helper(q);
    root->right = helper(q);
    return root;
}

// Deserialization
TreeNode *deserialize(string str)
{
    if (str.empty())
        return NULL; // Handle the case where the input string is empty

    queue<string> q;
    stringstream ss(str);
    string s;
    while (getline(ss, s, ','))
    {
        q.push(s);
    }
    return helper(q);
}

void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " "; // Uncommented this line to print the values
    inorder(root->right);
}

int main()
{
    string treeString;
    getline(cin, treeString);

    if (treeString.empty())
    {
        cout << "Input string is empty." << endl; // Added this line for better debugging
        return 0;
    }

    TreeNode *root = deserialize(treeString);
    cout << "After deserialization= " << endl;
    inorder(root);
    cout << endl; // To ensure the output is cleaner
    string serializedTree = serialize(root);
    cout << "After Serialized= " << serializedTree << endl;
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// // Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left, *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// // Serialization
// string serialize(TreeNode *root)
// {
//     // cout << "yes i am serialzing" << endl;
//     if (!root)
//         return "NULL";
//     return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
// }

// TreeNode *helper(queue<string> &q)
// {
//     // cout << "yes i am helping" << endl;
//     string s = q.front();
//     q.pop();
//     if (s == "NULL")
//         return NULL;
//     TreeNode *root = new TreeNode(stoi(s));
//     root->left = helper(q);
//     root->right = helper(q);
//     return root;
// }

// // Deserialization
// TreeNode *deserialize(string str)
// {
//     // cout << "yes i am deserialzing" << endl;
//     if (str.empty())
//         return NULL; // Handle the case where the input string is empty

//     queue<string> q;
//     stringstream ss(str);
//     string s;
//     while (getline(ss, s, ','))
//     {
//         q.push(s);
//     }
//     return helper(q);
// }

// void inorder(TreeNode *root)
// {
//     // cout << "yes i am printing" << endl;
//     if (!root)
//         return;
//     inorder(root->left);
//     // cout << root->val << " ";
//     inorder(root->right);
// }

// int main()
// {
//     string treeString;
//     getline(cin, treeString);

//     if (treeString.empty())
//     {
//         // cout << "Input string is empty." << endl;
//         return 0;
//     }

//     TreeNode *root = deserialize(treeString);
//     cout << "After deserialization= " << endl;
//     inorder(root);
//     cout << endl; // To ensure the output is cleaner
//     string serializedTree = serialize(root);
//     cout << "After Serialized= " << serializedTree << endl;
//     return 0;
// }
