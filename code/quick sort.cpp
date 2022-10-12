vector<int> quick_sort(vector<int> vec) {
	if (vec.size() <= 1)return vec;
	srand(time(NULL));
	int pivot =rand() % vec.size();
	vector<int> left, right;
	for (int i = 0; i < vec.size(); i++) {
		if (i == pivot)continue;
		if (vec[i] > vec[pivot])right.push_back(vec[i]);
		else left.push_back(vec[i]);
	}
	left = quick_sort(left);
	right = quick_sort(right);
	left.push_back(vec[pivot]);
	for (int i = 0; i < right.size(); i++)left.push_back(right[i]);
	return left;
}