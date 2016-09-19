#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TrieTree {
    long long val;
    TrieTree* left; // zero
    TrieTree* right;    //one
    TrieTree(long long value) : val(value), left(NULL), right(NULL) {}
};

void insert(TrieTree* root, long long value) {
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

long long find(TrieTree* root, long long num) {
    long long cur = 0;
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

int main(void)  {
    long long max = LONG_LONG_MIN;
    TrieTree* root = new TrieTree(-1);
    vector<long long> vec = {1, 2, 4, 8, 16};
    for(int i = 0; i < vec.size(); ++i) {
        insert(root, vec[i]);
    }

    for(int i = 0; i < vec.size(); ++i) {
        long long  t = find(root, ~vec[i]);
        if(t > max)
            max = t;
    }

    cout << max << endl;
    return 0;
}