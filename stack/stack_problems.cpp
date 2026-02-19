#include <iostream>
#include <stack>
using namespace std;

// Reverse String
void reverseString(string str) {
    stack<char> s;

    for (char ch : str)
        s.push(ch);

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

// Balanced Parentheses
bool isBalanced(string str) {
    stack<char> s;

    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        else {
            if (s.empty()) return false;

            if ((ch == ')' && s.top() == '(') ||
                (ch == '}' && s.top() == '{') ||
                (ch == ']' && s.top() == '['))
                s.pop();
            else
                return false;
        }
    }
    return s.empty();
}

int main() {

    cout << "Reversed: ";
    reverseString("Stack");

    cout << "Balanced Check: "
         << (isBalanced("{[()]}") ? "Balanced" : "Not Balanced");

    return 0;
}
