#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i, j, k;
    cout<<"Enter number of Process : ";
    cin>>n;
    //n = 5;
     cout<<"number of Instance for process :";
     m=3;
     int instance[10],sum;
     for(i=0; i<m; i++)
     {
         cin>>instance[i];
     }

    int alloc[n][m],max[n][m],avail[m];
    cout<<"Enter allocation\n";
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>alloc[i][j];
        }
    }
    int p=0,hello[10];
    sum=0;
    for(i=0;i<m;i++){

        for(j=0;j<n;j++){
            sum=sum+alloc[j][i];
        }
        hello[p]=sum;
        sum=0;
        p++;
    }
    cout<<"Enter Request\n";
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>max[i][j];
        }
    }
    cout<<"Enter available\n";
    for(i=0;i<m;i++){
        avail[i]=instance[i]-hello[i];
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
