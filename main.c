/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAXN 10001

int parent[MAXN];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y)
        parent[x] = y;
}

int main() {
    int n, num_connections;
    scanf("%d%d", &n, &num_connections);

    int connections[num_connections][2];
    for (int i = 0; i < num_connections; i++) {
        scanf("%d%d", &connections[i][0], &connections[i][1]);
    }
    
    for (int i = 0; i < n; i++)
        parent[i] = i;
    
    for (int i = 0; i < num_connections; i++)
        merge(connections[i][0], connections[i][1]);
    
    int num_components = 0;
    for (int i = 0; i < n; i++)
        if (parent[i] == i)
            num_components++;
    
    if (num_components == 1)
        printf("0\n");
    else if (num_components > 1) {
        int num_moves = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (find(i) != find(j)) {
                    merge(i, j);
                    num_moves++;
                }
            }
        }
        printf("%d\n", num_moves);
    }
    else {
        printf("-1\n");
    }
    
    return 0;
}
