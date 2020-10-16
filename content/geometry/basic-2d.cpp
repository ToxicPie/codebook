template<typename T> struct pt {
	T x, y;
	pt(T x, T y) : x(x), y(y) {}
	pt operator-() const { return {-x, -y}; }
	pt operator+(const pt& a) const {return {x+a.x, y+a.y}; }
	pt operator-(const pt& a) const {return {x-a.x, y-a.y}; }
	pt operator*(const T& t)  const {return {x*t, y*t}; }
	friend T abs2(pt a) { return a.x * a.x + a.y * a.y; }
	friend T len(pt a) { return sqrt(abs2(a)); }
	friend T dot(pt a, pt b){ return a.x * b.x + a.y * b.y; }
	friend T cross(pt a, pt b){return a.x * b.y - b.x * a.y;}
	friend T cross(pt a, pt b, pt o){return cross(a-o, b-o);}
};

// if segment AB and CD intersects
bool intersects(point a, point b, point c, point d) {
	if(cross(b, c, a) * cross(b, d, a) > 0) return false;
	if(cross(d, a, c) * cross(d, b, c) > 0) return false;
	return true;
}
// the intersect point of lines AB and CD
point intersect(point a, point b, point c, point d) {
	T x = cross(b, c, a), y = cross(b, d, a);
	if(x == y) {
	// if(abs(x, y) < 1e-8) {
		// is parallel
	} else {
		return d * (x/(x-y)) - c * (y/(x-y));
	}
}
