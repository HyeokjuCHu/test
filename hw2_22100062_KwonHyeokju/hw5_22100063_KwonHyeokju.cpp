#include <iostream>
#include <string>
using namespace std;

string reverse(string input) {
    if (input.empty()) {
        return input;
    }
    return reverse(input.substr(1)) + input[0];
}

int main() {
    string input, r_input;

    cout << "Input a string : ";
    cin >> input;

    r_input = reverse(input);

    cout << r_input << endl;

    return 0;
}
