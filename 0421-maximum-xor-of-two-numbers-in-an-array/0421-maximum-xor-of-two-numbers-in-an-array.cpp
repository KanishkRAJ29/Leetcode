class Node{
    public:
    vector<Node*>arr;
    Node(){
       arr.resize(2,NULL);
    }
    bool contains(int bit){
        if(arr[bit]==NULL)return false;
        return true;
    }
    void put(int bit,Node* temp){
        arr[bit]=temp;
    }
    Node* get(int bit){
        return arr[bit];
    }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->contains(bit)){
                node=node->get(bit);
            }
            else{
                node->put(bit,new Node());
                node=node->get(bit);
            }
        }
        return ;
    }

    int getMax(int num){
        Node* node=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->contains(1-bit)){
                maxi=maxi|(1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxi;
    }

};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* obj=new Trie();
        for(int i=0;i<nums.size();i++){
            obj->insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int maxi=obj->getMax(nums[i]);
            ans=max(ans,maxi);
        }
        return ans;
    }
};