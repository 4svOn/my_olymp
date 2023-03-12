// в dist всё INF
dist[st] = 0;
bool change = 1;
while(change){
	change = 0;
	for (edge ed : eddges){
		if (dist[ed.a] < INF && dist[ed.b] > dist[ed.a] + ed.c){
			dist[ed.b] = dist[ed.a] + ed.c;
			p[ed.b] = ed.a;
			change = 1;
		}
	}
}

// восстановление пути
if (dist[fin] == INF) // пути нет
ll cur = fin;
while (cur != st){
	path.pb(cur);
	cur = p[cur];
}
path.pb(st);
reverse(all(path));

// выведение отрицательного цикла
// если в while больше на n-ой итерации есть изменения, то в графе есть отрицательный цикл
ll cur = last_relaxed_v;
rep2(i, n){
	cur = p[cur];
}
while (cur != last_relaxed_v || path.size() < 2){
	path.pb(cur);
}
reverse(all(path));