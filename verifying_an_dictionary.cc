class Solution {
public:
    bool checkOrder(string fst, string snd, unordered_map<char, int> umap) {
        int flag = 0;
        for (int i = 0; i < min(fst.size(), snd.size()); i++) {
            flag = umap.at(snd[i]) - umap.at(fst[i]);
            if (flag == 0) {
                continue;
            } else if (flag > 0) {
                break;
            } else return false;
        }
        if (flag == 0 && fst.size() > snd.size())
            return false;
        return true;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> umap;
        for (int i = 0; i < order.size(); i++) {
            umap[order[i]] = i;
        }
        for (auto it = words.begin(); it + 1 != words.end(); it++) {
            if (!checkOrder(*it, *(it + 1), umap))
                return false;
        }
        return true;
    }
};
