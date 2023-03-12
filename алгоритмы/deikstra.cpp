void deik(ll u)
{
    dist[u] = 0;
    mn.insert({dist[u], u});
    while (!mn.empty()){
        ll v = mn.begin() -> s;
        mn.erase(mn.begin());
        for (pll q : gr[v]){
            ll to = q.f;
            ll len = q.s;
            if (dist[v] + len < dist[to]){
                mn.erase({dist[to], to});
                dist[to] = dist[v] + len;
                mn.insert({dist[to], to});
            }
        }
    }
}
