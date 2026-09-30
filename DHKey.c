#include <stdio.h>

int main() {
    int p, g;
    int a, b;
    int A, B;
    int key1, key2;
    int i;

    printf("Enter prime number (p): ");
    scanf("%d", &p);

    printf("Enter primitive root (g): ");
    scanf("%d", &g);

    printf("Enter private key of User 1: ");
    scanf("%d", &a);

    printf("Enter private key of User 2: ");
    scanf("%d", &b);

    // Calculate public keys
    A = 1;
    for (i = 0; i < a; i++)
        A = (A * g) % p;

    B = 1;
    for (i = 0; i < b; i++)
        B = (B * g) % p;

    printf("Public Key of User 1: %d\n", A);
    printf("Public Key of User 2: %d\n", B);

    // Calculate shared secret key
    key1 = 1;
    for (i = 0; i < a; i++)
        key1 = (key1 * B) % p;

    key2 = 1;
    for (i = 0; i < b; i++)
        key2 = (key2 * A) % p;

    printf("Shared Secret Key of User 1: %d\n", key1);
    printf("Shared Secret Key of User 2: %d\n", key2);

    return 0;
}