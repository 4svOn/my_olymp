// если нет ребра, то arr[i][j] = INF
// если i == j, то arr[i][j] = 0
// если есть ребро из i в j, то p[i][j] = j
rep2(k, n) {
	rep2(i, n) {
		rep2(j, n) {
			if (arr[i][j] > arr[i][k] + arr[k][j]) {
				arr[i][j] = arr[i][k] + arr[k][j];
				p[i][j] = p[i][k];
			}
		}
	}
}

// восстановление пути
if (arr[st][fin] == INF) // нет пути
ll tmp = st;
while (tmp != fin) {
	path.pb(tmp);
	tmp = p[tmp][fin];
}
path.pb(fin);

// поиск отрицательного цикла
rep2(i, n) {
	rep2(j, n) {
		rep2(k, n) {
			if (arr[i][k] < INF && arr[k][j] < INF && arr[k][k] < 0)
				// есть отрицательный цикл
		}
	}
}