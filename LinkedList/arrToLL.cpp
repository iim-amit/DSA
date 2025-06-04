// Convert an Array to a Linked List

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
}
 int main(){
vector<int> arr = {12, 5, 7, 9, 3};
Node *head = convertArr2LL(arr);
// cout << head->data;
Node *temp = head;
while (temp)
{
    cout << temp->data << "";
    temp = temp->next;
}
}

