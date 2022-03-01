double Power(double x, int n){
    if (n == 0) return 1;
    else if ((n % 2) == 0){
        return Power(x * x, n/2);
    }
    else return x * Power(x * x, (n - 1) / 2);
}