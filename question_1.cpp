#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to reverse a linked list */
struct Node *reverseList(struct Node *head)
{
    if (!head || !head->next)
        return head;

    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n, l, firstdata;

    struct Node *head = NULL, *tail = NULL;

    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n != 0)
    {
        cout << "Enter the data for the first node: ";
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
    }

    for (int i = 1; i < n; i++)
    {
        cout << "Enter the data for node " << i + 1 << ": ";
        cin >> l;
        tail->next = new Node(l);
        tail = tail->next;
    }

    head = reverseList(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}