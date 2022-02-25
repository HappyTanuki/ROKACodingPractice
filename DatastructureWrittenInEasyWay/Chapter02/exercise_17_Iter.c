int binomialCoefficient(int n, int r){
    int i = 0, result = 1;

    for(i = n; i >= (n - r + 1); i--){
        result *= i;
    }
    for(i = 1; i <= r; i++){
        result /= i;
    }

    return result;
}