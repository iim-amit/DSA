// Remove Duplicates from a sorted List 
// 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

// ✅ Define ListNode BEFORE using it in Solution
class ListNode {
public:
    int data;
    ListNode* next;

    // Constructor with data and next pointer
    ListNode(int data1, ListNode* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data
    ListNode(int data1) {
        data = data1;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr != nullptr) {
            while (curr->next && curr->data == curr->next->data) {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
        return head;
    }
};

int main() {
    // Example usage
    ListNode* node5 = new ListNode(3);
    ListNode* node4 = new ListNode(3, node5);
    ListNode* node3 = new ListNode(2, node4);
    ListNode* node2 = new ListNode(1, node3);
    ListNode* node1 = new ListNode(1, node2);

    Solution sol;
    ListNode* result = sol.deleteDuplicates(node1);

    // Print the result
    while (result != nullptr) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
/*delete the first node or head from the linked list

Node* removeHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;.
    delete temp;
    return head;
}*/ 
// Simple we move the Head to the 2nd node and set the initial head as temp and delete it

/* delete the tail of the linked list 
We Simple at the second last node we set the next as nullptr it becomes the last node and before this we delete the last node as it is free from the storage space

Node* removeTail(Node* head){
    if(head == NULL || head->next == Null) return Null;

    Node* temp = head;
    while(temp->next->next != Null){
    temp = temp->next:
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}
*/