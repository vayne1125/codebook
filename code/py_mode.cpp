{
  cat > a.in	 //copy input to a.in,use ctrl+d to finish
  . / a.out < a.in		    //enter input in a.in and run
  . / a.out<a.in>a.o	//enter output to a.o
	cat a.o	    //show up the content in a.o
}
{									//should use python
	from random import*
		randint(a, b)		  //produce a random int in a-b
		random(a, b)		 //maybe produce a float
}
ctrl + c		//force to stop

python3 test.py			//run
diff a.out b.out	//look difference between two file
{
	for ((i = 0;; i++))
do
	echo "$i"
	 python3 gen.py > input
	 . / ac < input > ac.out
	  . / wa < input > wa.out
	  diff ac.out wa.out || break
done
}			//match

a,b = b,a #swap

from sys import stdin //讀整行
n = stdin.readline()

a,b = map(int,input().split().) //映射輸入

s.strip() //刪頭尾空格

i='A' //字元轉數字
i=ord(i) #65
i=ord('B') - ord('A') 

x=bin(x) //2(以0b開頭)
x=oct(x) //8(以0o開頭)
x=hex(x) //16(以0x開頭)
x=int(x,2) //2轉10
x=int(x,8) //8轉10
x=int(x,16) //16轉10

for s in stdin:  //連續輸入

print("%g" %(R)) //去除小數的0 輸出法