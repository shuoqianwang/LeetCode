struct TrieNode {
    bool isWord = false;
    unordered_map<char, TrieNode*> nodes;
};

class WordDictionary {
private:
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        if (word == "")
            return;
        TrieNode* cur = root;
        TrieNode* prev = cur;
        for (auto c : word) {
            auto it = cur->nodes.find(c);
            if (it != cur->nodes.end()) {
                prev = cur;
                cur = it->second;
            } else {
                TrieNode* node = new TrieNode();
                cur->nodes.insert(make_pair(c, node));
                prev = cur;
                cur = node;
            }
        }
        prev->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        bool out = false;
        if (word == "")
            return out;
        TrieNode* cur = root;
        for (auto c : word) {
            auto it = cur->nodes.find(c);
            if (it != cur->nodes.end()) {
                out = cur->isWord;
                cur = it->second;
            } else return false;
        }
        return out;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
 
