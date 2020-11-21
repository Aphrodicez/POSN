/*
    TASK    : Weakpoint_TOI12
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;


void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int child[500010], deg[500010], visited[500010];
int n, source, u, v, i, mx = -1, idx, now, cnt;
/*
visited : 0 = Cycle, 1 = Leaf
mx = max children cut
idx = ans node
*/
vector<int> g[500010];

queue<int> bfs;

int main()
{

    cin >> n >> source;
    for(i=1; i<=n; i++){
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(i=1; i<=n; i++){
        /// leaf
        if(deg[i]==1)
            bfs.push(i);
    }
    while(!bfs.empty()){
        now = bfs.front();
        visited[now] = 1;
        bfs.pop();
        for(auto x : g[now]){
            if(visited[x]==0){
                child[x] += child[now] + 1;
                deg[x]--;
                if(deg[x]==1){
                    bfs.push(x);
                }
            }
        }
    }
    if(visited[source]==0){
        /// Source Inside Cycle
        for(i=1; i<=n; i++){
            if(i==source)
                continue;
            if(mx < child[i] && visited[i]==0){
                mx = child[i];
                idx = i;
            }
        }
        for(auto x : g[source]){
            if(mx < child[x]){
                mx = child[x];
                idx = x;
            }
            else if(mx==child[x]){
                idx= min(x,idx);
            }
        }
    }
    else{
        /// source not in cycle
        memset(visited, 0, sizeof visited);
        visited[source] = 1;
        for(auto x : g[source]){
            bfs.push(x);
            cnt = 0;
            visited[x] = 1;
            while(!bfs.empty()){
                now = bfs.front();
                bfs.pop();
                for(auto y : g[now]){
                    if(visited[y]==0){
                        visited[y] = 1;
                        bfs.push(y);
                        cnt++;
                    }
                }
            }
            if(mx < cnt){
                mx = cnt;
                idx = x;
            }
            else if(mx==cnt){
                idx = min(x, idx);
            }
        }
    }
    cout << idx << "\n" << mx;
    return 0;
}
/*
12 1
1 2
1 6
1 7
1 12
6 8
6 9
2 3
2 10
10 11
3 4
4 5
5 12
*/
