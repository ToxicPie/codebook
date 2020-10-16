struct Aho_Corasick {
	const static int cha=26;
	struct NODES {
		int Next[cha],fail,ans;
	};
	static const int character=26,maxn=1e5;
	NODES trie[maxn];
	int top,que_top,que[maxn];
	int get_node(const int &fail) {
		memset(trie[top].Next,0,sizeof(trie[top].Next));
		trie[top].fail=fail,trie[top].ans=0;
		return top++;
	}
	int insert(const string &s) {
		int ptr=1;
		for(int i=0;i<s.size();i++) {
			if(trie[ptr].Next[s[i]-'a']==0)
				trie[ptr].Next[s[i]-'a']=get_node(ptr);
			ptr=trie[ptr].Next[s[i]-'a'];
		}
		return ptr;
	}//return ans_last_place
	void build_fail(int ptr) {
		int tmp;
		for(int i=0;i<cha;i++)
			if(trie[ptr].Next[i]) {
				tmp=trie[ptr].fail;
				while(tmp!=1&&!trie[tmp].Next[i])
					tmp=trie[tmp].fail;
				if(trie[tmp].Next[i]^trie[ptr].Next[i]&&trie[tmp].Next[i])
					tmp=trie[tmp].Next[i];
				trie[trie[ptr].Next[i]].fail=tmp;
				que[que_top++]=trie[ptr].Next[i];
			}
	}
	void AC_auto(const string &s) {
		int ptr=1;
		for(int i=0;i<s.size();++i){
			while(ptr!=1&&!trie[ptr].Next[s[i]-'a'])
				ptr=trie[ptr].fail;
			if(trie[ptr].Next[s[i]-'a'])
				ptr=trie[ptr].Next[s[i]-'a'],trie[ptr].ans++;
		}
	}
	void Solve(string s) {
		for(int i=0;i<que_top;i++)
			build_fail(que[i]);
		AC_auto(s);
		for(int i=que_top-1;i>-1;i--)
			trie[trie[que[i]].fail].ans+=trie[que[i]].ans;
	}
	void reset() {
		que_top=top=1,que[0]=1,get_node(1);
	}
} AC;
// usage example
string s,S;
int n,t,ans_place[50000];
int main() {
	cin>>t;
	while(t--) {
		AC.reset();
		cin>>S>>n;
		for(int i=0;i<n;i++)
			cin>>s,ans_place[i]=AC.insert(s);
		AC.Solve(S);
		for(int i=0;i<n;i++)
			cout << AC.trie[ans_place[i]].ans<<'\n';
	}
}
