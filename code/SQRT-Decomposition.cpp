struct blk{
    vector<int> local;    //每塊的全部元素
    int global;           //儲存每塊的總和
    int tag;              //儲存整塊一起更新的值
    blk(){                //初始化
        local.clear();    //清空區間元素
        tag = global = 0; //將區間總和先設為0
    }
};
vector<blk> b;
void build(){
    int len=sqrt(n),num=(n+len-1)/len;
    for(int i=0;i<n;i++){    //第i個元素分在第 i/len 塊
        cin>>x;
        //存入區間中
        b[i/len].local.push_back(x);
        //更新區間總和
        b[i/len].global += x;
    }
}
void update(int ql,int qr,int v){
    int blk_l=ql/len,blk_r=qr/len,ret=0;
    if(blk_l == blk_r){    //如果都在同一塊直接一個一個跑過去就好
        for(int i=ql;i<=qr;i++)
            b[blk_l].local[i%len]+=v;
        b[blk_l].global+=(qr-ql+1)*v;
        return;
    }
    for(int i=ql;i<(blk_l+1)*len;i++){  //最左的那一塊
        b[blk_l].local[i%len]+=v;
        b[blk_l].global+=v;
    }
    for(int i=blk_l+1;i<blk_r;i++){  //中間每塊
        b[i].tag+=v;
        b[i].global+=v*len;
    }
    for(int i=blk_r*len;i<=qr;i++){  //最右的那一塊
        b[blk_r].local[i%len]+=v;
        b[blk_r].global+=v;
    }
}
int query(int ql,int qr){
    int blk_l=ql/len,blk_r=qr/len,ret=0;
    if(blk_l == blk_r){    //如果都在同一塊直接一個一個跑過去就好
        for(int i=ql;i<=qr;i++)
            ret+=b[blk_l].local[i%len]+b[blk_l].tag;
        return ret;
    }
    for(int i=ql;i<(blk_l+1)*len;i++)    //最左的那一塊
        ret+=b[blk_l].local[i%len]+b[blk_l].tag;
    for(int i=blk_l+1;i<blk_r;i++)    //中間每塊的總和
        ret+=b[i].global;
    for(int i=blk_r*len;i<=qr;i++)    //最右的那一塊
        ret+=b[blk_r].local[i%len]+b[blk_r].tag;
    return ret;
}