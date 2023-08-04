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

template <typename T> class Vector{
private:
    T* arr;
    int n; // Current size of the array.
    int cap; // Capacity available for the array.

    void resize(int newCap){
        cap = newCap;
        T* newArr = new T[cap];
        for(int i = 0; i < n; i++)
            newArr[i] = arr[i];
        arr = newArr;
    }
public:
    Vector(){
        n = 0;
        cap = 1;
        arr = new T[cap];
    }

    Vector(int n){
        this->n = n;
        cap = n;
        arr = new T[n];
    }

    Vector(int n, T val){
        this->n = n;
        cap = n;
        arr = new T[n];
        for(int i = 0; i < n; i++)
            arr[i] = val;
    }

    int size(){
        return n;
    }

    int capacity(){
        return cap;
    }

    bool is_empty(){
        return !n;
    }

    T& at(int i){
        if (i >= 0 && i < n)
            return arr[i];
        throw out_of_range("The index used in function at() is out of bound");
    }

    void push_back(T val){
        if (n < cap){
            arr[n++] = val;
        }
        else{
            resize(cap << 1);
            arr[n++] = val;
        }
    }

    void insert(T val, int i){
        // If index is the last element we can just call push_back.
        if (i == n)
            return push_back(val);

        if (i < 0 || i > n)
            throw out_of_range("The index used in function insert() is out of bound");

        // If the capacity is not enough we need to double it.
        if (n == cap)
            cap <<= 1;

        // Copying same elements before i.
        T* newArr = new T[cap];
        for(int j = 0; j < i; j++)
            newArr[j] = arr[j];

        // Inserting new element at i.
        newArr[i] = val;

        // Shifting other elements to the right.
        for(int j = i; j < n; j++)
            newArr[j + 1] = arr[j];

        n++;
        arr = newArr;
    }

    void prepend(T val){
        return insert(val, 0);
    }

    void pop_back(){
        arr[--n] = *new T;
        if (n == cap / 4)
            resize(cap >> 1);
    }

    void remove(int i){
        // If index is the last element, we can call pop_back.
        if (i == n - 1)
            return pop_back();

        if (i < 0 || i > n)
            throw out_of_range("The index used in function insert() is out of bound");

        // Copying same elements before i.
        T* newArr = new T[cap];
        for(int j = 0; j < i; j++)
            newArr[j] = arr[j];

        // Ignoring i and adding the remaining elements.
        for(int j = i + 1; j < n; j++)
            newArr[j - 1] = arr[j];

        arr = newArr;
        n--;
        if (n == cap / 4)
            resize(cap >> 1);
    }

    void removeAll(T val){
        for(int i = n - 1; i >= 0; i--)
            if (arr[i] == val)
                remove(i);
    }

    int find(T val){
        for(int i = 0; i < n; i++)
            if (arr[i] == val)
                return i;
        return -1;
    }

    T& operator[] (const int i){
        if (i < 0 || i > n)
            throw out_of_range("Index used in subscript[] is out of range");
        return arr[i];
    }

    friend ostream& operator<< (ostream &os, const Vector<T>& v){
        for(int i = 0; i < v.n; i++)
            cout << v.arr[i] << " \n"[i == v.n - 1];
        return os;
    }
};


void test()
{
    Vector<char> v(5, 'A');
    cout << v;
    v.insert('B', 1);
//    cout << v;
    /    cout << v;
//    v.at(0);
//    show(v.at(0));
}

int main() {
    fast
    int t = 1;
//    cin >> t;

    while(t--){
        test();
    }
}