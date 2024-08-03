***********************************************APPROACH 1st**************************************************

#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    
    Node(int newData)
    {
        data = newData;
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

Node *deleteList(Node *head,int k)
{
    Node *temp = head;
    Node *prev = NULL;
    
    if(k == 1)
    {
        return head->next;
    }
    while(temp != NULL)
    {
        if(temp->data == k)
        {
            prev->next = prev->next->next;
        }
        prev = temp;
        temp = temp->next;
    }
    
    return head;
}

int main()
{
    Node  *head = new  Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    int k;
    cout<<"Enter the value you want to delete:";
    cin>>k;
    cout<<"Before Delete:\n";
    printList(head);
    
    head = deleteList(head,k);
    
    cout<<"\nAfter Delete:\n";
    
    printList(head);   
}


**********************************************APPROACH 2nd******************************************************

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int newData) {
        data = newData;
        next = NULL;
    }
};

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* deleteList(Node *head, int k) {
    Node *temp = head;
    Node *prev = NULL;

    // Handle the case where the head node itself needs to be deleted
    if (head != NULL && head->data == k) {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }

    // Traverse the list to find the node to delete
    while (temp != NULL && temp->data != k) {
        prev = temp;
        temp = temp->next;
    }

    // If the node was found, delete it
    if (temp != NULL) {
        prev->next = temp->next;
        delete temp;
    }

    return head;
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k;
    cout << "Enter the value you want to delete: ";
    cin >> k;

    cout << "Before Delete:\n";
    printList(head);

    head = deleteList(head, k);

    cout << "\nAfter Delete:\n";
    printList(head);

    return 0;
}

  
