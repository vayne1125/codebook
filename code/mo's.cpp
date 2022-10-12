int n,k = sqrt(n);    //每塊大小為k
struct query{
    int l,r,id;       //詢問的左界右界 以及 第幾筆詢問
    friend bool operator<(const query& lhs,const query& rhs){
        return lhs.l/k==rhs.l/k ? lhs.r<rhs.r : lhs.l<rhs.l;
    }    //先判斷是不是在同一塊 不同塊的話就比較塊的順序，否則比較右界r
};
	int num = 0;
int cnt[1'000'005], ans[30005];
vector<query> q;
void add(int index){ ... }    //新增元素到區間內
void sub(int index){ ... }    //從區間內移除元素
void solve(){
    sort(q.begin(),q.end());
    for(int i=0,l=-1,r=0;i<n;i++){
        while(l>q[i].l)    add(--l);
        while(r<q[i].r)    add(++r);    //記得要先做新增元素的
        while(l<q[i].l)    sub(l++);    //再做移除元素的
        while(r>q[i].r)    sub(r--);
        ans[q[i].id] = num;             //移到區間後儲存答案
}    }