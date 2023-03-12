struct Point {
    ld x, y;
	
    bool operator == (const Point q) const {
        if (fabs(x - q.x) <= EPS && fabs(y - q.y) < EPS) return true;
        return false;
    }

    Point(ld x = 0, ld y = 0) {
        this->x = x;
        this->y = y;
    }

    ld polar_angle() const {
        ld angle = atan2(y, x);
        if (angle < 0)
        {
            angle += 2 * PI;
        }
        return angle;
    }
};

struct Segment {
    Point a, b;
	
    Segment(Point a, Point b) {
        this->a = a;
        this->b = b;
    }
};

struct Vector {
    ld x, y;
	
    Vector(ld x = 0, ld y = 0) {
        this->x = x;
        this->y = y;
    }
};

struct Line {
    ld a, b, c;
	
    Line(ld a = 0, ld b = 0, ld c = 0) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

struct Circle {
    Point C;
    ld R;

	Circle(Point C = Point(), ld R = 0) {
        this->C = C;
        this->R = R;
	}
};

struct Polygon {
    vector <Point> pp;
    Polygon(ll n = 0) {
        this->pp = vector <Point>(n);
    }
};

ld sqr(ld a) {
    return a * a;
}

Vector Mult_vec_on_num(Vector v, ld q) {
    Vector V(v.x * q, v.y * q);
    return V;
}

ld Dist_2p(Point p1, Point p2) {
    return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

Line LineFrom_V(Vector v) {
    Line l(v.y * -1, v.x, 0);
    return l;
}

Line LineFrom_2P(Point p1, Point p2) {
    Line l;
    l.a = p1.y - p2.y;
    l.b = p2.x - p1.x;
    l.c = -1 * (l.a * p1.x) - l.b * p1.y;
    return l;
}

Line LineFrom_P_V(Point p1, Vector v1) {
    Line l;
    l.a = v1.x;
    l.b = v1.y;
    l.c = -1 * (v1.x * p1.x) - v1.y * p1.y;
    return l;
}

bool is_P_in_Line(Point p, Line l) {
    if (l.a * p.x + l.b * p.y + l.c == 0) return true;
    else return false;
}

bool is_P_in_Segment(Point p, Segment q) {
    Line l;
    l = LineFrom_2P(q.a, q.b);
    if (l.a * p.x + l.b * p.y + l.c == 0 && min(q.a.x, q.b.x) <= p.x && max(q.a.x, q.b.x) >= p.x && min(q.a.y, q.b.y) <= p.y && max(q.a.y, q.b.y) >= p.y) return true;
    else return false;
}

ld Vector_2V(Vector a, Vector b) {
    return a.x * b.y - b.x * a.y;
}

ld Scalar_2V(Vector a, Vector b) {
    return a.x * b.x + b.y * a.y;
}

ld dist_P_Line(Point p, Line l) {
    ld q = abs(p.x * l.a + p.y * l.b + l.c) / sqrt(sqr(l.a) + sqr(l.b));
    return q;
}

Point Peresech_of_2Lines(Line l1, Line l2) {
    Point p((l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b),
        (l1.a * l2.c - l2.a * l1.c) / (l2.a * l1.b - l1.a * l2.b));
    return p;
}

Line Perpendik_Line_To_Line_With_P(Line l2, Point p) {
    Line l1(l2.b, l2.a * -1, -1 * (l2.b * p.x) - ((l2.a * -1) * p.y));
    return l1;
}

ld dist_P_Segment(Point p, Segment q) {
    Line l1 = LineFrom_2P(q.a, q.b);
	Line l2 = Perpendik_Line_To_Line_With_P(l1, p);
    Point p1 = Peresech_of_2Lines(l1, l2);
    if (is_P_in_Segment(p1, q)) return dist_P_Line(p, l1);
    return min(Dist_2p(p, q.a), Dist_2p(p, q.b));
}

ll Peresech_of_Circle_and_Line(vector <Point>& ans, Circle c, Line l) {
    ld D = dist_P_Line(c.C, l);;
    if (D > c.R) return 0;
    Line l1 = Perpendik_Line_To_Line_With_P(l, c.C);
    Point p1 = Peresech_of_2Lines(l, l1);
    if (fabs(c.R - D) <= EPS) {
        ans.pb(p1);
        return 1;
    }
    Vector u1(l.b * -1, l.a), u2(l.b, l.a * -1);
    Point u11(u1.x, 0), u22(u1.y, 0);
    ld d1 = Dist_2p(u22, u11);
    ld U = sqrt(sqr(c.R) - sqr(D));
    ld k = U / d1;
    Mult_vec_on_num(u1, k);
    Mult_vec_on_num(u2, k);
    u11.x = p1.x + u1.x;
    u22.x = p1.x + u2.x;
    u11.y = p1.y + u1.y;
    u22.y = p1.y + u2.y;
    ans.pb(u11);
    ans.pb(u22);
    return 2;
}

ll Peresech_of_2Circle(vector <Point>& ans, Circle c1, Circle c2) {
    ld D = Dist_2p(c1.C, c2.C);
    if (fabs(D) <= EPS && fabs(c1.R - c2.R) <= EPS) {
        return 3;
    	// совпадают
    }
	
    if (D > c1.R + c2.R) {
        return 0;
    }
    if (D + c2.R < c1.R || D + c1.R < c2.R) {
        return 0;
    }
	
    if (fabs(D - c1.R - c2.R) <= EPS) {
        Vector v1(c1.C.x - c2.C.x, c1.C.y - c2.C.y);
        ld k = c2.R / D;
        Mult_vec_on_num(v1, k);
        Point p(v1.x + c2.C.x, v1.y + c2.C.y);
        ans.pb(p);
        return 1;
    }
	
    if (fabs(D + c1.R - c2.R) <= EPS || fabs(D + c2.R - c1.R) <= EPS) {
        Line l1 = LineFrom_2P(c2.C, c1.C);
        vector <Point> ans1, ans2;
        ll q = Peresech_of_Circle_and_Line(ans1, c1, l1);
        ll w = Peresech_of_Circle_and_Line(ans2, c2, l1);
        rep(i, q) {
            rep(j, w) {
                if (ans1[i] == ans2[j]) {
                    ans.pb(ans1[i]);
                    return 1;
                }
            }
        }
    }
	
    if (c1.R + c2.R > D&& D > fabs(c1.R - c2.R)) {
        ld d1 = fabs((sqr(c2.R) - sqr(c1.R) - sqr(D)) / (2 * D));
        ld h = sqrt(sqr(c1.R) - sqr(d1));
        Vector v(c2.C.x - c1.C.x, c2.C.y - c1.C.y);
        Point p1(v.x, v.y), p2(0, 0);
        ld d3 = Dist_2p(p1, p2);
        ld k = d1 / d3;
        Mult_vec_on_num(v, k);
        p2.x = v.x + c1.C.x;
        p2.y = v.y + c1.C.y;
        Vector v1(-v.y, v.x), v2(v.y, -v.x);
        k = h / d1;
        Mult_vec_on_num(v1, k);
        Mult_vec_on_num(v2, k);
        ans.pb(Point(v1.x + p2.x, v1.y + p2.y));
        ans.pb(Point(v2.x + p2.x, v2.y + p2.y));
        return 2;;
    }
}

ll kas_From_P_To_Circle(vector <Point>& ans, Circle c, Point p) {
    if (sqr(p.x - c.C.x) + sqr(p.y - c.C.y) < sqr(c.R)) {
        return 0;
    }
    if (sqr(p.x - c.C.x) + sqr(p.y - c.C.y) - sqr(c.R) < EPS) {
        ans.pb(p);
        return 1;
    }
    ld D = Dist_2p(c.C, p);
    Circle ch(Point(p.x, p.y));
    ch.R = sqrt(sqr(D) - sqr(c.R));
    ll q = Peresech_of_2Circle(ans, c, ch);
    return 2;
}

bool is_P_in_Polygon(Polygon & pol, Point p) {
    ld sum = 0.0;
    for (ll i = 1; i < sz(pol.pp); i++) {
        Vector q1(pol.pp[i - 1].x - p.x, pol.pp[i - 1].y - p.y);
        Vector q2(pol.pp[i].x - p.x, pol.pp[i].y - p.y);
        Segment seg(pol.pp[i - 1], pol.pp[i]);
        if (is_P_in_Segment(p, seg)) return true;
        ld d1 = Vector_2V(q1, q2), d2 = Scalar_2V(q1, q2);
        ld q = atan2(d1, d2);
        sum += q;
    }
    Vector q1(pol.pp.back().x - p.x, pol.pp.back().y - p.y);
    Vector q2(pol.pp[0].x - p.x, pol.pp[0].y - p.y);
    Segment seg(pol.pp[0], pol.pp.back());
    if (is_P_in_Segment(p, seg)) return true;
    ld d1 = Vector_2V(q1, q2), d2 = Scalar_2V(q1, q2);
    ld q = atan2(d1, d2);
    sum += q;
    if (fabs(sum) <= EPS) return false;
    return true;
}

bool is_Polygon_Vblp(Polygon pol) {
    vector <ll> H;
    H.pb(0);
    H.pb(1);
    for (int i = 2; i < sz(pol.pp); ++i) {
        Vector q(pol.pp[H.size() - 2].x - pol.pp[H.size() - 1].x,
            pol.pp[H.size() - 2].y - pol.pp[H.size() - 1].y);
        Vector w(pol.pp[H.size() - 1].x - pol.pp[i].x,
            pol.pp[H.size() - 1].y - pol.pp[i].y);
        if (H.size() >= 2 && q.x * w.y - w.x * q.y >= EPS) {
            return false;
        }
        H.pb(i);
    }
    return true;
}

bool is_Polygon_Vblp_Protiv(Polygon pol) {
    vector <ll> H;
    H.pb(0);
    H.pb(1);
    for (int i = 2; i < sz(pol.pp); ++i) {
        Vector q(pol.pp[H.size() - 1].x - pol.pp[H.size() - 2].x,
            pol.pp[H.size() - 1].y - pol.pp[H.size() - 2].y);
        Vector w(pol.pp[i].x - pol.pp[H.size() - 1].x,
            pol.pp[i].y - pol.pp[H.size() - 1].y);
        if (H.size() >= 2 && w.x * q.y - q.x * w.y >= EPS) {
            return false;
        }
        H.pb(i);
    }
    return true;
}

bool comp(pair<ld, Point> a, pair<ld, Point> b) {
    if (fabs(a.F - b.F) <= EPS) {
        if (a.S.y < b.S.y) return true;
        else return false;
    }
    if (a.F < b.F) return true;
    else return false;
}

Polygon Vblp_obol(Polygon& pol) {
    Point st; st.x = -100000.0; st.y = 100000.0;
    rep(i, sz(pol.pp)) {
        if (pol.pp[i].y < st.y) st = pol.pp[i];
        else if (fabs(pol.pp[i].y - st.y) <= EPS && pol.pp[i].x > st.x) st = pol.pp[i];
    }
    vector < pair<ld, Point> > pp(sz(pol.pp));
    rep(i, sz(pol.pp)) {
        pp[i].S = pol.pp[i];
        Point p1(pol.pp[i].x - st.x, pol.pp[i].y - st.y);
        pp[i].F = p1.polar_angle();
    }
    sort(all(pp), comp);
    pp.pb(pp[0]);
    vector <ll> H;
    H.pb(0);
    H.pb(1);
    for (ll i = 2; i < sz(pp); ++i) {
        while (H.size() >= 2) {
            Vector q(pp[H[H.size() - 1]].S.x - pp[H[H.size() - 2]].S.x,
                pp[H[H.size() - 1]].S.y - pp[H[H.size() - 2]].S.y);
            Vector w(pp[i].S.x - pp[H[H.size() - 1]].S.x,
                pp[i].S.y - pp[H[H.size() - 1]].S.y);
            if (q.x * w.y - w.x * q.y >= EPS) break;
            H.popb();
        }
        H.pb(i);
    }
    if (pp[H[0]].S == pp[H[sz(H) - 1]].S) H.popb();
    if (sz(H) == 1 && pp[H[0]] != pp[sz(pp) - 2]) H.pb(sz(pp) - 2);
    Polygon ans;
    rep(i, sz(H)) {
        ans.pp.pb(pp[H[i]].S);
    }
    return ans;
}

ld S_of_Polygon(Polygon& pol) {
    ld sum = 0.0;
    for (ll i = 1; i < sz(pol.pp); i++) {
        Vector q1(pol.pp[i - 1].x, pol.pp[i - 1].y);
    	Vector q2(pol.pp[i].x, pol.pp[i].y);
        sum += Vector_2V(q1, q2);
    }
    Vector q1(pol.pp[sz(pol.pp) - 1].x, pol.pp[sz(pol.pp) - 1].y);
    Vector q2(pol.pp[0].x, pol.pp[0].y);
    sum += Vector_2V(q1, q2);
    return sum / 2;
}

ld P_of_Polygon(Polygon& pol) {
    ld sum = 0.0;
    for (ll i = 1; i < sz(pol.pp); i++) {
        sum += Dist_2p(pol.pp[i - 1], pol.pp[i]);
    }
	sum += Dist_2p(pol.pp[sz(pol.pp) - 1], pol.pp[0]);
    return sum;
}