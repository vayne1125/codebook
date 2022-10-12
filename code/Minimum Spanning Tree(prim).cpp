void prim(){
    v.clear();v.resize(n);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0,0});
    ll sum=0;
    while(!pq.empty()){
        auto u=pq.top();pq.pop();
        if(v[u.second]) continue;
        v[u.second]=1;
        sum+=u.first;
        for(auto i:edge[u.second]){
            if(!v[i.first]){
                pq.push({i.second,i.first});
            }
        }
    }
    cout<<sum<<endl;
}