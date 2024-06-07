class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word = "";
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->word = word;
    }
    
    string searchRoot(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.count(c)) {
                node = node->children[c];
                if (node->word != "") {
                    return node->word;
                }
            } else {
                break;
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (string& word : dictionary) {
            trie.insert(word);
        }
        
        stringstream ss(sentence);
        string word;
        string result = "";
        
        while (ss >> word) {
            if (result != "") {
                result += " ";
            }
            result += trie.searchRoot(word);
        }
        
        return result;
    }
};
