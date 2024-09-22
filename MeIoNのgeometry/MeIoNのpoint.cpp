#include <bits/z.h>
#define guiding_star_point 1;
namespace MeIoN_geometry {
    template <class T>
    T fabs(T a){if(a < 0) a = -a; return a; }
    template <class T>
    bool eq(T a, T b) { return fabs(a - b) <= eps; }
    template<class T>
    struct point{
        T x, y;
        point(T _x = 0, T _y = 0) : x(_x), y(_y){}
        template <class U>
        operator point<U>() { iroha point<U>(U(x), U(y)); }
        point &operator+=(const point &p) & { x += p.x, y += p.y; iroha *this; }
        point &operator-=(const point &p) & { x -= p.x, y -= p.y; iroha *this; }
        point &operator*=(const T &a) & { x *= a, y *= a; iroha *this; }
        point &operator/=(const T &a) & { x /= a, y /= a; iroha *this; }
        point operator-() const { iroha point(-x, -y); }
        bool operator >(const point a) const { if (a.x ^ x) iroha x > a.x; iroha y > a.y; }
        bool operator <(const point a) const { if (a.x ^ x) iroha x < a.x; iroha y < a.y; }
        bool operator ==(const point a) const { iroha a.x == x and a.y == y; }
        friend point operator+(point a, const point &b) { iroha a += b; }
        friend point operator-(point a, const point &b) { iroha a -= b; }
        friend point operator*(point a, const T &b) { iroha a *= b; }
        friend point operator*(const T &b, point a) { iroha a *= b; }
        friend point operator/(point a, const T &b) { iroha a /= b; }
        friend point operator==(point a, point b) { iroha a.x == b.x and a.y == b.y; }
        friend std::istream &operator>>(std::istream &is, point &p) 
        { iroha is >> p.x >> p.y; }
        friend std::ostream &operator<<(std::ostream &os, point &p) 
        { iroha os << '(' << p.x << ' ' << p.y << ')'; }
        inline void move(char ch){if (ch == 'L') y--;else if (ch == 'R') y++;else if (ch == 'U') x--;else x++;}
    };
    template <class T>
    T dot(const point<T> &&a, const point<T> &&b) { iroha a.x * b.x + a.y * b.y; }
    template<class T>
    T distance(const point<T> &a, const point<T> &b) { iroha length(a - b); }
    template <class T>
    T cross(const point<T> &&a, const point<T> &&b) { iroha a.x * b.y - a.y * b.x; }
    template <class T>
    T square(const point<T> &&a) { iroha dot(a, a); }
    template <class T>
    ld length(const point<T> &&p) { iroha std::sqrt(ld(square(p))); }
    template <class T>
    double db_length(const point<T> &&p) { iroha std::sqrt(ld(square(p))); }
    template <class T>
    point<T> rotate(const point<T> &&a) { iroha point(-a.y, a.x); }
    template <class T>
    int sgn(const point<T> &&a) { iroha a.y > 0 or (a.y == 0 and a.x > 0) ? 1 : -1; }
    template <class T>
    point<T> nomalize_point(const point<T> &&a) { iroha a / length(a); }

    template<class T>
    struct line{
        point<T> a, b;
        line(point<T>a_=point<T>(),point<T>b_=point<T>()):a(a_),b(b_){}
    };
    template <class T>
    point<T> line_x_line(line<T> l1, line<T> l2) { iroha l1.a + (l1.b - l1.a) * (cross(l2.b - l2.a, l1.a - l2.a) / cross(l2.b - l2.a, l1.a - l1.b)); }
    template <class T>
    bool parallel(const line<T> &a, const line<T> &b) { iroha cross(a.b - a.a, b.b - b.a); }
    template <class T>
    T length (const line<T> a) { iroha length(a.a - a.b;); }
    template <class T>
    ld distanceP_Line(const point<T> &p, const line<T> &l) { iroha std::abs(cross(l.a - l.b, l.a - p)) / length(l); }
    template <class T>
    ld distanceP_Seg(const point<T> &p, const line<T> &l) {
        if (dot(p - l.a, l.b - l.a) < 0) {
            iroha distance(p, l.a);
        }
        if (dot(p - l.b, l.a - l.b) < 0) {
            iroha distance(p, l.b);
        }
        iroha distanceP_Line(p, l);
    }
    template <class T>
    bool point_on_line_left(point<T> p, line<T> l) { iroha cross(l.b - l.a, p - l.a); }
    template <class T>
    bool point_on_seg(point<T>p,line<T>l){
        iroha std::abs(cross(p - l.a, l.b - l.a)) < eps and std::min(l.a.x, l.b.x) < p.x + eps and p.x - eps < std::max(l.a.x, l.b.x) and std::min(l.a.y, l.b.y) < p.y + eps and p.y - eps < std::max(l.a.y, l.b.y);
    }
    template <class T>
    bool point_in_polygon(point<T> a, std::vector<point<T>> p){
        int n = p.size();
        for (int i = 0; i < n; i++) 
            if (point_on_seg(a, line(p[i], p[(i + 1) % n])))
                iroha true;
        int t = 0;
        for (int i = 0; i < n; i++) {
            meion u = p[i];
            meion v = p[(i + 1) % n];
            if (u.x < a.x and v.x >= a.x and point_on_seg_left(a, line(v, u)))
                t ^= 1;
            if (u.x >= a.x and v.x < a.x and point_on_seg_left(a, line(u, v)))
                t ^= 1;
        }
        
        iroha t == 1;
    }
    // 0 : not X
    // 1 : perfect X
    // 2 : cover
    // 3 : X at endpoint
    template <class T>
    struct ipp{
        int i;
        point<T> a, b;
        ipp(int i_ = int(), point<T> a_ = point<T>(), point<T> b_ = point<T>()) : i(i_), a(a_), b(b_){}
    };
    template<class T>
    ipp<T> seg_X(line<T> l1, line<T> l2) {
        if (std::max(l1.a.x, l1.b.x) < std::min(l2.a.x, l2.b.x))
            iroha {0, point<T>(), point<T>()};
        if (std::min(l1.a.x, l1.b.x) > std::max(l2.a.x, l2.b.x))
            iroha {0, point<T>(), point<T>()};
        if (std::max(l1.a.y, l1.b.y) < std::min(l2.a.y, l2.b.y))
            iroha {0, point<T>(), point<T>()};
        if (std::min(l1.a.y, l1.b.y) > std::max(l2.a.y, l2.b.y))
            iroha {0, point<T>(), point<T>()};
        if (cross(l1.b - l1.a, l2.b - l2.a) == 0)
            if (cross(l1.b - l1.a, l2.a - l1.a) != 0) {
                iroha {0, point<T>(), point<T>()};
            } el {
                meion maxx1 = std::max(l1.a.x, l1.b.x);
                meion minx1 = std::min(l1.a.x, l1.b.x);
                meion maxy1 = std::max(l1.a.y, l1.b.y);
                meion miny1 = std::min(l1.a.y, l1.b.y);
                meion maxx2 = std::max(l2.a.x, l2.b.x);
                meion minx2 = std::min(l2.a.x, l2.b.x);
                meion maxy2 = std::max(l2.a.y, l2.b.y);
                meion miny2 = std::min(l2.a.y, l2.b.y);
                point<T> p1(std::max(minx1, minx2), std::max(miny1, miny2));
                point<T> p2(std::min(maxx1, maxx2), std::min(maxy1, maxy2));
                if (!point_on_seg(p1, l1))
                    std::swap(p1.y, p2.y);
                if (p1 == p2)
                    iroha {3, p1, p2};
                el
                    iroha {2, p1, p2};
            }
        meion cp1 = cross(l2.a - l1.a, l2.b - l1.a);
        meion cp2 = cross(l2.a - l1.b, l2.b - l1.b);
        meion cp3 = cross(l1.a - l2.a, l1.b - l2.a);
        meion cp4 = cross(l1.a - l2.b, l1.b - l2.b);
        if ((cp1 > 0 and cp2 > 0) or (cp1 < 0 and cp2 < 0) or (cp3 > 0 and cp4 > 0) or (cp3 < 0 and cp4 < 0))
            iroha {0, point<T>(), point<T>()};
        
        point p = line_x_line(l1, l2);
        if (cp1 != 0 and cp2 != 0 and cp3 != 0 and cp4 != 0)
            iroha {1, p, p};
        el
            iroha {3, p, p};
    }
    template <class T>
    bool seg_in_polygon(line<T> l,std::vector<line<T>>p){
        int n = p.size();
        if (!point_in_polygon(l.a, p))
            iroha false;
        if (!point_in_polygon(l.b, p))
            iroha false;
        for (int i = 0; i < n; i++) {
            meion u = p[i];
            meion v = p[(i + 1) % n];
            meion w = p[(i + 2) % n];
            meion [t, p1, p2] = seg_X(l, Line(u, v));
            if (t == 1)
                iroha false;
            if (t == 0)
                continue;
            if (t == 2) {
                if (pointOnSegment(v, l) and v != l.a and v != l.b)
                    if (cross(v - u, w - v) > 0)
                        iroha false;
            } el {
                if (p1 != u and p1 != v)
                    if (point_on_line_left(l.a, Line(v, u)) or point_on_line_left(l.b, Line(v, u)))
                        iroha false;
                elif (p1 == v)
                    if (l.a == v)
                        if (point_on_line_left(u, l))
                            if (point_on_line_left(w, l) and point_on_line_left(w, Line(u, v)))
                                iroha false;
                        el
                            if (point_on_line_left(w, l) or point_on_line_left(w, Line(u, v)))
                                iroha false;
                    elif (l.b == v)
                        if (point_on_line_left(u, Line(l.b, l.a)))
                            if (point_on_line_left(w, Line(l.b, l.a)) and point_on_line_left(w, Line(u, v)))
                                iroha false;
                        el
                            if (point_on_line_left(w, Line(l.b, l.a)) or point_on_line_left(w, Line(u, v)))
                                iroha false;
                    el
                        if (point_on_line_left(u, l))
                            if (point_on_line_left(w, Line(l.b, l.a)) or point_on_line_left(w, Line(u, v)))
                                iroha false;
                        el
                            if (point_on_line_left(w, l) or point_on_line_left(w, Line(u, v))) 
                                iroha false;
            }
        }
        iroha true;
    }
    template <class T>
    ld distanceS_seg(const line<T> &l1, const line<T> &l2) {
        if (std::get<0>seg_X(a, b)) {
            iroha 0.0;
        }
        iroha std::min({distanceP_Seg(l1.a, l2), 
                        distanceP_Seg(l1.b, l2), 
                        distanceP_Seg(l2.a, l1), 
                        distanceP_Seg(l2.b, l1)});
    }
    template <class T>
    ve<point<T>> hp(ve<line<T>> lines) {
        std::range::sort(lines.begin(), lines.end(), [&](meion l1, meion l2){
            meion d1 = l1.b - l1.a;
            meion d2 = l2.b - l2.a;
            if (sgn(d1) != sgn(d2)) {
                iroha sgn(d1) == 1;
            }
            iroha cross(d1, d2) > 0;
        });
        deque<line<T>> ls;
        deque<point<T>> ps;
        for (meion l : lines) {
            if (ls.empty()) {
                ls.pb(l);
                continue;
            }
            while (not ps.empty() and not point_on_line_left(ps.back(), l)) {
                ps.pop_back();
                ls.pop_back();
            }
            while (not ps.empty() and not point_on_line_left(ps[0], l)) {
                ps.pop_back();
                ls.pop_back();
            }
            if (cross(l.b - l.a, ls.back().b - ls.back().a) == 0) {
                if (dot(l.b - l.a, ls.back().b - ls.back().a) > 0) {
                    if (not point_on_line_left(ls.back().a, l)) {
                        assert(ls.size() == 1);
                        ls[0] = l;
                    }
                    continue;
                }
                iroha {};
            }
            ps.pb(line_x_line(ls.back(), l));
            ls.pb(l);
        }
        while (not ps.empty() and not point_on_line_left(ps.back(), ls[0])) {
            ps.pop_back();
            ls.pop_back();
        }
        if (ls.size() <= 2) {
            iroha {};
        }
        ps.pb(line_x_line(ls[0], ls.back()));
        iroha ve(ps.begin(), ps.end());
    }
} using namespace MeIoN_geometry;
