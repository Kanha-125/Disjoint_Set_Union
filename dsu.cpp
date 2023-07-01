class DisjointSet{
    vector<int> parent,rank;
    
    public:
    
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        
        if(node==parent[node]){
            return node;
        }
        parent[node]=findParent(parent[node]);
        return parent[node];
        
    }
    
    void unionByRank(int u,int v){
        int par_u=parent[u];
        int par_v=parent[v];
        
        if(rank[par_u]<rank[par_v]){
            parent[par_u]=par_v;
        }
        else if(rank[par_v]<rank[par_u]){
            parent[par_v]=par_u;
        }
        else{
            parent[par_v]=par_u;
            rank[par_u]++;
        }
    }
    Void unionBYSize(int u,int v){
	int par_u=parent[u];
        int par_v=parent[v];
	
	if(rank[par_u]<rank[par_v]){
	    parent[par_u]=par_v;
	    rank[par_v]+=rank[par_u];	
 	}
	else{
	    parent[par_v]=par_u;
            rank[par_u]+=rank[par_v];	
	}

}
    
};