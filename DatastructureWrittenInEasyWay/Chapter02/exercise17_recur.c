int BinomialCoefficient(int n, int k){
    if (k == 0 || k == n){
        return 1;
    }
    if (0 < k && k < n){
        return (BinomialCoefficient(n - 1, k - 1) + BinomialCoefficient(n - 1, k));
    }
}