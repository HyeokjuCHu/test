#include <iostream>
#include <string>
using namespace std;

#define YES 1
#define NO 0

int check(string str, int start, int end) {
    // Base case: If there is only one character or no character in the string
    if (start >= end) {
        return YES;
    }
    
    // If the characters at start and end indexes are not equal, it's not a palindrome
    if (str[start] != str[end]) {
        return NO;
    }
    
    // Recur for the remaining substring
    return check(str, start + 1, end - 1);
}

int main() {
    string input;
    int len;
    
    cout << "Input a string : ";
    cin >> input;
    
    len = input.size();
    
    if (check(input, 0, len - 1) == YES)
        cout << "Yes, it is a palindrome. \n";
    else
        cout << "No, it is not a palindrome. \n";
    
    return 0;
}
