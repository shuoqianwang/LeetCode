class Solution {
public:
    bool check(string s, int i, int j, int count) {
        for (int k = i; k <= i + (j - i) / 2; k++) {
            if (s[k] != s[j - k + i]) {
                count--;
                if (count < 0) return false;
                return check(s, k + 1, j - k + i, count) || check(s, k, j - k + i - 1, count);
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int count = 1;
        for (int i = 0; i < s.size() / 2; i++) {
            int j = s.size() - 1 - i;
            if (s[i] != s[j]) {
                count--;
                if (count < 0) return false;
                return check(s, i + 1, j, count) || check(s, i, j - 1, count);
            }
        }
        return true;
    }
};
