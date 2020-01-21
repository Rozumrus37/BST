
#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* newnode(const int val) {
    Node  *temptree = new Node();
    temptree->left = temptree->right = nullptr;
    temptree->value = val;
    return temptree;
}

void insert(Node * &node, const int val) {

    if(node == nullptr)
        node = newnode(val);
    else if(node -> value <= val)
       insert(node -> right, val);
    else insert(node -> left, val);
}

int find_min(Node * node) {
    if(node->left == nullptr)
        return node->value;
    else return find_min(node -> left);

}

int find_max(Node * node) {
    if(node -> right == nullptr)
        return node->value;
    else return find_max(node -> right);
}

void Print (Node * node)
{
    if(node == nullptr) {
        return;
    }
    Print(node->left);
    cout << node->value << " ";
    Print(node->right);

}

bool find_node(Node * node, int val) {
    if(node == nullptr)
        return 0;
    if(node -> value == val) return 1;

    if(find_node(node -> left, val)) return 1;

    return find_node(node -> right, val);
}


int main() {
    int n;
    cin >> n;
    int a[n];

    cin >> a[0];
    Node *parent = newnode(a[0]);

    for(int i = 1; i < n; i++) {
        cin >> a[i];
        insert(parent, a[i]);
    }

    cout << find_min(parent) << endl;
    cout << find_max(parent) << endl;
    cout << find_node(parent, 10) << endl;

     Print(parent);

    return 0;
}