#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i, j, k;
    n = 5;
    m = 3;
    int alloc[n][m],max[n][m],avail[m];
    cout<<"Enter allocation\n";
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>alloc[i][j];
        }
    }

    cout<<"Enter Request\n";
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>max[i][j];
        }
    }
    cout<<"Enter available\n";
    for(i=0;i<m;i++){
        cin>>avail[i];
    }


    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {

                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                         break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    printf("Following is the SAFE Sequence\n");
    for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
    printf(" P%d", ans[n - 1]);

    return (0);
}
