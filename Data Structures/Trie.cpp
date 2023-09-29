#include <bits/stdc++.h>
using namespace std;

class Trie{
    static const int ALPHABET_SIZE = 128;
    Trie *children[ALPHABET_SIZE];
    bool isLeaf;

    Trie(){
        for(int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = nullptr;
        isLeaf = false;
    }

    void insert(string &word){
        Trie *cur = this;
        for(char c: word){
            if (!cur->children[c])
                cur->children[c] = new Trie();
            cur = cur->children[c];
        }
        cur->isLeaf = true;
    }

    bool search(string &word){
        Trie *cur = this;
        if (!cur)
            return false;
        for(char c: word){
            if (!children[c])
                return false;
            cur = cur->children[c];
        }
        return cur->isLeaf;
    }

    bool startsWith(string &word){
        Trie *cur = this;
        if (!cur)
            return false;
        for(char c: word){
            if (!children[c])
                return false;
            cur = cur->children[c];
        }
        return true;
    }

    void remove(string &word){
        erase(this, word, 0);
    }

    bool isEmpty(Trie *cur){
        for(int i = 0; i < ALPHABET_SIZE; i++)
            if (cur->children[i])
                return false;
        return true;
    }

    Trie* erase(Trie *cur, string &word, int depth){
        if (!cur)
            return nullptr;

        if (depth == word.length()){
            cur->isLeaf = false;

            if (isEmpty(cur)){
                delete (cur);
                cur = nullptr;
            }

            return cur;
        }

        cur->children[word[depth]] = erase(cur->children[word[depth]], word, depth + 1);

        if (!cur->isLeaf && isEmpty(cur)){
            delete (cur);
            cur = nullptr;
        }
        return cur;
    }

};