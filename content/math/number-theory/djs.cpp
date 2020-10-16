const ll N = 1000000;
ll presum_g(ll n);
ll presum_h(ll n);
// preprocessed prefix sum of f
ll presum_f[N];
// djs: prefix sum of multiplicative function f
ll djs_f(ll n) {
	static unordered_map<ll,ll> m;
	if(n<N) return presum_f[n];
	if(m.find(n)!=m.end()) return m[n];
	ll ans=presum_h(n);
	for(ll l=2,r; l<=n; l=r+1) {
		r=n/(n/l);
		ans-=(presum_g(r)-presum_g(l-1))*djs_f(n/l);
	}
	return m[n]=ans;
}
