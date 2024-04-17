#include <iostream>
#include <string>

#define SIZE 100
#define EOS '$'

using namespace std;

class op_stack {
    char s[SIZE];
    int top;
public:
    op_stack();
    void push(char x);
    char pop();
    bool empty();
    char top_element();
};

op_stack::op_stack() {
    top = 0;
}

void op_stack::push(char x) {
    s[top++] = x;
}

char op_stack::pop() {
    return(s[--top]);
}

bool op_stack::empty() {
    return (top == 0);
}

char op_stack::top_element() {
    return (s[top - 1]);
}

bool is_operand(char ch) {
    if ((ch == '(') || (ch == ')') ||
        (ch == '+') || (ch == '-') ||
        (ch == '*') || (ch == '/') ||
        (ch == '%') || (ch == '$'))
        return true;
    else
        return false;
}

int get_precedence(char op) {
    if (op == '$' || op == '(')
        return 0;
    else if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else
        return -1;
}

int main() {
    string input, output;
    op_stack stack1;
    cout << "Input an infix expression to convert: ";
    cin>>input;
    

    input += EOS; // 선택 사항 : input 끝에 eos 추가
    stack1.push(EOS);

    for (int i = 0; i < input.size(); i++) {
        char ch = input[i];
        if (ch == ' ' || ch == '\t')
            continue;
        else if (isalnum(ch))
            output += ch;
        else if (is_operand(ch)) {
            while (!stack1.empty() && get_precedence(stack1.top_element()) >= get_precedence(ch) && stack1.top_element() != '(') {
                output += stack1.pop();
            }
            if (ch != ')')
                stack1.push(ch);
        }
        else if (ch == '(') {
            stack1.push(ch);
        }
        else if (ch == ')') {
            while (stack1.top_element() != '(') {
                output += stack1.pop();
            }
            stack1.pop();
        }
    }

    while (!stack1.empty()) {
        output += stack1.pop();
    }

    cout << output << endl;

    return 0;
}
