// global bump allocator
char mem[256 << 20];  // 256 MB
size_t rsp = sizeof mem;
void* operator new(size_t s) {
	assert(s < rsp);  // MLE
	return (void*)&mem[rsp -= s];
}
void operator delete(void*) {}

// bump allocator for STL / pbds containers
char buf[256 << 20];
size_t idx = sizeof buf;
template<typename T> struct bump {
	typedef T value_type;
	bump() {}
	template<typename U> bump(U,...) {}
	T* allocate(size_t n) {
		idx -= n * sizeof(T);
		idx &= 0 - alignof(T);
		return (T*)(buf + idx);
	}
	void deallocate(T*, size_t n) {}
};
