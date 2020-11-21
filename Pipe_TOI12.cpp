/*
    TASK    : Pipe_TOI12
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

int x[15010], y[15010], dis[15010], now, i, j, n, k, sum, target, mi;
priority_queue <int> pq;

int main(){
    scanf("%d %d",&n, &k);
    for(i=1; i<=n; i++){
        scanf("%d %d",&x[i], &y[i]);
        dis[i] = 2e9;
    }
    dis[1] = 0;
    for(now=1; now<n; now++){
        mi = 2e9;
        for(i=now+1; i<=n; i++){
            dis[i] = min(dis[i], abs(x[i] - x[now]) + abs(y[i] - y[now]));
            if(dis[i] < mi){
                target = i;
                mi = dis[i];
            }
        }
        pq.push(mi);

        /// change target
        swap(x[target], x[now+1]);
        swap(y[target], y[now+1]);
        swap(dis[target], dis[now+1]);
    }
    /// cut
    while(!pq.empty() && k-1>0){
        pq.pop();
        k--;
    }
    while(!pq.empty()){
        k--;
        sum += pq.top();
        pq.pop();
    }
    printf("%d", sum);
    return 0;
}
/*
5 2
2 9
9 7
14 2
12 9
16 4
*/
