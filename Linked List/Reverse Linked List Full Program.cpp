************************************************APPROACH 1st*****************************************************
    
#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    
    Node(int new_data)
    {
        data = new_data;
        next = NULL;
    }
};

void printList(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node *reverseList(Node *head)
{
    Node *temp = head;
    Node *prev = NULL;
    
    while(temp != NULL)
    {
        Node *next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    cout<<"Before Reverse:";
    
    printList(head);
    
    cout<<"\nAfter Reverse:";
    
    head = reverseList(head);
    printList(head);
}


************************************************APPROACH 2nd********************************************************

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    
    Node(int new_data)
    {
        data = new_data;
        next = NULL;
    }
};

void printList(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseList(Node *head)
{
    Node *temp = head;
    Node *prev = NULL;
    
    while(temp != NULL)
    {
        Node *next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

Node* createList(int n)
{
    if(n <= 0) return NULL;

    int data;
    cout << "Enter value for node 1: ";
    cin >> data;
    Node *head = new Node(data);
    Node *current = head;

    for(int i = 2; i <= n; i++)
    {
        cout << "Enter value for node " << i << ": ";
        cin >> data;
        current->next = new Node(data);
        current = current->next;
    }
    
    return head;
}

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    Node *head = createList(n);

    cout << "Before Reverse: ";
    printList(head);
    
    head = reverseList(head);
    
    cout << "After Reverse: ";
    printList(head);
    
    return 0;
}
  
