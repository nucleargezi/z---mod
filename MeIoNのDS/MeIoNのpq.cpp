#include <bits/z.h>
template <class T>
struct prique {
private:
    priority_queue <T> q;
    priority_queue <T> del;
public:
    ull size () {
        assert(q.size() >= del.size());
        return q.size() - del.size();
    }
    T top () {
        return q.top();
    }
    void erase (T a) {
        del.push(a);
        while (del.size() and del.top() == q.top()) {
            q.pop();
            del.pop();
        }
    }
    void pop () {
        erase(q.top());
    }
};
