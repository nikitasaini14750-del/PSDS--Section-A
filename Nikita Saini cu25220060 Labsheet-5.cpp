/*Labsheet-5 Nikita Saini CU25220060
1.
#include <iostream>
#include <string>
using namespace std;

class Stack {
    char arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char x) {
        arr[++top] = x;
    }

    char pop() {
        return arr[top--];
    }

    char peek() {
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;

    return 0;
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (char ch : infix) {

        // If operand, add directly to postfix
        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9')) {

            postfix += ch;
        }

        // Opening bracket
        else if (ch == '(') {
            s.push(ch);
        }

        // Closing bracket
        else if (ch == ')') {

            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }

            s.pop(); // Remove '('
        }

        // Operator
        else {
            while (!s.isEmpty() &&
                   precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }

            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
*/
/*2.
#include <iostream>
#include <stack>
using namespace std;

int main() {
    string postfix;
    stack<int> s;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            if (ch == '+') s.push(a + b);
            else if (ch == '-') s.push(a - b);
            else if (ch == '*') s.push(a * b);
            else if (ch == '/') s.push(a / b);
        }
    }

    cout << "Result = " << s.top();

    return 0;
}*/

//3. Binary Search Tree Implementation
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Insert a node
Node* insertNode(Node* root, int value) {

    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Find minimum value node
Node* findMin(Node* root) {

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

// Delete a node
Node* deleteNode(Node* root, int value) {

    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {

        // No left child
        if (root->left == NULL) {

            Node* temp = root->right;
            delete root;
            return temp;
        }

        // No right child
        else if (root->right == NULL) {

            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node has two children
        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {

    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(Node* root) {

    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(Node* root) {

    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {

    Node* root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\n\nDeleting 30...\n";

    root = deleteNode(root, 30);

    cout << "Inorder after deletion: ";
    inorder(root);

    return 0;
}