class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<char> vec;
        auto it1 = num1.rbegin(), it2 = num2.rbegin();
        int flag = 0, sum;
        while (it1 != num1.rend() || it2 != num2.rend()) {
            int x = it1 == num1.rend() ? 0 : *it1++ - '0',
                y = it2 == num2.rend() ? 0 : *it2++ - '0';
            flag += x + y;
            sum = flag % 10;
            vec.push_back(sum + '0');
            flag /= 10;
        }
        if (flag != 0)
            vec.push_back(flag + '0');
        string s;
        while (!vec.empty()) {
            s.push_back(vec.back());
            vec.pop_back();
        }
        return s;
    }
};
