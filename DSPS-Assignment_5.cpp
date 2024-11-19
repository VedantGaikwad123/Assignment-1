#include<iostream>
#include<stack>
#include<string>
using namespace std;

int precedence(char c) {
if (c == '^') {
return 3;
} 
else if (c == '*' || c == '/') {
return 2;
} 
else if (c == '+' || c == '-') {
return 1;
} 
else {
return -1;
}
}

bool isOperand(char c) {
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
return true;
}
return false;
}

string infixToPostfix(string s) {
stack<char> st;
string result;
for (int i = 0; i < s.length(); i++) {
char c = s[i];
if (isOperand(c)) {
result += c;
} 
else if (c == '(') {
st.push(c);
} 
else if (c == ')') {
while (!st.empty() && st.top() != '(') {
result += st.top();
st.pop();
}
if (!st.empty()) {
st.pop();
}
} 
else {
while (!st.empty() && precedence(c) <= precedence(st.top())) {
result += st.top();
st.pop();
}
st.push(c);
}
}
while (!st.empty()) {
result += st.top();
st.pop();
}
return result;
}

int main() {
string exp;
cout << "Enter the infix expression: ";
cin >> exp;
cout << "Postfix Expression: " << infixToPostfix(exp) << endl;
return 0;
}
