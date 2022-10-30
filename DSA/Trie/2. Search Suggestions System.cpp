struct Node {
    Node* links[26];
    vector<int> indices;
    
    bool containsKey(char ch) {
        return (links[ch-'a'] != NULL);
    }
    
    Node* getNextNode(char ch) {
        return (links[ch-'a']);
    }
    
    void putNewNode(char ch, Node* node) {
        links[ch-'a'] = node;
    }
    
    void addIdx(int idx) {
        indices.push_back(idx);
    }
    
    vector<int> getIdx() {
        return indices;
    }
};

class Trie {
private : 
    Node* root;
    
public : 
    
    Trie() {
        root = new Node();
    }
    
    void insert(string& key, int idx) {
        Node* node = root;
        for(char ch : key) {
            if(!node->containsKey(ch)) {
                node->putNewNode(ch, new Node());
            }
            node = node->getNextNode(ch);
            node->addIdx(idx);
        }
    }
    
    vector<int> search(string& key) {
        Node* node = root;
        for(char ch : key) {
            if(!node->containsKey(ch)) {
                return {};
            }
            node = node->getNextNode(ch);
        }
        
        vector<int> ans = node->getIdx();
        if(ans.size() > 3) {
            ans = {ans[0], ans[1], ans[2]};
        }
        
        return ans;
    }
    
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& vs, string searchWord) {
        
        int n = vs.size();
        sort(vs.begin(), vs.end());
        
        Trie* trie = new Trie();       
                       
        for(int i=0; i<n; i++) {
            trie->insert(vs[i], i);
        }
        
        vector<vector<string>> ans;
        string s = "";
        
        for(int i=0; i<searchWord.length(); ++i) {
            s += searchWord[i];
            vector<int> prefixIdx = trie->search(s);
            vector<string> tmp;
            
            for(int it : prefixIdx) {
                tmp.push_back(vs[it]);
            }
            
            ans.push_back(tmp);
        }
        
        return ans;
        
    }
};