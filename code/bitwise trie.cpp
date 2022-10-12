struct trie {
    trie* nxt[2];  
    int cnt;   //how many number end at this node
    int sz;    //how many number's prefix include this node
    trie() :cnt(0), sz(0) {
        memset(nxt, 0, sizeof(nxt));
    }
};
//create new trie
trie* root = new trie();
void insert(int x){
    trie *now = root;  //start at root everytime
    for(int i=30;i>=0;i--){
        now->sz++;
        if(now->nxt[x>>i&1] == NULL){
            now->nxt[x>>i&1] = new trie();
        }
        now = now->nxt[x>>i&1]; / go to next
    }
    now->cnt++;
    now->sz++;
}