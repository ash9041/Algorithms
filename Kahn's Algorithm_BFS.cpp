
#include <bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	
	vector<int> topoSort(int V, vector<int> mp[]) 
	{
	    
	    int n=V;
	   vector<int>indeg(n,0);
      vector<int>ans;
      queue<int>q;
      for(int i=0;i<n;i++){
        for(int j=0;j<mp[i].size();j++){
            indeg[mp[i][j]]++;
            
        }  
      }
     
      for(int i=0;i<n;i++){
          if(indeg[i]==0){
              q.push(i);
          }
      }
      while(!q.empty()){
          int sz=q.size();
          for(int i=0;i<sz;i++){
              int tp=q.front();
              q.pop();
              ans.push_back(tp);
              for(auto  it:mp[tp]){
                  indeg[it]--;
                  if(indeg[it]==0){
                      q.push(it);
                       
                  }
              }
          }
         
      }
      if(ans.size()!=n)return {};
      return ans;
	}
};


int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
