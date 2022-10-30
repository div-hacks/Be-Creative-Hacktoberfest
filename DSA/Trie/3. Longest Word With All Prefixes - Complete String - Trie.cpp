struct Node {
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char& ch) {
        return (links[ch-'a'] != NULL);
    }    
    Node* getNextNode(char& ch) {
        return links[ch-'a'];
    }    
    void putNewNode(char& ch, Node* node) {
        links[ch-'a'] = node;
    }    
    void markEnd() {
        flag = true;
    }    
    bool isEnd() {
        return flag;
    }
};

class Trie {
 private :
    Node* root;
    
public :
    
    Trie() {
        root = new Node();
    }
    
    void insert(string& word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->putNewNode(ch, new Node());
            }
            node = node->getNextNode(ch);
        }
        node->markEnd();
    }
    
    bool chkIfPrefExist(string& word) {
        Node* node = root;
        bool f = 1;
        for(char ch : word) {
            if(node->containsKey(ch)) {
                node = node->getNextNode(ch);
                if(!node->isEnd()) return false;
            }
            else return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    string ans = "";
    Trie* trie = new Trie();
    
    for(string s : a) {
        trie->insert(s);
    }
    
    for(string s : a) {
        if(trie->chkIfPrefExist(s)) {
            if(ans.length() < s.length()) ans = s;
            else if(ans.length() == s.length()) {
                if(s < ans) ans = s;
            }
        }
    }
 
    return ans == "" ? "None" : ans;
}