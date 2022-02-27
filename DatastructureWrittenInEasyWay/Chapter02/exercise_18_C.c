int ackermann(int m, int n){
    int stack[2][100000] = {0, }, stackTop = -1;

    stack[0][++stackTop] = m;
    stack[1][stackTop] = n;
    
    while (stackTop >= 0){
        m = stack[0][stackTop];
        n = stack[1][stackTop];
        stackTop--;

        if (m == 0){
            if (stackTop < 0){
                return n + 1;
            }
            stack[1][stackTop] = n + 1;
            continue;
        }
        if (n == 0 && m > 0){
            stackTop++;
            stack[0][stackTop] = m - 1;
            stack[1][stackTop] = 1;
            continue;
        }
        if (m > 0 && n > 0){
            stackTop++;
            stack[0][stackTop] = m - 1;
            stack[1][stackTop] = -2;
            stackTop++;
            stack[0][stackTop] = m;
            stack[1][stackTop] = n - 1;
            continue;
        }
        stack[1][stackTop] = 0;
    }
}