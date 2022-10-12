#define cl(x) (x<<1)+1
#define cr(x) (x<<1)+2

int arr[MXN];
int tree[MXN*4];


void build(int index,int left,int right){
    if( left == right ){
        tree[index] = arr[left];
        return;
    }
    int mid=(left + right)/2;
    build(cl(index),left,mid);
    build(cr(index),mid+1,right);
    tree[index] = max(tree[cl(x)] ,tree[cr(x)]);
}
int query(int index,int left,int right,int query_left,int query_right){
    if( query_left <= left && right <= query_right){
        return tree[index];
    }
    int mid=(left + right)/2;
    int ans=-INF;
    if(query_left <= mid){
        ans = max(ans, query(cl(index),left,mid,query_left,query_right));
    }
    if(query_right > mid){
        ans = max(ans, query(cr(index),mid+1,right,query_left,query_right));
    }
    return ans;
}
void update(int index,int left,int right,int position,int value){
    if(left == right){
        tree[index] = value;
        return;
    }
    int mid=(left+right)/2;
    if(position <= mid){
        update(cl(index),left,mid,position,value);
    }
    esle{
        update(cr(index),mid+1,right,position,value);
    }
    tree[index] = max(tree[cl(index)],tree[cr(index)]);
}

int main(){
    build(0,0,n-1);
    query(0,0,n-1,2,7);
}