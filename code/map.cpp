//almost same to set,O(lg n)
map<key,value>
mp[i]		//can get the value ,whitch set dont have
mp[i]=2	//if map dont have key=i,then it will insert({i,2})
mp.insert({i,2})	//if key=i is already exist,it will fail
mp.count() 	//return 0 represent not found	
mp.find() 	//return end() represent not found	
mp.erase(mp.begin(),mp.end())

