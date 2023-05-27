const int M = 1e9+7;
int mazeObstacles(int n, int m, vector< vector< int> > &g) {
    if(g[0][0]==-1) return 0;

    for(int i=0; i<n; ++i){
        if(g[i][0]==0) g[i][0]=1;
        else break;
    }
    for(int i=1; i<m; ++i){  //not i=1 not 0 init topmost  row
        if(g[0][i]==0) g[0][i]=1;
        else break;
    }

    for(int i=1; i<n; ++i){
        for(int j=1; j<m; ++j){
            if(g[i][j]==-1) continue;
            if(g[i-1][j]>0)
                g[i][j] = (g[i][j] + g[i-1][j])%M;
            if(g[i][j-1]>0)
                g[i][j] = (g[i][j] + g[i][j-1])%M;
        }
    }
    return (g[n-1][m-1]>0) ? g[n-1][m-1] : 0;
}
