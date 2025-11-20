#include <bits/stdc++.h>
using namespace std;

void show(vector<int> &f) {
    for (int x: f) cout << (x==-1?"-":to_string(x)) << " ";
    cout << "\n";
}

void fifo(vector<int> r, int k) {
    cout << "\n--- FIFO ---\n";
    vector<int> f(k,-1);
    int ptr=0;
    for (int p: r) {
        bool hit = find(f.begin(), f.end(), p)!=f.end();
        if (!hit) { f[ptr]=p; ptr=(ptr+1)%k; }
        cout << p << ": " << (hit?"HIT ":"FAULT ") ; show(f);
    }
}

void lru(vector<int> r, int k) {
    cout << "\n--- LRU ---\n";
    vector<int> f(k,-1), last(k,-1);
    for (int t=0;t<r.size();t++) {
        int p=r[t]; bool hit=false;
        for (int i=0;i<k;i++) if (f[i]==p) {hit=true; last[i]=t;}

        if (!hit) {
            int pos=-1;
            for (int i=0;i<k;i++) if (f[i]==-1) {pos=i; break;}
            if (pos==-1) {
                pos = min_element(last.begin(), last.end()) - last.begin();
            }
            f[pos]=p; last[pos]=t;
        }
        cout<<p<<": "<<(hit?"HIT ":"FAULT "); show(f);
    }
}

void optimal(vector<int> r, int k) {
    cout << "\n--- Optimal ---\n";
    vector<int> f(k,-1);
    for (int t=0;t<r.size();t++) {
        int p=r[t]; bool hit=false;

        for(int x:f) if (x==p) hit=true;

        if (!hit) {
            int pos=-1;
            for (int i=0;i<k;i++) if(f[i]==-1){pos=i; break; }

            if (pos==-1) {
                int far=-1;
                for(int i=0;i<k;i++){
                    int nxt=1e9;
                    for(int j=t+1;j<r.size();j++)
                        if(r[j]==f[i]){ nxt=j; break; }
                    if(nxt>far){ far=nxt; pos=i; }
                }
            }
            f[pos]=p;
        }
        cout<<p<<": "<<(hit?"HIT ":"FAULT "); show(f);
    }
}

int main() {
    int n,k;
    cout<<"Enter number of references: ";
    cin>>n;

    vector<int> r(n);
    for(int &x:r) cin>>x;

    cout<<"Enter number of frames: ";
    cin>>k;

    fifo(r,k);
    lru(r,k);
    optimal(r,k);
}
