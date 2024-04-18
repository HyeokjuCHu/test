/*#include <iostream>
using namespace std;

const int MAX_NODES = 10000;
int preorder[MAX_NODES];
int idx = 0;

// 이진 트리 노드 정의
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 이진 검색 트리에 노드를 삽입하는 함수
void insertTreeNode(TreeNode *&root, int val)
{
    if (root == nullptr)
    {
        root = new TreeNode(val);
    }
    else
    {
        if (val < root->val)
        {
            insertTreeNode(root->left, val);
        }
        else
        {
            insertTreeNode(root->right, val);
        }
    }
}

// 후위 순회 함수
void postorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    TreeNode *root = nullptr;

    // 전위 순회 결과를 입력받음
    int num;
    while (cin >> num)
    {
        preorder[idx++] = num;
    }

    // 입력받은 전위 순회 결과로 이진 검색 트리를 구성
    for (int i = 0; i < idx; ++i)
    {
        insertTreeNode(root, preorder[i]);
    }

    // 후위 순회 결과 출력
    postorder(root);

    return 0;
}
*/
#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string name;
    double score;
    node *left, *right;
    void set_data(string s, double n);
};

void node::set_data(string s, double n) {
    name = s;
    score = n;
    left = NULL;
    right = NULL;
}

class my_tree {
public:
    int node_count;
    node *root;
    my_tree();
    int insert_root(node t);
    int insert_left(string tname, node t);
    int insert_right(string tname, node t);
    double score_sum();
    double score_average();
    void print_data_inorder();
    void print_data_preorder(node *p);
    void print_data_postorder(node *p);
private:
    // Helper function for recursive node insertion
    int insert_node(node *p, string tname, node t, bool isLeft);
};

my_tree::my_tree() {
    node_count = 0;
    root = NULL;
}

int my_tree::insert_root(node t) {
    if (root != NULL)
        return 0;
    node *p = new node;
    *p = t;
    p->left = NULL;
    p->right = NULL;
    root = p;
    node_count++;
    return 1;
}

int my_tree::insert_left(string tname, node t) {
    return insert_node(root, tname, t, true);
}

int my_tree::insert_right(string tname, node t) {
    return insert_node(root, tname, t, false);
}

int my_tree::insert_node(node *p, string tname, node t, bool isLeft) {
    if (p == NULL)
        return 0;
    
    if (p->name == tname) {
        if (isLeft) {
            if (p->left != NULL)
                return -1;
            node *newNode = new node;
            *newNode = t;
            newNode->left = NULL;
            newNode->right = NULL;
            p->left = newNode;
        } else {
            if (p->right != NULL)
                return -1;
            node *newNode = new node;
            *newNode = t;
            newNode->left = NULL;
            newNode->right = NULL;
            p->right = newNode;
        }
        node_count++;
        return 1;
    } else {
        int result = insert_node(p->left, tname, t, isLeft);
        if (result != 0)
            return result;
        return insert_node(p->right, tname, t, isLeft);
    }
}

double sum_allnodes(node *p) {
    if (p == NULL)
        return 0;
    return sum_allnodes(p->left) + sum_allnodes(p->right) + p->score;
}

double my_tree::score_sum() {
    return sum_allnodes(root);
}

double my_tree::score_average() {
    if (node_count == 0)
        return 0;
    return score_sum() / node_count;
}

void inorder_print(node *p) {
    if (p == NULL)
        return;
    inorder_print(p->left);
    cout << p->name << " : " << p->score << "\n";
    inorder_print(p->right);
}

void my_tree::print_data_inorder() {
    inorder_print(root);
}

void my_tree::print_data_preorder(node *p) {
    if (p == NULL)
        return;
    cout << p->name << " : " << p->score << "\n";
    print_data_preorder(p->left);
    print_data_preorder(p->right);
}

void my_tree::print_data_postorder(node *p) {
    if (p == NULL)
        return;
    print_data_postorder(p->left);
    print_data_postorder(p->right);
    cout << p->name << " : " << p->score << "\n";
}

int main() {
    my_tree thetree;
    node tmp;

    tmp.set_data("Kim", 8.1);
    thetree.insert_root(tmp);
    tmp.set_data("Lee", 6.5);
    thetree.insert_left("Kim", tmp);
    tmp.set_data("Park", 8.3);
    thetree.insert_right("Kim", tmp);
    tmp.set_data("Choi", 7.2);
    thetree.insert_left("Lee", tmp);
    tmp.set_data("Ryu", 9.0);
    thetree.insert_right("Lee", tmp);
    tmp.set_data("Cho", 7.7);
    thetree.insert_right("Park", tmp);

    cout << "Score Sum : " << thetree.score_sum() << "\n";
    cout << "Score Average : " << thetree.score_average() << "\n";
    cout << "\nInorder Traversal Result:\n";
    thetree.print_data_inorder();
    cout << "\nPreorder Traversal Result:\n";
    thetree.print_data_preorder(thetree.root);
    cout << "\nPostorder Traversal Result:\n";
    thetree.print_data_postorder(thetree.root);

    return 0;
}
