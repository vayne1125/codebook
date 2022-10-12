//sort in small to big,O(lg n)
*st.begin()		//get first value
*st.rbegin()	//get last value
st.count(x) 	//return 0 represent not found	
st.find(x) 		//return st.end() represent not found	
st.erase(x)		//x can be value or iterator
st.clear()  st.empty()  st.size()
st.insert(st2.begin(),st2.end())	//insert st2[begin,end) to st
/*dont have operator[]*/

//customize compare
struct cmp {
	bool operator()(int lhs, int rhs)/*const*/{
		return lhs > rhs;
	}
}
set<int, cmp> st;