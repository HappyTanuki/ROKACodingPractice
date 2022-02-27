int ackermann(int m, int n){
    int stack[3][100] = {0, }, stackTop = -1;

    stack[0][++stackTop] = m;
    stack[1][stackTop] = n;
    stack[2][stackTop] = -1;
    
    while (stackTop != -1){
        m = stack[0][stackTop--];
        n = stack[1][stackTop + 1];

        if (m == 0){
            stack[0][++stackTop] = m;
            stack[1][stackTop] = n;
            stack[2][stackTop] = n + 1;
            if (stackTop == 0){
                stackTop = -1;
            }
            continue;
        }
        if (n == 0){
            stack[0][++stackTop] = m - 1;
            stack[1][stackTop] = 1;
            stack[2][stackTop] = -1;
            continue;
        }
        if (m >= 1 && n >= 1){
            stack[0][++stackTop] = m - 2;
            stack[1][stackTop] = -1;
            stack[2][stackTop] = -1;
            stack[0][++stackTop] = m;
            stack[1][stackTop] = n - 1;
            stack[2][stackTop] = -1;
            continue;
        }
        break;
    }

    return stack[2][0];
}