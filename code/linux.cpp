ls				//show the file
mkdir test	//make a directory - test
cd test	   //go to test directory
cd ..		  //back to last directory
mv test test2 //if test2 exist,move test to test2,else rename test to test2
rm test   //delete test

vim a.cpp	 //write code
{
	i			//insert mode(type)
	esc		//normal mode(command)
	:wq		//save and leave
	normal + gg + G + d	//delete all
	normal +the line	 your mouse stop+d	//delete the line
	normal + gg + V + G + " = "	//indent(tab)
	normal + u  //return to last step
	the leter your mouse stop + s	//delete the letter and start insert mode
	!!DO NOT press ctrl + s!! //if so ,use ctrl+q 
}
g++ a.cpp -o a.out				//compile	
./a.out		//run



