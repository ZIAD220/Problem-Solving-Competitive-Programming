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
    int n;
    Node<T> *head, *tail;
public:
    Queue(){
        n = 0;
        head = tail = new Node<T>();
    }

    void enqueue(T val){
        n++;
        if (n == 1){
            tail->val = val;
            head = tail;
        }
        else if (n == 2){
            tail = new Node<T> (val);
            head->next = tail;
        }
        else{
            tail->next = new Node<T>(val);
            tail = tail->next;
        }
    }

    T dequeue(){
        if (n == 0)
            throw out_of_range("Queue is empty.");
        n--;
        int ret = head->val;
        head = head->next;
        return ret;
    }

    bool empty(){
        return !n;
    }

    void print(){
        Node<T>* cur = head;
        while(cur != nullptr){
            cout << cur->val << ' ';
            cur = cur->next;
        }
        cout << '\n';
    }
};

void test()
{
    int n;
    cin >> n;
    Queue<int> q;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        q.enqueue(x);
    }
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