int Sub(int n){
    int i, result = 0;
    for(i = 0; n - (i * 3) > 0; i++){
        result += n - (i * 3);
    }
    return result;
}