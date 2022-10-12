vector<int> merge_sort(vector<int> vec) {
	if (vec.size() == 1)return vec;
	vector<int> left(vec.begin(), vec.begin() + vec.size()/2),
		right(vec.begin() + vec.size()/2, vec.end());
	left = merge_sort(left);
	right = merge_sort(right);
	vector<int> re;
	int i, j;
	for (i = 0,j=0; i < left.size() && j<right.size();) {
		if (left[i] < right[j]) re.push_back(left[i++]);
		else if(left[i] > right[j]) re.push_back(right[j++]);
		else {
			re.push_back(left[i++]);
			re.push_back(right[j++]);
		}
	}
	while (i < left.size())re.push_back(left[i++]);
	while (j < right.size())re.push_back(right[j++]);
	return re;
}