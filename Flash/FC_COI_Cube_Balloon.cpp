/*
	Author	: Aphrodicez
	School	: RYW
	Language: C++
	Algo	: DSU
*/
#include <bits/stdc++.h>
using namespace std;

struct A{
	int time, idx, val;
	bool operator < (const A& o) const{
		return time > o.time;
	}
};

priority_queue<A> heap;

int sum[100010];
int p[100010];

int fin(int u){
	if(p[u] == u)
        return u;
	return fin(p[u]);
}
void upd(int now, int target){
	sum[now] -= sum[target];
	if(p[now] == now)
        return ;
	upd(p[now], target);
}
int main(){
	ios_base :: sync_with_stdio(0);
    cin.tie(0);
	int n, m, u, v, val, time, rv, opr;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> val;
		sum[i] = val;
        p[i] = i;
	}
	for(int i=1; i<=m; i++){
		cin >> opr;
		while(!heap.empty() && i == heap.top().time){
			auto now = heap.top();
			heap.pop();
			rv = fin(now.idx);
			sum[rv] += now.val;
		}
		if(opr == 1){
			cin >> u;
			if(p[u] == u)
                continue;
			upd(p[u], u);
			p[u] = u;
		}
        else if(opr == 2){
			cin >> u >> v >> time >> val;
			rv = fin(v);
			if(rv == u)
                continue;
			if(p[u] != u)
            	upd(p[u], u);
			p[u] = rv;
			sum[rv] += sum[u];
			heap.push({time, u, val});
		}
        else if(opr == 3){
			cin >> v;
			rv = fin(v);
			cout << sum[rv] << "\n";
		}
	}
	return 0;
}
/*
7 10
1 2 3 4 5 6 7
3 1
2 1 2 5 3
3 1
3 2
3 2
1 1
3 2
2 2 3 9 4
3 2
3 3
*/
/*
7 17
1 2 3 4 5 6 7
2 1 2 5 1
2 2 5 5 2
2 3 5 5 3
2 4 5 8 4
3 1
2 6 7 8 5
2 5 7 8 6
3 1
3 6
2 7 1 11 7
3 7
2 2 5 13 8
3 1
3 4
2 4 6 17 10
1 4
3 4
*/
