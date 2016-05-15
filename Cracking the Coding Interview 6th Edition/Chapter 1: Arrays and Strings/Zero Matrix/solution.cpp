void zeroMatrix(array<array<int, N>, M> A) {
	set<int> zRows, zCols;

	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < A[0].size(); ++j) {
			if (A[i][j] == 0) {
				zRows.insert(i);
				zCols.insert(j);
			}
		}
	}

	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < A[0].size(); ++j) {
			if (zRows.find(i) != zRows.end() || zCols.find(j) != zCols.end()) {
				A[i][j] = 0;
			}
		}
	}	
}