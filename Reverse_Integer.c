int reverse(int x) {
    int flag = 1, digit, out = 0;
    if (x < 0) {
        flag = -1;
        x = labs(x) > INT_MAX ? 0 : -x;
    }
    while (x != 0) {
        digit = x % 10;
        out = out <= (INT_MAX - digit) / 10 ? 10 * out + digit : 0;
        x /= 10;
    }
    return flag * out;
}
