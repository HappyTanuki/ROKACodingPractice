int Factorial(int n){
    printf("Factorial(%d)\n", n);
    if(n <= 1) return(1);
    else return (n * Factorial(n - 1));
}