int LIS(const vector<int>& arr){
    vector<int> lis;
    for(auto i:arr){
        if(lis.empty() || lis.back() < i)   lis.push_back(i);
        else    *lower_bound(lis.begin(),lis.end(),i) = i;
    }
    return lis.size();
}