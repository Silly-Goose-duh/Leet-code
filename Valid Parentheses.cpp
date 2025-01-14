class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // create an empty stack to store opening brackets
        for (char c : s) { // loop through each character in the string
            if (c == '(' || c == '{' || c == '[') { // if the character is an opening bracket
                st.push(c); // push it onto the stack
            } else { // if the character is a closing bracket
                if (st.empty() || // if the stack is empty or 
                    (c == ')' && st.top() != '(') || // the closing bracket doesn't match the corresponding opening bracket at the top of the stack
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    return false; // the string is not valid, so return false
                }
                st.pop(); // otherwise, pop the opening bracket from the stack
            }
        }
        return st.empty(); // if the stack is empty, all opening brackets have been matched with their corresponding closing brackets,
                           // so the string is valid, otherwise, there are unmatched opening brackets, so return false
    }
};

/* 

MY CODE [ runtime 0ms but 77/100 testcases was done ]


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int top = -1;
char stack[10];

// Function to push an element onto the stack
void push(char element) {
    if (top < 9) { // Check to avoid stack overflow
        stack[++top] = element;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top >= 0) { // Check to avoid stack underflow
        return stack[top--];
    }
    return '\0'; // Return null character if stack is empty
}

// Function to check if brackets are valid
bool isValid(char* s) {
    int i = 0;
    while (s[i] != '\0') { // Iterate through the string until the null terminator
        switch (s[i]) {
            case '(':
            case '[':
            case '{':
                push(s[i]);
                break;
            case ')':
                if (top == -1 || pop() != '(') return false;
                break;
            case ']':
                if (top == -1 || pop() != '[') return false;
                break;
            case '}':
                if (top == -1 || pop() != '{') return false;
                break;
            default:
                break;
        }
        i++;
    }
     if(top==-1)
        return true;
    else
        return false;
}


// THE BELOW CODE DOES 99/100 TESTCASES:

#include <stdbool.h>

#define MAX 1000

// Stack data structure for storing characters
typedef struct {
    char items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, char c) {
    if (stack->top < MAX - 1) {
        stack->items[++(stack->top)] = c;
    }
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[(stack->top)--];
    }
    return '\0';
}

// Function to check if a string contains valid parentheses
bool isValid(char* s) {
    Stack stack;
    initStack(&stack);
    
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        
        // If the character is an opening bracket, push it onto the stack
        if (c == '(' || c == '{' || c == '[') {
            push(&stack, c);
        } 
        // If the character is a closing bracket, check if it matches the top of the stack
        else {
            if (isEmpty(&stack) || 
                (c == ')' && pop(&stack) != '(') || 
                (c == '}' && pop(&stack) != '{') || 
                (c == ']' && pop(&stack) != '[')) {
                return false;
            }
        }
    }

    // If the stack is empty, all opening brackets have been matched
    return isEmpty(&stack);
}
*/
