struct Node {
  Node* links[26];
  
  bool containsKey(char& ch) {
      return (links[ch-'a'] != NULL);
  }
  
  Node* getNextNode(char& ch) {
      return links[ch-'a'];
  }
  
  void putNewNode(char& ch, Node* node) {
      links[ch-'a'] = node;
  }
};

/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    int cnt = 0;
    Node* root = new Node();
    
    for(int i=0; i<s.length(); i++) {
        Node* node = root;
        for(int j=i; j<s.length(); j++) {
            if(!node->containsKey(s[j])) {
                cnt++;
                node->putNewNode(s[j], new Node());
            }
            node = node->getNextNode(s[j]);
        }
    }
    
    return cnt+1;
}