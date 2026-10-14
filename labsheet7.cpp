#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// 8. Create Tree
Node* createTree() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    return root;
}

// 9. Inorder Traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// 10. Preorder Traversal
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// 11. Postorder Traversal
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// 12. All 3 Traversals
void allTraversals(Node* root) {
    cout << "\nInorder: "; inorder(root);
    cout << "\nPreorder: "; preorder(root);
    cout << "\nPostorder: "; postorder(root);
    cout << "\n";
}

// 13 & 15. Insert in BST
Node* insertBST(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->data) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

// 14. Search in BST
bool searchBST(Node* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;
    if (key < root->data) return searchBST(root->left, key);
    return searchBST(root->right, key);
}

// Helper: Minimum node dhundhne ke liye
Node* getMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

// 16, 17, 18. Delete in BST (Leaf, 1 Child, 2 Children)
Node* deleteBST(Node* root, int key) {
    if (root == NULL) return NULL;
    if (key < root->data) root->left = deleteBST(root->left, key);
    else if (key > root->data) root->right = deleteBST(root->right, key);
    else {
        // Case 1 & 2: 0 child (leaf) ya 1 child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: 2 children (Inorder successor)
        Node* temp = getMin(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

// 19. Height of Tree
int height(Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

// 20. Count Total Nodes
int countNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 21. Count Leaf Nodes
int countLeaf(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

// 22. Menu-driven Program
int main() {
    Node* root = NULL;
    int choice, val;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n2. Search\n3. Inorder\n4. Preorder\n5. Postorder\n";
        cout << "6. Delete\n7. Height\n8. Total Nodes\n9. Leaf Nodes\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            root = insertBST(root, val);
        } else if (choice == 2) {
            cout << "Enter value to search: ";
            cin >> val;
            if (searchBST(root, val)) cout << "Found!\n";
            else cout << "Not Found!\n";
        } else if (choice == 3) {
            cout << "Inorder: "; inorder(root); cout << "\n";
        } else if (choice == 4) {
            cout << "Preorder: "; preorder(root); cout << "\n";
        } else if (choice == 5) {
            cout << "Postorder: "; postorder(root); cout << "\n";
        } else if (choice == 6) {
            cout << "Enter value to delete: ";
            cin >> val;
            root = deleteBST(root, val);
            cout << "Deleted (if existed).\n";
        } else if (choice == 7) {
            cout << "Height: " << height(root) << "\n";
        } else if (choice == 8) {
            cout << "Total Nodes: " << countNodes(root) << "\n";
        } else if (choice == 9) {
            cout << "Leaf Nodes: " << countLeaf(root) << "\n";
        } else if (choice == 10) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}