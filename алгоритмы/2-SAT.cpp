graph gr;
graph grb;
graph cmp;
vector <US<ll>> newgr;
vecc used;
vecc ans;
vec order;
ll c = 0;
vec comp;
ll n, m;

void topsort(ll v) {
	used[v] = 1;
	for (ll to : gr[v]) {
		if (!used[to]) topsort(to);
	}
	order.pb(v);
}

void dfs(ll v) {
	used[v] = 1;
	for (ll to : grb[v]) {
		if (!used[to]) dfs(to);
	}
	comp[v] = c;
	cmp[c].pb(v);
}

void solve(ll v) {
	if (v >= n) ans[v - n] = 0;
	else ans[v] = 1;
	for (ll to : gr[v]) {
		if (ans[(v >= n) ? (v - n) : v] == 6) dfs(to);
	}
}

signed main() {
	FF;
	while (cin >> n >> m) {
		gr.assign(n * 2, vec());
		grb.assign(n * 2, vec());
		used.assign(n * 2, 0);
		comp.assign(n * 2, -1);
		order.clear();
		c = 0;
		rep(i, m) {
			ll x1, e1, x2, e2;
			cin >> x1 >> e1 >> x2 >> e2;

			if (e1 && e2) {
				gr[x1 + n].pb(x2);
				gr[x2 + n].pb(x1);
				grb[x2].pb(x1 + n);
				grb[x1].pb(x2 + n);
			}

			if (!e1 && !e2) {
				grb[x1 + n].pb(x2);
				grb[x2 + n].pb(x1);
				gr[x2].pb(x1 + n);
				gr[x1].pb(x2 + n);
			}

			if ((!e1 && e2) || (e1 && !e2)) {
				if (!e1) {
					swap(e1, e2);
					swap(x1, x2);
				}
				gr[x1 + n].pb(x2 + n);
				gr[x2].pb(x1);
				grb[x2 + n].pb(x1 + n);
				grb[x1].pb(x2);
			}
		}

		rep(i, n * 2) {
			if (!used[i]) {
				topsort(i);
			}
		}
		reverse(all(order));

		cmp.clear();
		used.assign(n * 2, 0);
		for (ll v : order) {
			if (!used[v]) {
				cmp.pb(vec());
				dfs(v);
				++c;
			}
		}

		newgr.assign(c, US<ll>());
		rep(v, n) {
			for (ll to : gr[v]) {
				if (comp[v] != comp[to])
					newgr[comp[v]].insert(comp[to]);
			}
		}

		ans.assign(n, 6);
		repb(i, c) {
			for (ll v : cmp[i]) {
				if (ans[(v >= n) ? (v - n) : v] == 6) {
					if (v >= n) ans[v - n] = 0;
					else ans[v] = 1;
				}
			}
		}

		rep(i, sz(ans)) {
			cout << char(ans[i] + '0');
		}
		cout << el;
	}
	return 0;
}


/*
Формулировка 2-SAT: нужно подобрать значения n булевых переменных так, чтобы все m утверждений вида xi1 = e1∨xi2 = e2 обратились в истину. В данной задаче вам гарантируется, что решение
существует.

Формат входных данных
Входной файл состоит из одного или нескольких тестов.
Каждый тест описывается следующим образом. На первой строке число переменных n и число
утверждений m. Каждая из следующих m строк содержит числа i1, e1, i2, e2, задает утверждение
xi1 = e1 ∨ xi2 = e2 (0 6 ij < n, 0 6 ej 6 1). Ограничения: сумма всех n не больше 100 000, сумма
всех m не больше 300 000.

Формат выходных данных
Для каждого теста выведите строку из n нулей и единиц — значения переменных. Если у данной
задачи 2-SAT есть несколько решений, выведите любое.

*/