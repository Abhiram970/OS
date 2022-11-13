#include <bits/stdc++.h>
using namespace std;

bool search(int pg[], int index, vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == pg[index]) return true;
    }
    return false;
}

int predictOptimal(int pg[], int pn, vector<int> v, int index) {
    int res = -1, highest = index;
    for(int i = 0; i < v.size(); i++) {
        int j;
        for(j = index; j < pn; j++) {
            if(pg[j] == v[i]) {
                if(j > highest) {
                    highest = j;
                    res = i;
                }
            }
        }
        if(j == pn) return i;
    }
    return res == -1 ? 0 : res;
}

void optimalPage(int pg[], int pn, int fn) {
    vector<int> v;
    int hits = 0;
    for(int i = 0; i < pn; i++) {
        if(v.size() < fn) {
            if(search(pg, i, v)) {
                hits++;
            }
            else {
                v.push_back(pg[i]);
            }
        }
        else {
            if(search(pg, i, v)) {
                hits++;
            }
            else {
                int pos = predictOptimal(pg, pn, v, i+1);
                v[pos] = pg[i];
            }
        }
    }
    printf("No. of hits : %d\n", hits);
    printf("No. of misses : %d", pn - hits);
}

int main()
{
    int pg[] = {1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
    int pn = sizeof(pg) / sizeof(pg[0]);
    int fn = 4;
    optimalPage(pg, pn, fn);
    return 0;
}

