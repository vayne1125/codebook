//判斷負環 , 差分約束
//差分約束 :
//xj - xi <= k
//連接一條邊 連接一條邊(i,j), 權重為 k
//最後再設置一個起點 s,連向所有邊邊權為 0
//從起點 s,跑 SPFA,若出現負環則代表這組不等式無解

bool spfa(){
    deque<int> dq;
    dis[0]=0;
    dq.push_back(0);
    inq[0]=1;
    while(!dq.empty()){
        int u=dq.front();
        dq.pop_front();
        inq[u]=0;
        for(auto i:edge[u]){
            if(dis[i.first]>i.second+dis[u]){
                dis[i.first]=i.second+dis[u];
                len[i.first]=len[u]+1;
                if(len[i.first]>n)	return 1;
                if(inq[i.first])	continue;
                if(!dq.empty()&&dis[dq.front()]>dis[i.first])
                    dq.push_front(i.first);
                else
                    dq.push_back(i.first);
                inq[i.first]=1;
    }	}	}
    return 0;
}