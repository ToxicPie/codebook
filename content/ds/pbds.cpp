#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/rope>
using namespace __gnu_pbds;

// most of std::map + order_of_key, find_by_order
template<typename T, typename U = null_type>
using ordered_map = tree<T, U, std::less<T>,
rb_tree_tag, tree_order_statistics_node_update>;
// rb_tree_tag can be changed to splay_tree_tag

template<typename T> struct myhash {
	size_t operator()(T x) const;  // splitmix64, etc.
};
// mostly the same as std::unordered_map
template<typename T, typename U = null_type>
using hash_table = gp_hash_table<T, U, myhash<T>>;

// most of std::priority_queue + merge
using heap = priority_queue<int, std::less<int>>;
// the third template parameter is tag, useful ones are
// pairing_heap_tag, binary_heap_tag, binomial_heap_tag

// similar to treap, has insert/delete range, merge, etc.
using __gnu_cxx::rope;
