#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int calculate(char* s) {
    int result = 0;  // Current result
    int sign = 1;    // 1 means positive, -1 means negative
    int stackSize = 100;  // Initial stack size
    int *stack = (int *)malloc(stackSize * sizeof(int)); // Dynamic stack allocation
    int top = -1;    // Stack pointer

    if (!stack) {
        // Handle memory allocation failure
        return 0;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        // If the character is a digit
        if (isdigit(c)) {
            int num = 0;
            // Continue to build the full number
            while (i < strlen(s) && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;  // Adjust the index to prevent skipping the next character
            result += sign * num;
        }
        // If the character is a '+' operator
        else if (c == '+') {
            sign = 1;  // Set sign to positive
        }
        // If the character is a '-' operator
        else if (c == '-') {
            sign = -1; // Set sign to negative
        }
        // If the character is a '('
        else if (c == '(') {
            // If the stack is full, resize it
            if (top == stackSize - 1) {
                stackSize *= 2;  // Double the stack size
                stack = (int *)realloc(stack, stackSize * sizeof(int)); // Resize the stack
                if (!stack) {
                    return 0;  // Handle memory allocation failure
                }
            }

            // Push current result and sign to stack
            stack[++top] = result;
            stack[++top] = sign;
            result = 0;  // Reset result for the new sub-expression
            sign = 1;    // Reset sign to positive for inside parentheses
        }
        // If the character is a ')'
        else if (c == ')') {
            // Pop the sign and previous result from the stack
            result = stack[top--] * result + stack[top--];
        }
        // If the character is a space, simply skip it
        else if (c == ' ') {
            continue;
        }
    }

    free(stack); // Free the dynamically allocated memory for the stack
    return result;
}
