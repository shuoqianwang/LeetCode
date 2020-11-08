class Solution {
public:
    bool checkOrder(string fst, string snd, int* vec) {
        int flag;
        for (int i = 0; i < min(fst.size(), snd.size()); i++) {
            flag = vec[snd[i] - 'a'] - vec[fst[i] - 'a'];
            if (flag == 0)
                continue;
            else if (flag > 0)
                break;
            else return false;
        }
        if (flag == 0 && fst.size() > snd.size())
            return false;
        return true;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        int vec[26] = {0};
        for (int i = 0; i < order.size(); i++)
            vec[order[i] - 'a'] = i;
        for (auto it = words.begin(); it != words.end() - 1; it++)
            if (!checkOrder(*it, *(it + 1), vec))
                return false;
        return true;
    }
};
