struct trie {
    trie* nxt[26];
    int cnt;    //how many string end at this node
    int sz;     //how many string's prefix include this node
    trie() :cnt(0), sz(0) {
        memset(nxt, 0, sizeof(nxt));
    }
};
//create new trie
trie* root = new trie();
// O(|s|)
void insert(string& s) {
    trie* now = root;  //start at root everytime
    for (auto i : s) {
        now->sz++;
        if (now->nxt[i - 'a'] == NULL) {
            now->nxt[i - 'a'] = new trie();
        }
        now = now->nxt[i - 'a'];  //go to next letter
    }
    now->cnt++;
    now->sz++;
}
// O(|s|)
int query_prefix(string& s) {  //search how many prefix is s
    trie* now = root;     //start at root everytime
    for (auto i : s) {
        if (now->nxt[i - 'a'] == NULL) {
            return 0;
        }
        now = now->nxt[i - 'a'];
    }
    return now->sz;
}
int query_count(string& s) {  //search how many times s appear 
    trie* now = root;     //start at root everytime
    for (auto i : s) {
        if (now->nxt[i - 'a'] == NULL) {
            return 0;
        }
        now = now->nxt[i - 'a'];
    }
    return now->cnt;
}