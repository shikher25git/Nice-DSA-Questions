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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("b.txt","r",stdin);
        freopen("bo.txt","w",stdout);
        // freopen("errorcv.txt","w",stderr);
    #endif
    // cout<<"Hello";
    int projects, contributors;
    cin>>contributors>>projects;
    map<string, map<int, set<int>>> skills;
    vector<string> pid(projects), cid(contributors);
    map<string, int> piid, ciid;
    vector<pair<pair<int, int>, pair<int, int>>> project(projects);
    vector<vector<pair<string, int>>> reqs(projects);
    for(int i=0;i<contributors;i++){
    	string name;
    	int n;
    	cin>>name>>n;
    	cid[i] = name;
    	ciid[name] = i;
    	for(int j=0;j<n;j++){
    		string skill; int lev;
    		cin>>skill>>lev;
    		skills[skill][-lev].insert(i);
    	}
    }
    for(int i=0;i<projects;i++){
    	string name; int days, score, before, roles;
    	cin>>name>>days>>score>>before>>roles;
    	pid[i] = name;
    	piid[name] = i;
    	project[i] = {{days, score}, {before, i}};
    	vector<pair<string, int>> tmp(roles);
    	
    	for(int j=0;j<roles;j++){
    		string skill; int lev;
    		cin>>skill>>lev;
    		tmp[j] = {skill, lev};
    	}
    	reqs[i] = tmp;
    }
    sort(project.begin(), project.end(), [&](const pair<pair<int, int>, pair<int, int>>&a, const pair<pair<int, int>, pair<int, int>>&b){
    	return (1.0 * a.fi.se)/a.fi.fi > (1.0 * b.fi.se)/b.fi.fi;
    });

    vector<int> proc(projects, 0);
    string ans = "";
    int ac = 0, ctr = 0;
    do{
        vector<int> visc(contributors, 0);
	    for(int i=0;i<projects;i++){
	    	if(proc[i] == 1)
	    		continue;
	    	int f = 0;
	    	vector<int> d;
	    	for(auto j: reqs[project[i].se.se]){
	    		string sk = j.first;
	    		int le = j.second;
	    		auto itr = skills[sk];
	    		int ff = 0, fff = 0;
	    		for(auto k: itr){
	    			if(abs(k.fi) > le){
						for(auto l: k.se){
							if(visc[l] == 0){
			    				visc[l] = 1;
			    				d.push_back(l);
			    				fff = 1;
			    				break;
			    			}
			    			else ff = 1;
			    		}
	    			}
	    			else if(abs(k.fi) == le){
	    				for(auto l: k.se){
							if(visc[l] == 0){
			    				visc[l] = 2;
			    				d.push_back(l);
			    				fff = 1;
			    				break;
			    			}
			    			else ff = 1;
			    		}
	    			}
	    		// 	else if(abs(k.fi) + 1 == le){
	    		// 		for(auto l: k.se){
							// if(visc[l] == 0 and ff){
			    // 				visc[l] = 2;
			    // 				d.push_back(l);
			    // 				fff = 1;
			    // 				break;
			    // 			}
			    // 		}
	    		// 	}
	    			else break;
	    			if(fff)
	    			    break;
	    		}
	    		if(fff == 0){
	    			f = 1; break;
	    		}
	    	}
	    	if(f == 0){
	    	    proc[i] = 1;
	    		++ac;
	    		ans += pid[project[i].se.se];
	    		ans += "\n";
	    		int sz = d.size();
	    		int sz1 = reqs[project[i].se.se].size();
	    		for(int j=0;j<sz;j++){
	    			string sk = reqs[project[i].se.se][j].fi;
	    			int le = reqs[project[i].se.se][j].se;
	    			if(visc[d[j]] == 2){
		    			skills[sk][-le].erase(d[j]);
		    			skills[sk][-le - 1].insert(d[j]);
		    		}
		    		ans += cid[d[j]];
		    		ans += " ";
	    		}
	    		ans += "\n";
	    	}
	    	else{
	    	    for(auto j: d){
	    	        visc[j] = 0;
	    	    }
	    	}
	    }
	    
	    ++ctr;
	}while(ctr < 100);
	cout<<ac<<'\n';
	cout<<ans;
	return 0;
}