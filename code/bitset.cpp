bitset<4> bitset1;	//0000
bitset<8> bitset2(12);	//00001100
string s = "100101";
bitset<10> bitset3(s);
char s2[] = "10101";
bitset<13> bitset4(s2);　
string s = foo.to_string();　　//bitset轉換成string
unsigned long a = foo.to_ulong();　　//bitset轉換成unsigned long
unsigned long long b = foo.to_ullong();　　//bitset轉換成unsigned long long

bitset<8> foo ("10011011");
foo.count() //5（count求1的個數
foo.size()	//8（size求bitset的大小
foo.test(0)	//true（test查下標處的元素是 0->false，1->true
foo.any()	//true（any檢查bitset中是否有1
foo.none() //false（none檢查bitset中是否沒有1
foo.all() 	//false（all檢查bitset中是全部爲1
foo.flip(2)　//10011111（flip傳參數時，用於將參數位取反
foo.flip() 	//01100000（flip不指定參數時，將每一位全部取反
foo.set()	//11111111（set不指定參數時，將bitset的每一位設爲1
foo.set(3,0) //11110111（set函數指定兩位參數時，將第一參數位的元素設爲第二參數的值
foo.set(3)	//11111111（set函數只有一個參數時，將參數下標處設爲1
foo.reset(4) //11101111（reset函數傳一個參數時將參數下標處設爲0
foo.reset() 	//00000000（reset函數不傳參數時將bitset的每一位設爲0
