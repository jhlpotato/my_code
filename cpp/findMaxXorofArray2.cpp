#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

const int NUM = 100001;
long long int llarray[NUM];

struct TrieTree {
    long long int val;
    TrieTree* left; // zero
    TrieTree* right;    //one
    TrieTree(long long int value) : val(value), left(NULL), right(NULL) {}
};

void insert(TrieTree* root, long long int value) {
    TrieTree* p = root;
    for(int i = 39; i >= 0; --i) {
        int temp = (value >> i) & 1;
        if(temp == 0) {
            if(!p->left) {
                TrieTree* node = new TrieTree(0);
                p->left = node;
                p = p->left;
            } else {
                p = p->left;
            }
        } else {
            if(!p->right) {
                TrieTree* node = new TrieTree(0);
                p->right = node;
                p = p->right;
            } else {
                p = p->right;
            }
        }
    }
}


int getHighOfTree(TrieTree* root) {
    if(root == NULL)
        return 0;
    int left = getHighOfTree(root->left);
    int right = getHighOfTree(root->right);
    return left > right ? left + 1 : right + 1;
}

long long int find(TrieTree* root, long long int num) {
    long long int cur = 0;
    TrieTree* p = root;
    for(int i = 39; i >= 0; --i) {
        cur <<= 1;
        int temp = (num >> i) & 1;
        if(temp == 0) {
            if(!p->left) {
                if(!p->right)
                    return cur;
                else 
                    p = p->right;
            } else {
                cur += 1;
                p = p->left;
            }
        } else {
            if(!p->right) {
                if(!p->left)
                    return cur;
                else
                    p = p->left;
            } else {
                cur += 1;
                p = p->right;
            }
        }
    }
    return cur;
}

void deleteTree(TrieTree* root) {
    if(root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
    return;
}


int main(void)  {
    long long int max = -1;
    //long long int max = LONG_LONG_MIN;
    //TrieTree* root = new TrieTree(-1);

    long long int cur = 0;
    int N;
    //cin >> N;
    while(cin >> N) {
        TrieTree* root = new TrieTree(-1);
        cur = 0;
        for (int i = 0; i < N; ++i) {
            cin >> llarray[i]; 
            cur ^= llarray[i];
        }

        long long int ins = 0, max = -1; 
        insert(root, 0);
        for(int i = 0; i < N; ++i) {
            ins ^= llarray[i];
            cur ^= llarray[i];
            insert(root, ins);
            long long int t = find(root, ~cur);
            if(t > max)
                max = t;
        }
    /*
    vector<long long int>pre_xor_vec;
    vector<long long int>suf_xor_vec;
    pre_xor_vec.push_back(0);
    suf_xor_vec.push_back(0);

    // pre_xor_vec and suf_xor_vec size()+1
    for(int i = 1; i <= N; ++i) {
        long long int pre = pre_xor_vec[i-1] ^ llarray[i-1];
        long long int suf = suf_xor_vec[i-1] ^ llarray[N-i];
        pre_xor_vec.push_back(pre);
        suf_xor_vec.push_back(suf);
    }

    // size() + 1
    for(int i = 0; i <= N; ++i) {
        insert(root, pre_xor_vec[i]);
        for(int j = 0; j <= N-i; j++) {
            long long int t = find(root, ~suf_xor_vec[j]);
            if(t > max)
                max = t;
        }
    }
    */
        cout << max << endl;
        deleteTree(root);
    }

    return 0;
}