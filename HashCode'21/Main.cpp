#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll fp(ll a, ll b){
    ll res=1;
    while(b){
        if(b&1)
        res*=a;
        a*=a;
        b/=2;
    }
    return res;
}

bool cmp(const pair<pair<ll, ll>, vector<string>>&a, const pair<pair<ll, ll>, vector<string>>&b){
	if(a.se[0] == b.se[0]) {
		return a.fi.se < b.fi.se;
	}
	return a.fi.fi < b.fi.fi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("e.txt","r",stdin);
        freopen("ee.txt","w",stdout);
        // freopen("errorcv.txt","w",stderr);
    #endif

        ll d, i, s, v, f;
        cin>>d>>i>>s>>v>>f;
        map<string, pair<pair<ll, ll>, pair<ll, ll>>> mp;
        vector<set<string>> strts(i);
        for(int i=0;i<s;i++){
        	string str; ll a, b, c;
        	cin>>a>>b>>str>>c;
        	mp[str] = {{a, b}, {c, i}};
        	strts[b].insert(str);
        }
        vector<pair<pair<ll, ll>, vector<string>>> mpp(v);
        for(ll i=1;i<=v;i++){
        	ll n, sum = 0;
        	cin>>n;
        	vector<string> path;
        	for(int j=0;j<n;j++){
        		string str;
        		cin>>str;
        		if(i > 0){
        			sum += mp[str].se.fi;
        		}
        		path.push_back(str);
        	}
        	mpp[i-1] = {{sum, i}, path};
        }
        sort(mpp.begin(), mpp.end(), cmp);
        int j = 0, ct = 0;
        vector<bool> inter(i, false);
        vector<set<string>> streets(i);
        for(int i=0;i<=332*d;){
        	i += mpp[j].fi.fi;
        	for(int z=0;z<mpp[j].se.size();z++){
        		if(inter[mp[mpp[j].se[z]].fi.se] == false) ++ct;
        		inter[(mp[mpp[j].se[z]].fi.se)] = true;
        		streets[(mp[mpp[j].se[z]].fi.se)].insert(mpp[j].se[z]);
        	}
        	++j;
        	if(j == mpp.size()) break;
        }
        cout<<i<<'\n';
        srand(time(0));
        for(int j=0;j<i;j++){
        	if(inter[j]){
        		cout<<j<<'\n';
        		cout<<streets[j].size()<<'\n';
        		int sz = streets[j].size();
        		for(auto k: streets[j]) {
        			// int time = rand()%sz + 1;
        			cout<<k<<" "<<1<<"\n";
        		}
        	}
        	else{
        		if(strts[j].size() == 0){
        			continue;
        		}
        		cout<<j<<'\n';
        		cout<<strts[j].size()<<'\n';
        		int sz = strts[j].size();
        		for(auto k: strts[j]) {
        			// int time = rand()%sz + 1;
        			cout<<k<<" "<<1<<"\n";
        		}
        	}
        }

	return 0;
}
