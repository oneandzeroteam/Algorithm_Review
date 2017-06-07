#include <iostream>
#include <vector>

using namespace std;

int n, m;

struct UnionFind{
    vector<int> parent, rank, enemy, size;
    UnionFind(int n) : parent(n),rank(n,1),enemy(n,-1),size(n,1){
        for(int i =0; i<n; ++i){
            parent[i] =i;
        }
    }

    int find (int u){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    //After merging,it returns the representative of merged sets.

    int merge(int u, int v){
        if(u == -1 || v == -1)
            return max(u,v);
        u = find(u); v = find(v);
        if(u ==v) return u;
        if(rank[u] > rank[v]) swap(u,v);
        if(rank[u] == rank[v]) ++rank[v];
        parent[u] = v;
        size[v] += size[u];
        return v;
    }

    bool dis(int u, int v){
        u = find(u); v = find(v);

        if(u == v) return false;

        int a = merge(u, enemy[v]);
        int b = merge(v, enemy[u]);
        enemy[a] = b; enemy[b] = a;
        return true;
    }
    bool ack(int u, int v){
        u= find(u); v = find(v);

        if(enemy[u] == v) return false;

        int a = merge(u,v), b = merge(enemy[u], enemy[v]);
        enemy[a] = b;
        if(b != -1) enemy[b] = a;
        return true;
    }



};


int maxParty(UnionFind& a){
    int ret = 0;
    for(int node = 0; node < n; ++node){
        if(a.find(node) == node){
            int enemy = a.enemy[node];
            if(enemy > node) continue;
            int mySize = a.size[node];
            int enemySize = (enemy == -1 ? 0 : a.size[enemy]);
            ret += max(mySize, enemySize);
        }
    }
    return ret;
}

int main() {

    int c;
    scanf("%d",&c);
    while(c--){
        scanf("%d%d",&n,&m);
        UnionFind a(n);
        int contradict = -1;
        for(int i =1; i<=m; ++i){
            int p,q;
            char stance[4];
            scanf("%s%d%d",stance,&p,&q);
            if(contradict != -1) continue;
            if(string(stance) == "ACK"){
                if(!a.ack(p,q))
                    contradict = i;
            } else
                if(!a.dis(p,q))
                    contradict = i;
        }
        if(contradict == -1)
            cout << "MAX PARTY SIZE IS "<< maxParty(a) << endl;
        else
            cout << "CONTRADICTION AT " << contradict << endl;

    }
}
