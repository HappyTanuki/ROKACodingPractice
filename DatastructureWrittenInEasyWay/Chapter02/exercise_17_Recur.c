int binomialCoefficient(int n, int r){
    if (r == 0 || r == n){
        return 1;
    }
    return binomialCoefficient(n - 1, r - 1) + binomialCoefficient(n - 1, r);
}