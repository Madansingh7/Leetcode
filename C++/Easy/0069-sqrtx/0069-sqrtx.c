int mySqrt(int x) {
    int count = 0;
    int odd = 1;
    while (x >= 0) {
        x = x - odd;
        odd = odd + 2;
        count++;
    }
    return count - 1;
}