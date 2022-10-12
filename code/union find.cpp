void init(){
    for(int i=0;i<n;i++)
        f[i]=i;
}
int find(int x){
    if(f[x] == x)    return x;
    f[x] = find(f[x]);    //make root as x's father
    return f[x];
}
void merge(int x,int y){
    x=find(x),y=find(y);
    if(x!=y)    f[y]=x;
}