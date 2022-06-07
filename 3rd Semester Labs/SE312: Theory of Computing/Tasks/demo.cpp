#include <bits/stdc++.h>
    #define N 10005
    using namespace std;
     
    vector<int> ans;
     
    void DFS(int src, vector<int> adj[], bool visited[]){
     
    	visited[src] = true;
    	// cout << src << " ";
    	ans.push_back(src);
     
    	for(int u: adj[src]){
     
    		if(!visited[u]){
    			DFS(u, adj, visited);
    		} 
    	}
     
    }
     
     
    int main(){
     
    	// freopen("in.txt", "r", stdin);
    	// freopen("out.txt", "w", stdout);
     
    	int t;
    	cin >> t;
     
    	int k = 0;
    	for(int i=0; i<t; i++){
     
    		int n;
    		cin >> n;
     
    		vector<int> adj[N];
    		bool visited[N];
     
    		for(int i=0; i<N; i++){
    			visited[i] = false;
    		}
     
     
     
    		int arr[2*n+5] = {-1};
     
    		for(int i=1; i<=n; i++){
     
    			int x;
    			cin >> x;
     
    			arr[i] = x;
    		}
     
     
    		// type 1
    		for(int i=1; i<=n-1; i++){
    			adj[i].push_back(i+1);
    		}
     
    		// type 2
    		for(int i=1; i<=n; i++){
     
    			if(arr[i]==1) adj[n+1].push_back(i);
    			else adj[i].push_back(n+1);
    		}
     
     
    		// for(int i=1; i<=n+1; i++){
     
    		// 	cout << i << "-> ";
     
    		// 	for(int u: adj[i]){
    		// 		cout << u << " ";
    		// 	}
    		// 	cout << endl;
    		// }
     
            int flag = 1;
    		for(int i=1; i<=n+1; i++){
    			
    			DFS(i, adj, visited);
     
    			for(int i=1; i<=n+1; i++){
    				if(!visited[i]) {
    					flag = 0;
    					break;
    				}
    			}
     
    			if(flag) {
     
    				break;
    			} 
     
    		}

            if(flag==0) cout << -1;

            else{

                cout << ans[0];
                for(int i=1; i<ans.size(); i++){
                    cout << " " << ans[i];
                }
        
            }
                
           
     
    		ans.clear();
     
    		if(i != t-1) cout << endl;
    	}
    }