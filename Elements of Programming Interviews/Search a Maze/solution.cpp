struct pt {
	int x, y;
	bool visited;
};

bool findsEnd(vector<vector<bool>> grid, pt start, pt end) {
	if (grid[start.x][start.y] || grid[end.x][end.y]) {
		return false;
	}

	expand(grid, start);
	return end.visited;
}

void expand(vector<vector<pt>> &grid, pt cur) {
	if (!grid[cur.x][cur.y]) {
		grid[cur.x][cur.y] = true;

		if (cur.x > 0) {
			expand(grid, pt(cur.x - 1, cur.y));
		}

		if (cur.x < grid.size() - 1) {
			expand(grid, pt(cur.x + 1, cur.y));
		}

		if (cur.y > 0) {
			expand(grid, pt(cur.x, cur.y - 1));
		}

		if (cur.y < grid.size() - 1) {
			expand(grid, pt(cur.x, cur.y + 1));
		}
	}
}