//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define f first
#define s second
#define show(x) cout << (#x) << " is " << (x) << endl
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) ((ll)((v).size()))
#define posmod(v, m) ((v) % (m) + (m)) % m;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v){forn(i,sz(v)) out<<v[i]<<' ';return out;}
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
int dx[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int dy[] = {+0, +0, +1, -1, +1, -1, +1, -1};

template<typename T> class Node{
public:
    T val;
    Node* next;

    Node(){
        val = *new T;
        next = nullptr;
    }
    Node(T val){
        this->val = val;
        next = nullptr;
    }
    Node(T val, Node<T>* next){
        this->val = val;
        this->next = next;
    }
    Node(Node* node){
        val = node->val;
        next = node->next;
    }
};

template<typename T> class Queue{
private:
    int sz, first, n;
    T *arr;
public:
    Queue(int sz){
        this->sz = sz;
        arr = new T[sz];
        n = first = 0;
    }

    void enqueue(T val){
        if (n == sz)
            throw out_of_range("Queue reached maximum size.");
        arr[n++] = val;
    }

    T dequeue(){
        if (!n)
            throw out_of_range("Queue is empty.");
        T ret = arr[first];
        arr[first] = *new T;
        first = (first + 1) % sz;
        n--;
        return ret;
    }

    bool empty(){
        return !n;
    }

    bool full(){
        return n == sz;
    }

    void print(){
        for(int i = first, cnt = 0; cnt < n; i = (i + 1) % sz, cnt++)
            cout << arr[i] << " \n"[cnt == n - 1];
    }
};

void test()
{
    int n;
    cin >> n;
    Queue<int> q(5);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        q.enqueue(x);
    }
    show(q.full());
    show(q.empty());
    q.print();
    show(q.dequeue());
    q.print();
    show(q.dequeue());
    q.print();
    show(q.dequeue());
    q.print();
    show(q.dequeue());
    q.print();
    show(q.empty());
}

int main() {
    fast
    int t = 1;
//    cin >> t;

    while(t--){
        test();
    }
}