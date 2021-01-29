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


/**
迭代解法
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        Node *l = root;

        while (l -> left) {
            Node *head = l;
            while (head) {
                head -> left -> next = head -> right;

                if (head -> next) {
                    head -> right -> next = head -> next -> left;
                }
                head = head -> next;
            }
        l = l -> left;
        }
        return root;
    }
};


/**
递归解法
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !root -> left) return root;

        root -> left -> next = root -> right;

        if (root -> next)
            root -> right -> next = root -> next -> left;

        connect(root -> left);
        connect(root -> right);
        return root;

    }
};
