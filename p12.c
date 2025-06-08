#include <stdio.h>
#include <stdlib.h>

int board[10], n;

int safe(int r, int c) {
    for (int i = 0; i < r; i++)
        if (board[i] == c || abs(board[i] - c) == abs(i - r))
            return 0;
    return 1;
}

void solve(int r) {
    if (r == n) {
        for (int i = 0; i < n; i++, printf("\n"))
            for (int j = 0; j < n; j++)
                printf("%c ", board[i] == j ? 'Q' : '.');
        printf("\n");
        return;
    }
    for (int c = 0; c < n; c++)
        if (safe(r, c)) {
            board[r] = c;
            solve(r + 1);
        }
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);
    solve(0);
    return 0;
}
