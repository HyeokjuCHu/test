#include <iostream>

using namespace std;

// Define your node structure
struct node {
    string name;
    double score;
    node* left;
    node* right;

    // Constructor for convenience
    node(string n, double s) : name(n), score(s), left(nullptr), right(nullptr) {}
};

// Custom stack-like structure for node pointers
class MyStack {
private:
    node** arr;
    int capacity;
    int top_index;

public:
    MyStack(int cap) : capacity(cap), top_index(-1) {
        arr = new node*[capacity];
    }

    ~MyStack() {
        delete[] arr;
    }

    bool isEmpty() const {
        return top_index == -1;
    }

    void push(node* item) {
        if (top_index < capacity - 1) {
            arr[++top_index] = item;
        }
    }

    node* pop() {
        if (!isEmpty()) {
            return arr[top_index--];
        }
        return nullptr;
    }
};

// Define your tree class
class my_tree {
private:
    int node_count;
    node* root;

public:
    my_tree() : node_count(0), root(nullptr) {}

    int insert_root(node t);
    int insert_left(string tname, node t);
    int insert_right(string tname, node t);
    double score_sum();
    double score_average();
    void print_data_inorder();
    void print_data_preorder();
    void print_data_postorder();
    void nonrecursive_inorder();
    void print_data_levelorder();
};

void my_tree::nonrecursive_inorder() {
    if (root == nullptr) {
        return;
    }

    MyStack stack(100); // Custom stack with capacity

    node* current = root;

    while (current != nullptr || !stack.isEmpty()) {
        // Reach the leftmost node of the current subtree
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        // Current is now null, pop the top element from the stack
        current = stack.pop();

        // Print the current node's data
        cout << current->name << " : " << current->score << endl;

        // Move to the right child
        current = current->right;
    }
}

// Your other member functions (insert, print, etc.) go here

int main() {
    // Example usage
    my_tree tree;

    // Build your tree using insert methods

    // Traverse in-order non-recursively
    tree.nonrecursive_inorder();

    return 0;
}
/*
Equality Test
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
------
bool isSameTree(TreeNode* p, TreeNode* q) {
    // 두 트리가 모두 빈 트리인 경우
    if (p == nullptr && q == nullptr)
        return true;
    
    // 한 트리만 빈 트리인 경우
    if (p == nullptr || q == nullptr)
        return false;

    // 현재 노드의 값이 다른 경우
    if (p->val != q->val)
        return false;

    // 왼쪽 서브트리와 오른쪽 서브트리 재귀적으로 비교
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
------
int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    bool result = isSameTree(p, q);
    std::cout << "Two trees are " << (result ? "same." : "different.") << std::endl;

    return 0;
}

*/

/*
Node *root = NULL;
void Treecreate()
{
    Node *p, *t;
    Queue q;
    create(&q, 100);

    int x;
    printf("Enter root value");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while(!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child: %d", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("Enter right child: %d", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(Node *p)
{
    if (p)
    {
        printf("%d", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}


*/

/*
노드제거
Node * BinarySearchTree::removeSequence(Node *node, int _value){
    if(node==nullptr)return node;
    else if(node -> value > _value){
        node -> left=removeSequence(node->left,_value);
    }else if(node -> value <_value){
        node -> right = removeSequence(node -> right, _value);
    }else{
        Node *ptr =node;
        if(node -> right==nullptr&&node -> left ==nullptr){
            delete node;
            node=nullptr;
        }else if(node -> right==nullptr){
            node=node -> right;
            delete ptr;
        }else{
            ptr=searchMaxNode(node->left);
            node -> value = ptr -> value;
            node -> left = removeSequence(node -> left, ptr -> value);
        }
    }
    return node;
}

void BinarySearchTree::removeNode(int value){
    Node *ptr = root;
    removeSequence(ptr,value);
}

값 찾기
bool BinarySearchTree::searchValue(int value){
    Node *ptr= root;
    Node *tmpRoot =nullptr;
    while(ptr!=nullptr){
        if(ptr->value==value){
            cout<<"FOund"<<endl;
            return true;
        }else if(ptr -> value > value)
            ptr=ptr->left;
        else ptr=ptr->right;
    }
    cout<<"not found"<<endl;
    return false;
}
*/