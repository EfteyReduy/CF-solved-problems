#include<bits/stdc++.h>

using namespace std;


struct Node{
    int data;
    Node* next;
};

int main()
{

    Node* head=NULL;
    int n;
    cout<<"Enter total number of data to enter into the linked list : ";
    cin>>n;
    cout<<"Enter data into the linked list : "<<endl;
    for(int i=0; i<n; i++)
    {
        Node* node=new Node;
        int a;
        cin>>a;
        node->data=a;
       // ptr=head;
        node->next=head;
        head=node;
    }
    Node* ptr=new Node;
    ptr=head;
    cout<<"The current linked list looks like this : ";
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
    cout<<"Reversed Linked list is: ";
    ptr=head;
    head=NULL;
    while(ptr!=NULL)
    {
        Node* rev=new Node;
        rev->data=ptr->data;
        rev->next=head;
        head=rev;
        ptr=ptr->next;
    }
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
