void findway() {
	way[0] = 1;
	int price[5] = { 1,5,10,25,50 };
	for (int i = 0; i < 5; i++) {
		for (int j = price[i]; j < MXN;j++) {
			way[j] += way[j - price[i]];
		}
	}
}