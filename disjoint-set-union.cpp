#include<iostream>

using namespace std;

class DSU {

private:
    int size;
    int *parent;
    
public:
    DSU(int size) {
        parent = new int[size+1];
        size = size;
    }

    void make_set(int node) {
        parent[node] = node;
    }

    /* Worst case can take O(n) for each call (Pretty bad)
    * Path Compression can optimize it iteratively
    * Once we find the parent of a node we can change its
    * parent to the found parent. Tree's breadth will increase
    * with each call of find_set. Finally each call for find_set
    * will be O(1)
    * */
    
    int find_set(int node) {
        if (parent[node] == node) {
            return node;
        }
        return find_set(parent[node]);

        // path compression
        // return parent[node] = find_set(parent[node])
    }

    void union_sets(int a, int b) {
        int set1 = find_set(a);
        int set2 = find_set(b);

        if(set1 != set2) {
            parent[set1] = set2;
        }
    }
};

int main() {
    DSU a(10);
}