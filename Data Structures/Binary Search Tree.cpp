#include <bits/stdc++.h>
using namespace std;

template <typename T> class BSTNode{
public:
    T val;
    BSTNode *left, *right;
    BSTNode(T val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

template<typename T> class BST{
private:
    BSTNode<T> *root;

public:
    BST(){
        root = nullptr;
    }

    void insert(T val){
        if (root == nullptr){
            root = val;
            return;
        }

        BSTNode<T> *cur = root;
        while(true){
            if (val <= cur->val){
                if (cur->left)
                    cur = cur->left;
                else {
                    cur->left = new BSTNode<T> (val);
                    break;
                }
            }
            else{
                if (cur->right)
                    cur = cur->right;
                else {
                    cur->right = new BSTNode<T> (val);
                    break;
                }
            }
        }
    }

    int get_node_count(T val){
        int cnt = 0;
        BSTNode<T> *cur = root;
        while(cur){
            cnt += (val == cur->val);
            if (val <= cur->val)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return cnt;
    }

    void print(){
        if (!root)
            return;

        auto dfs = [&] (auto &&dfs, BSTNode<T> *cur){
            if (cur->left)
                dfs(dfs, cur->left);
            if (cur->right)
                dfs(dfs, cur->right);
            cout << cur->val;
        };

        dfs(root);
        cout << '\n';
    }

    void delete_tree(){
        if (!root)
            return;
        auto dfs = [&] (auto &&dfs, BSTNode<T> *cur){
            if (cur->left)
                dfs(dfs, cur->left);
            if (cur->right)
                dfs(dfs, cur->right);
            *cur = nullptr;
        };
        dfs(root);
    }

    bool is_in_tree(T val){
        bool found = false;
        BSTNode<T> *cur = root;
        while(cur){
            found |= (val == cur->val);
            if (val <= cur->val)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return found;
    }

    
};

int main() {

}
