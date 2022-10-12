void dijkstra(int startPoint,int endPoint){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    v.clear();v.resize(n);
    dis.clear();dis.resize(n,INF);
    dis[startPoint]=0;
    pq.push({dis[startPoint],startPoint});//push startpoint into pq
    while(!pq.empty()){//if pq is not empty then continue
       auto u=pq.top();pq.pop();  //pop the point that is closet to startpoint everytime
       if(v[u.second]) continue; //if the point is visited represent there already have shorter path and dont have to walk again
       v[u.second]=1;       //set the point visited
       for(auto i:edge[u.second]){
          if(dis[i.first]>u.first+i.second){//determine whether it can relax
              dis[i.first]=u.first+i.second;    
              pq.push({dis[i.first],i.first});//connect the path that can relax 
          }
       }
    }
    cout<<dis[endPoint]<<endl;
}
