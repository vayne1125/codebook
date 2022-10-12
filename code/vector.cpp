vec.insert(vec.begin()+i,a); 	//insert a in vec[i]
//erase vec[i]~vec[j-1]
vec.erase(vec.begin()+i,vec.begin()+j);
{
	vector<int>::iterator low, up;
	low = std::lower_bound(v.begin(), v.end(), 20);
	up = std::upper_bound(v.begin(), v.end(), 20);
}
//erase repeat number
{
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), iter, vec.end())
}
