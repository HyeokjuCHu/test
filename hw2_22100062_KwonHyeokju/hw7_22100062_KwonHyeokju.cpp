#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char value) {
        data = value;
        next = nullptr;
    }
};

class op_stack {
    Node* top;

public:
    op_stack();
    ~op_stack();

    void push(char x);
    char pop();
    bool empty();
    char top_element();
};

op_stack::op_stack() {
    top = nullptr;
}

op_stack::~op_stack() {
    while (!empty()) {
        pop();
    }
}

void op_stack::push(char x) {
    Node* newNode = new Node(x);
    newNode->next = top;
    top = newNode;
}

char op_stack::pop() {
    if (empty()) {
        cout << "Error: Stack underflow\n";
        exit(EXIT_FAILURE);
    }
    Node* temp = top;
    char value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

bool op_stack::empty() {
    return (top == nullptr);
}

char op_stack::top_element() {
    if (empty()) {
        cout << "Error: Stack is empty\n";
        exit(EXIT_FAILURE);
    }
    return top->data;
}

bool is_opening_bracket(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

bool is_closing_bracket(char ch) {
    return ch == ')' || ch == ']' || ch == '}';
}

bool are_matching_brackets(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

void check_expression(const string& expression) {
    op_stack stack;
    for (char ch : expression) {
        if (is_opening_bracket(ch)) {
            stack.push(ch);
        } else if (is_closing_bracket(ch)) {
            if (stack.empty()) {
                cout << "Error: An extra parenthesis '" << ch << "' is found.\n";
                return;
            }
            char top_bracket = stack.top_element();
            if (!are_matching_brackets(top_bracket, ch)) {
                cout << "Error: mis-matched parenthesis, '" << top_bracket << "' is expected.\n";
                return;
            }
            stack.pop();
        }
    }

    if (!stack.empty()) {
        cout << "Error: An extra parenthesis '" << stack.top_element() << "' is found.\n";
    } else {
        cout << "It's a normal expression.\n";
    }
}

int main() {
    string expression;
    cout << "Enter an expression to check parentheses: ";
    getline(cin, expression);

    check_expression(expression);

    return 0;
}
