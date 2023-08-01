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

template<typename T> class LinkedList{
private:
    int n;
    Node<T>* head;
public:
    LinkedList(){
        n = 0;
        head = new Node<T>();
    }

    LinkedList(int n, T val){
        this->n = n;
        head = new Node<T>();
        if (!n)
            return;
        head->val = val;
        Node<T>* prev = head;
        for(int i = 1; i < n; i++){
            Node<T>* newNode = new Node<T>(val);
            prev->next = newNode;
            prev = prev->next;
        }
    }

    int size(){
        return n;
    }

    bool is_empty(){
        return !n;
    }

    Node<T>* at(int i){
        if (i < 0 || i >= n)
            throw out_of_range("Index used in function at() is out of bound.");
        Node<T> *cur = head;
        for(int j = 1; j <= i; j++)
            cur = cur->next;
        return cur;
    }

    void push_front(T val){
        n++;
        if (n == 1){
            head = new Node<T>(val);
            return;
        }
        Node<T>* prevHead = new Node<T> (head->val, head->next);
        head->val = val;
        head->next = prevHead;
    }

    void pop_front(){
        if (head == nullptr)
            return;
        head = head->next;
        n--;
    }

    void push_back(T val){
        n++;
        if (n == 1){
            head = new Node<T>(val);
            return;
        }

        Node<T>* cur = head;
        while(cur->next)
            cur = cur->next;
        cur->next = new Node<T> (val);
    }

    void pop_back(){
        n = max(0, n - 1);
        if (!n){
            head = nullptr;
            return;
        }

        Node<T>* prev = head;
        for(int i = 1; i < n; i++)
            prev = prev->next;
        prev->next = nullptr;
    }

    Node<T>* front(){
        return head;
    }

    Node<T>* back(){
        Node<T>* cur = head;
        for(int i = 1; i < n; i++)
            cur = cur->next;
        return cur;
    }

    void insert(int idx, T val){
        if (!idx)
            return push_front(val);
        if (idx == n)
            return push_back(val);
        if (idx < 0 || idx > n)
            throw out_of_range("Inserted index is out of range.");

        Node<T>* prev = head;
        for(int i = 1; i < idx; i++)
            prev = prev->next;
        Node<T>* newNode = new Node<T>(val);
        newNode->next = prev->next;
        prev->next = newNode;
    }

    void erase(int idx){
        if (!idx)
            return pop_front();
        if (idx == n - 1)
            return pop_back();
        if (idx < 0 || idx >= n)
            throw out_of_range("Erased index is out of range.");

        Node<T>* prev = head;
        for(int i = 1; i < idx; i++)
            prev = prev->next;
        prev->next = prev->next->next;
        n--;
    }

    void remove(T val){
        if (!n)
            return;
        if (head->val == val)
            return pop_front();

        Node<T>* prev = head;
        for(int i = 1; i < n - 1; i++){
            Node<T>* cur = prev->next;
            if (cur->val == val){
                prev->next = cur->next;
                n--;
                return;
            }
            prev = prev->next;
        }
    }

    void print(){
        Node<T> *cur = head;
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
    LinkedList<int> l(5, 5);
    l.print();
}

int main() {
    fast
    int t = 1;
//    cin >> t;

    while(t--){
        test();
    }
}
/*
 * Tested:
 * - Constructors.
 * - push_back();
 * - pop_back();
 * - size();
 * - print();
 * - is_empty();
 * - at();
 * - push_front()
 * - pop_front();
 * - front();
 * - back();
 * - insert();
 * - erase();
 * - remove();
 */