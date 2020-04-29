#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i, a, b) for (int i = a, end = b; i < end; i++)
#define ALL(s) s.begin(), s.end()
#define SZ(s) int(s.size())
#define EPS 1e-9
#define pb push_back
#define FIN                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int MAXN = 105;

vector<double> x(MAXN);
vector<double> y(MAXN);
vector<double> t(MAXN);

struct pt
{ // for 3D add z coordinate
    double x, y;
    pt(double x, double y) : x(x), y(y) {}
    pt() {}
    double norm2() { return *this * *this; }
    double norm() { return sqrt(norm2()); }
    bool operator==(pt p) { return abs(x - p.x) < EPS && abs(y - p.y) < EPS; }
    pt operator+(pt p) { return pt(x + p.x, y + p.y); }
    pt operator-(pt p) const { return pt(x - p.x, y - p.y); }
    pt operator*(double t) { return pt(x * t, y * t); }
    pt operator/(double t) { return pt(x / t, y / t); }
    double operator*(pt p) { return x * p.x + y * p.y; }
    //	pt operator^(pt p){ // only for 3D
    //		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
    double angle(pt p)
    { // redefine acos for values out of range
        return acos(*this * p / (norm() * p.norm()));
    }
    pt unit() { return *this / norm(); }
    double operator%(pt p) { return x * p.y - y * p.x; }
    // 2D from now on
    bool operator<(pt p) const
    { // for convex hull
        return x < p.x - EPS || (abs(x - p.x) < EPS && y < p.y - EPS);
    }
    bool left(pt p, pt q)
    { // is it to the left of directed line pq?
        return (q - p) % (*this - p) > EPS;
    }
    pt rot(pt r) { return pt(*this % r, *this * r); }
    pt rot(double a) { return rot(pt(sin(a), cos(a))); }
};
pt ccw90(1, 0);
pt cw90(-1, 0);

struct circle
{
    pt o;
    double r;
    circle(pt o, double r) : o(o), r(r) {}
    bool has(pt p) { return (o - p).norm() < r + EPS; }
    vector<pt> operator^(circle c)
    { // ccw
        vector<pt> s;
        double d = (o - c.o).norm();
        if (d > r + c.r + EPS || d + min(r, c.r) + EPS < max(r, c.r))
            return s;
        double x = (d * d - c.r * c.r + r * r) / (2 * d);
        double y = sqrt(r * r - x * x);
        pt v = (c.o - o) / d;
        s.pb(o + v * x - v.rot(ccw90) * y);
        if (y > EPS)
            s.pb(o + v * x + v.rot(ccw90) * y);
        return s;
    }
    vector<pt> tang(pt p)
    {
        double d = sqrt((p - o).norm2() - r * r);
        return *this ^ circle(p, d);
    }
    bool in(circle c)
    { // non strict
        double d = (o - c.o).norm();
        return d + r < c.r + EPS;
    }
};

struct Cmp
{ // IMPORTANT: add const in pt operator -
    pt r;
    Cmp(pt r) : r(r) {}
    int cuad(const pt &a) const
    {
        if (a.x > 0 && a.y >= 0)
            return 0;
        if (a.x <= 0 && a.y > 0)
            return 1;
        if (a.x < 0 && a.y <= 0)
            return 2;
        if (a.x >= 0 && a.y < 0)
            return 3;
        assert(a.x == 0 && a.y == 0);
        return -1;
    }
    bool cmp(const pt &p1, const pt &p2) const
    {
        int c1 = cuad(p1), c2 = cuad(p2);
        if (c1 == c2)
            return p1.y * p2.x < p1.x * p2.y;
        return c1 < c2;
    }
    bool operator()(const pt &p1, const pt &p2) const
    {
        return cmp(p1 - r, p2 - r);
    }
};

vector<double> intercircles(vector<circle> c)
{
    vector<double> r(SZ(c) + 1); // r[k]: area covered by at least k circles
    fore(i, 0, SZ(c))
    {
        int k = 1;
        Cmp s(c[i].o);
        vector<pair<pt, int>> p = {
            {c[i].o + pt(1, 0) * c[i].r, 0},
            {c[i].o - pt(1, 0) * c[i].r, 0}};
        fore(j, 0, SZ(c)) if (j != i)
        {
            bool b0 = c[i].in(c[j]), b1 = c[j].in(c[i]);
            if (b0 && (!b1 || i < j))
                k++;
            else if (!b0 && !b1)
            {
                auto v = c[i] ^ c[j];
                if (SZ(v) == 2)
                {
                    p.pb({v[0], 1});
                    p.pb({v[1], -1});
                    if (s(v[1], v[0]))
                        k++;
                }
            }
        }
        sort(p.begin(), p.end(),
             [&](pair<pt, int> a, pair<pt, int> b) { return s(a.fst, b.fst); });
        fore(j, 0, SZ(p))
        {
            pt p0 = p[j ? j - 1 : SZ(p) - 1].fst, p1 = p[j].fst;
            double a = (p0 - c[i].o).angle(p1 - c[i].o);
            r[k] += (p0.x - p1.x) * (p0.y + p1.y) / 2 + c[i].r * c[i].r * (a - sin(a)) / 2;
            k += p[j].snd;
        }
    }
    return r;
}

double binary(double a, int n)
{
    double l = 0;
    double r = 1e7;
    double mid = 0;
    double result = 0;
    int it = 200;
    while (it--)
    {
        mid = l + (r - l) / 2.0;
        vector<circle> circles;
        fore(i, 0, n)
        {
            double tc = t[i];
            if (mid >= tc)
                circles.pb(circle(pt(x[i], y[i]), mid - tc));
        }
        vector<double> v = intercircles(circles);
        result = v[1];
        if (result <= a)
            l = mid;
        else
            r = mid;
    }
    return mid;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    FIN;

    int n;
    cin >> n;
    double a;
    cin >> a;
    fore(i, 0, n)
    {
        double xp, yp, tp;
        cin >> xp >> yp >> tp;
        x[i] = xp;
        y[i] = yp;
        t[i] = tp;
    }
    cout << fixed << setprecision(10);
    cout << binary(a, n) << "\n";

    return 0;
}
