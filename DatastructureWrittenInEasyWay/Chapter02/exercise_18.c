int ackermann(int m, int n){
    if(m == 0){
        return n + 1;
    }
    if(n == 0){
        return ackermann(m - 1, 1);
    }
    if (m >= 1 && n >= 1){
        return ackermann(m - 2, ackermann(m, n - 1));
    }
}