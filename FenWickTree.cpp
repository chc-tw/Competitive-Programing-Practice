#include <iostream>
#include <vector>

using namespace std;

int n, q;
typedef long long ll;
ll BIT[5000003];

int lowbit(int pos) {
    return pos & (-pos);
}

void modify(int pos, int value) {
    for (; pos <= n; pos += lowbit(pos)) {
        BIT[pos] += value;
    }
    return;
}

ll query(int pos) {
    ll sum = 0;
    for (; pos > 0; pos -= lowbit(pos)) {
        sum += BIT[pos];
    }
    return sum;
}

int main(void) {
    scanf("%d%d", &n, &q);
    n += 2;
    char op;
    int x;
    ll y;
    while (q--) {
        scanf(" %c", &op);
        if (op == '+') {
            scanf("%d%llu", &x, &y);
            modify(x + 1, y);
        }
        else if (op == '?') {
            scanf("%d", &x);
            if (x == 0)
                printf("0\n");
            else
                printf("%lld\n", query(x));
        }
    }
    return 0;
}
