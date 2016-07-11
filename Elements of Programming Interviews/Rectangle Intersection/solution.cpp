struct Rectangle {
	int x, y, width, height;
}

Rectangle overlap(Rectangle &A, Rectangle &B) {
	Rectangle &sx = A.x <= B.x ? A : B,
	          &bx = A.x > B.x ? A : B, 
	          &sy = A.y <= B.y ? A : B,
	          &by = A.y > B.y ? A : B;

	if (sx.x + sx.width <= bx.x && sy.y + sy.height <= by.y) {
		Rectangle result;
		result.x = bx.x;
		result.y = by.x;
		result.width = sx.x + width - bx.x;
		result.height = sy.y + height - by.y;
		return result;
	} else {
		throw exception;
	}
}