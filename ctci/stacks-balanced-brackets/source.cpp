#include <stack>
#include <iostream>

using namespace std;

// returns true if char (arg) is an open bracket
bool isOpen(char c) {
    if (c == '[' || c == '{' || c == '(') 
        return true;
    else 
        return false;
}

// returns true if char a is the same bracket type as char b
bool isSameType(char a, char b) {
    switch(a) {
        case '}':
            return (b == '{');
        case ']':
            return (b == '[');
        case ')':
            return (b == '(');
    }
    return false;
}

bool is_balanced(string expression) {
    // if string length is odd, return false
    if (expression.length()%2 != 0) 
        return false;
    
    stack<char> brackets;
    
    brackets.push(expression[0]);
    for (int i = 1; i < expression.length(); i++) {
        if (isOpen(expression[i])) 
            brackets.push(expression[i]);
        else {
            if (brackets.empty()) return false;
            else if (!isSameType(expression[i], brackets.top())) return false;
            else brackets.pop();
        }
    }
    
    if (brackets.empty()) 
        return true;
    else 
        return false;
    
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
