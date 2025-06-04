/**
 * REMOVE N NODE FROM THE LAST
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 //Leet Code
/*class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0;i<n;i++) fast = fast->next;
        if(fast == NULL) return head->next;
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};
Here we simply create two pointers 
Hint-Maintain two pointers and update one with a delay of n steps.
n is given 
after n steps , 
we simple point the previous->next=previous->next->next;
before this we point that node as del node (because we have to delete it after connecting the nodes)
*/
// SINGLY LINKED LIST
#include<bits/stdc++.h>
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
Node* removeK(Node* head, int k){
    if(head ==NULL) return head;
    if(k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
void print(Node* head){
    while(head != NULL){
        cout << head->data << "";
        head = head->next;
    }
}

int main(){
    vector<int> arr = {12,5,7,9,3};
    Node* head = convertArr2LL(arr);
    head = removeK(head, 1);
    cout << head;
}

/*Insert New Node at the Head
// function
Node* inserthead(Node* head,int val){
    return new Node(val, head);
}
    
    
    
    in main()
    head = insertHead(head, 100);
    */


/*Insert New Node at Last
Node* insertTail(Node* head, int  val){
    if(head == NULL){
    return new Node(val);
}
    Node* temp = head;
    while(temp->next != Null){
    temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
    }
*/

/* Insert New Node at K position
    Node* insertPosition(Node* head, int el, int k){
    if(head == NULL){
        if(k == 1){
            return new Node(el);
            }
        else{
            return head;
            }
        }
        if(k == 1){
        return new Node(el, Head);
        }
        int cnt = 0;
        Node* temp = head;
        while(temp != NULL){
        cnt++;
        if(cnt == k-1){
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
            }
        temp = temp->next;
        }
        return head;
    }
*/

/* Insert New Node before the value
    Node* insertBeforeValue(Node* head, int el, int val){
    if(head == NULL){
        return NULL:
        }
        if(head->data == val){
        return new Node(el, Head);
        }
        
        Node* temp = head;
        while(temp != NULL){
        
        if(temp->next->data == val){
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
            }
        temp = temp->next;
        }
        return head;
    }    
*/