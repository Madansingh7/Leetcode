int calculate(char *s) {
      int n = strlen(s);

    // stack to store intermediate results
    int stack[n];
    int top = -1;

    int num = 0;     // current number being formed
    char sign = '+'; // previous operator (default '+')

    for (int i = 0; i < n; i++) {
        char ch = s[i];

        //If digit
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        }

        //if operator OR last character
        if ((!isdigit(ch) && ch != ' ') || i == n - 1) {

            // Apply previous sign
            if (sign == '+') {
                stack[++top] = num;   // push number
            } 
            else if (sign == '-') {
                stack[++top] = -num;  // push negative number
            } 
            else if (sign == '*') {
                stack[top] = stack[top] * num; // multiply with top
            } 
            else if (sign == '/') {
                stack[top] = stack[top] / num; // divide with top
            }

            // Update sign to current operator
            sign = ch;

            // Reset number
            num = 0;
        }
    }

    //Final result
    int res =0;
    for (int i = 0; i <= top; i++) {
        res += stack[i];
    }

    return res;
}