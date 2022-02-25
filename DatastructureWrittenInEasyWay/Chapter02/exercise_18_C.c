int ackermann(int m, int n){
    int stack[100] = {0, }, stackTop = -1;

    stack[++stackTop] = m;
    
    while (stackTop != -1){
        m = stack[stackTop--];

        if (m == 0){
            stack[++stackTop] = n + 1;
            if (stackTop == 0){
                stackTop = -1;
            }
            continue;
        }
        if (n == 0){
            stack[++stackTop] = m - 1;
            n = 1;
            continue;
        }
        if (m >= 1 && n >= 1){
            stack[++stackTop] = m - 2;
            stack[++stackTop] = m;
            n -= 1;
        }
    }

    return stack[0];
}