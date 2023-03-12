const ll K = 2200;

struct ask {
	ll t, l, r, i;
};

struct change {
	ll i, x;
};

bool comp(const ask& a, const ask& b) {
	if (a.l / K == b.l / K) {
		if (a.t / K == b.t / K) {
			return a.r < b.r;
		}
		return a.t / K < b.t / K;
	}
	return a.l / K < b.l / K;
}

vec arr;
vector <ask> req;
vector <change> ch;
vec cnt;
vec szs(100001); // ���-�� size-�� �� cnt

ll find_ans(ll v) {
	rep2(i, 100000) {
		if (szs[i] == 0) return i;
	}
}

void add(ll i) {
	ll x = arr[i];
	if (cnt[x] > 0) --szs[cnt[x]];
	++cnt[x];
	++szs[cnt[x]];
}

void del(ll i) {
	ll x = arr[i];
	--szs[cnt[x]];
	--cnt[x];
	if (cnt[x] > 0) ++szs[cnt[x]];
}

void add_t(ll j, ll l, ll r) {
	ll i = ch[j].i, x = ch[j].x;
	ch[j].x = arr[i];
	if (i < l || i > r) {
		arr[i] = x;
	}
	else {
		del(i);
		arr[i] = x;
		add(i);
	}
}

void del_t(ll j, ll l, ll r) {
	ll i = ch[j].i, x = ch[j].x;
	ch[j].x = arr[i];
	if (i < l || i > r) {
		arr[i] = x;
	}
	else {
		del(i);
		arr[i] = x;
		add(i);
	}
}

signed main() {
	FF;
	ll n, q;
	cin >> n >> q;
	arr.rsz(n);
	map <ll, ll> cod;
	ll free = 1;
	
	rep(i, n) {
		cin >> arr[i];
		if (cod[arr[i]] == 0) {
			cod[arr[i]] = free;
			++free;
		}
		arr[i] = cod[arr[i]];
	}
	
	ll c = 0, anss = 0;
	rep(i, q) {
		ll tp;
		cin >> tp;
		if (tp == 1) {
			ll l, r;
			cin >> l >> r;
			--l; --r;
			req.pb({ c, l, r, anss });
			++anss;
		} else {
			ll j, x;
			cin >> j >> x;
			--j;
			if (cod[x] == 0) {
				cod[x] = free;
				++free;
			}
			x = cod[x];
			++c;
			ch.pb({ j, x });
		}
	}

	cnt.rsz(free + 1, 0);
	sort(all(req), comp);
	vec ans(anss);
	ll l = 1, r = 0, t = 0;
	
	rep(i, sz(req)) {
		
		ll t1 = req[i].t, l1 = req[i].l, r1 = req[i].r, i1 = req[i].i;
		
		while (l > l1) {
			--l;
			add(l);
		}
		
		while (r < r1) {
			++r;
			add(r);
		}
		
		while (l < l1) {
			del(l);
			++l;
		}
		
		while (r > r1) {
			del(r);
			--r;
		}
		
		while(t < t1) {
			++t;
			add_t(t - 1, l1, r1);
		}
		
		while (t > t1) {
			del_t(t - 1, l1, r1);
			--t;
		}

		ans[i1] = find_ans(0);
	}

	rep(i, sz(ans)) {
		cout << ans[i] << el;
	}
	return 0;
}


/*
На курсе машинного обучения вам выдали первое домашнее задание — вам предстоит проанализировать некоторый массив из n чисел.
В частности, вы интересуетесь так называемой равномерностью массива. Предположим, что в
массиве число b1 встречается k1 раз, b2 — k2 раз, и т.д. Тогда равномерностью массива называется
такое минимальное целое число c > 1 , что c 6= ki для любого i .
В рамках вашего исследования вы хотите последовательно проделать q операций.

Формат входных данных
Первая строка содержит n и q ( 1 6 n, q 6 100000 ) — размер массива и число запросов соответственно.
Во второй строке записаны ровно n чисел — a1 , a2 , ... , an ( 1 6 ai 6 109
).
Каждая из оставшихся q строк задаёт очередной запрос.
Запрос первого типа задаётся тремя числами ti = 1 , li
, ri
, где 1 6 li 6 ri 6 n — границы
соответствующего отрезка.
Запрос второго типа задаётся тремя числами ti = 2 , pi
, xi
, где 1 6 pi 6 n — позиция в которой
нужно заменить число, а 1 6 xi 6 109 — его новое значение

Формат выходных данных
Для каждого запроса первого типа выведите одно число — равномерность соответствующего
отрезка массива.

*/