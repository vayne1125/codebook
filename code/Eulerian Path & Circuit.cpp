//存在歐拉的條件

//歐拉迴路                  
//無向圖: 所有點的度數為偶數     
//有向圖: 所有點入度等於出度	   
                                                              
//歐拉路徑
//無向圖: 度數為奇數的點數量不超過2
//有向圖: 全部點的入度出度一樣,
//        或剛好一個點出度-1=入度,
//        另一點入度-1=出度,
//        其他點入度等於出度
//  且圖連通!!!! <反例> a->b b->a c->d d->c
vector<int> path;
void dfs(int x){
    while(!edge[x].empty()){
        int u = edge[x].back();
        edge[x].pop_back();
        dfs(u);
    }
    path.push_back(x);
}
 
int main(){
    build();
    dfs(st);
    reverse(path.begin(),path.end());
    for(int i:path)    cout<<i<<' ';
    cout<<endl;
}