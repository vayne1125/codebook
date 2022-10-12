struct Treap {
	int key, pri, sz, tag;
	Treap* cl, * cr;   //左右子樹
	Treap() {}
	Treap(int key_) {
		key = key_;
		sz = 1;
		tag = 0;
		pri = rand();
		cl = cr = nullptr;
	}
};
int Size(Treap* x) { return x ? x->sz : 0; }
void pull(Treap* x) { x->sz = Size(x->cl) + Size(x->cr) + 1; }
Treap* merge(Treap* a, Treap* b) {
	push(a);
	push(b);
	if (!a || !b)return a ? a : b; //其中一個子樹為空則回傳另一個
	if (a->pri > b->pri) {         //如果a的pri比較大則a比較上面
		push(a->cr);           
		push(b);
		a->cr = merge(a->cr, b);  //將a的右子樹跟b合併
		pull(a);
		return a;
	}
	else {
		push(b->cl);                
		push(a);
		b->cl = merge(a, b->cl);   //如果b的pri比較大則b比較上面
		pull(b);                   //將b的左子樹根a合併
		return b;
	}
}
void splitByKey(Treap* x, int k, Treap*& a, Treap*& b) {
	//將一棵Treap分成兩棵，
	//key小於等於k的分到左邊那棵a，其他分到右邊那棵b
	push(x);
	if (!x) { a = b = nullptr; }
	else if (x->key <= k) {
		a = x;
		splitByKey(x->cr, k, a->cr, b);
		pull(a);
	}
	else {
		b = x;
		splitByKey(x->cl, k, a, b->cl);
		pull(b);
	}
}
void splitByKth(Treap* x, int k, Treap*& a, Treap*& b) {
	//將一棵Treap分成兩棵，
	//左邊那棵a的節點數有k個，右邊那棵b節點數為n - k個
	push(x);
	if (!x) { a = b = nullptr; }
	else if (Size(x->cl) + 1 <= k) {
		a = x;  //如果左子樹+自己的size小於等於k則左子樹跟自己為k個以內
		splitByKth(x->cr, k - Size(x->cl) - 1, a->cr, b);
		pull(a);
	}
	else {
		b = x;  //如果左子樹+自己的size大於k個則右子樹跟自己會分到右邊
		splitByKth(x->cl, k, a, b->cl);
		pull(b);
	}
}
void insert(int val){             //新增一個值為val的元素
    Treap *x = new Treap(val);    //設一個treap節點
    Treap *l,*r;
    splitByKey(root, val, l, r);  //找到新節點要放的位置
    root = merge(merge(l,x),r);   //合併到原本的treap裡
}                                 
void erase(int val){              //移除所有值為val的元素
    Treap *l,*mid,*r;
    splitByKey(root, val, l, r);  //把小於等於val的丟到l
    splitByKey(l, val-1, l, mid); //小於val的丟到l,等於val的就會在mid裡
    root = merge(l,r);            //將除了val以外的值合併
}
//翻轉
void push(Treap* x) {
	if (!x)return;
	if (x->tag) {
		swap(x->cl, x->cr);
		if (x->cl)x->cl->tag ^= 1;
		if (x->cr)x->cr->tag ^= 1;
		x->tag ^= 1;
	}
}