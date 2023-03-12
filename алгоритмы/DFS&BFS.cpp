void dfs(ll v){
	used[v] = 1;
	for (ll to : gr[v]){
		if (!used[to])
			dfs(to);
	}
}

void bfs(ll st){
	used[st] = 1;
	queue <ll> q;
	q.push(st);
	while(!q.empty()){
		ll v = q.front();
		q.pop();
		for (ll to : gr[v]){
			used[to] = 1;
			q.push(to);
		}
	}
}