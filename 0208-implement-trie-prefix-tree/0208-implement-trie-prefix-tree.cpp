class TrieNode{
public:
    TrieNode* arr[26];
    bool reachEnd;
    TrieNode(){
        reachEnd=false;
        for(int i=0;i<26;i++){
            arr[i]=NULL;
        }
    }
    bool contains(char c){
        return arr[c-'a']!=NULL;
    }
    void put(char c,TrieNode* node){
        arr[c-'a']=node;
        return;
    }
    TrieNode* get(char c){
        return arr[c-'a'];
    }
    void setEnd(){
        reachEnd=true;
        return;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr=root;
        for(char c:word){
            if(!curr->contains(c)){
                curr->put(c,new TrieNode());
            }
            curr=curr->get(c);
        }
        curr->setEnd();
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        for(char c:word){
            if(!curr->contains(c)){
                return false;
            }
            curr=curr->get(c);
        }
        return curr->reachEnd==true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        for(char c: prefix){
            if(!curr->contains(c)){
                return false;
            }
            curr=curr->get(c);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */