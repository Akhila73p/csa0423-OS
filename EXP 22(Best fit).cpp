#include <iostream>
using namespace std;

int main() {
    int b, p;
    cout << "Enter number of blocks: ";
    cin >> b;

    int block[b];
    cout << "Enter block sizes:\n";
    for(int i=0;i<b;i++) cin >> block[i];

    cout << "Enter number of processes: ";
    cin >> p;

    int process[p], alloc[p];
    cout << "Enter process sizes:\n";
    for(int i=0;i<p;i++) cin >> process[i];

    // BEST FIT allocation
    for(int i=0;i<p;i++) {
        int best = -1;
        for(int j=0;j<b;j++)
            if(block[j] >= process[i] && (best == -1 || block[j] < block[best]))
                best = j;

        alloc[i] = best;

        if(best != -1)
            block[best] -= process[i];
    }

    cout << "\nProcess\tSize\tBlock\n";
    for(int i=0;i<p;i++) {
        cout << i << "\t" << process[i] << "\t";
        if(alloc[i] != -1)
            cout << alloc[i];
        else
            cout << "Not Allocated";
        cout << endl;
    }

    return 0;
}

