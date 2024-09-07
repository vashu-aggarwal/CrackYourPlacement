/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
       if(!root) return NULL;
        
        Node* start=root;

        while(start){
            Node* curr=start;

            while(curr){
                if(curr->left){
                    curr->left->next=curr->right;
                }

                if(curr->right && curr->next){
                    curr->right->next=curr->next->left;
                }

                curr=curr->next;
            }

            start=start->left;
        }
    return root;
    }
};