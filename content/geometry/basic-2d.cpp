using T = long long;
using pt = pair<T, T>;
#define x first
#define y second

pt operator-(pt a) { return { -a.x, -a.y }; }
pt operator+(pt a, pt b) {return { a.x + b.x, a.y + b.y};}
pt operator-(pt a, pt b) {return { a.x - b.x, a.y - b.y};}
pt operator*(pt a, T t) { return { a.x * t, a.y * t }; }
T abs2(pt a) { return a.x * a.x + a.y * a.y; }
T len(pt a) { return sqrt(abs2(a)); }
T dot(pt a, pt b) { return a.x * b.x + a.y * b.y; }
T cross(pt a, pt b) { return a.x * b.y - b.x * a.y; }
T cross(pt a, pt b, pt o) { return cross(a - o, b - o); }

// if segment AB and CD intersects
// for a nondegenrate version, change > to >=
bool intersects(pt a, pt b, pt c, pt d) {
	if(cross(b, c, a) * cross(b, d, a) > 0) return false;
	if(cross(d, a, c) * cross(d, b, c) > 0) return false;
	return true;
}
// the intersect pt of lines AB and CD
pt intersect(pt a, pt b, pt c, pt d) {
	auto x = cross(b, c, a), y = cross(b, d, a);
	if(x == y) {
	// if(abs(x, y) < 1e-8) {
		// is parallel
	} else {
		return d * (x/(x-y)) - c * (y/(x-y));
	}
}
