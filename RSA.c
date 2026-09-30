#include <stdio.h>

int main() {
    int p, q, n, phi;
    int e, d, msg, encrypted, decrypted;
    int i;

    printf("Enter two prime numbers: ");
    scanf("%d %d", &p, &q);

    n = p * q;
    phi = (p - 1) * (q - 1);

    // Find e
    for (e = 2; e < phi; e++) {
        int gcd = 1;

        for (i = 1; i <= e && i <= phi; i++) {
            if (e % i == 0 && phi % i == 0)
                gcd = i;
        }

        if (gcd == 1)
            break;
    }

    // Find d
    for (d = 1; d < phi; d++) {
        if ((d * e) % phi == 1)
            break;
    }

    printf("Public Key  : (%d, %d)\n", e, n);
    printf("Private Key : (%d, %d)\n", d, n);

    printf("Enter message (number): ");
    scanf("%d", &msg);

    // Encryption: C = M^e mod n
    encrypted = 1;
    for (i = 0; i < e; i++)
        encrypted = (encrypted * msg) % n;

    printf("Encrypted Message: %d\n", encrypted);

    // Decryption: M = C^d mod n
    decrypted = 1;
    for (i = 0; i < d; i++)
        decrypted = (decrypted * encrypted) % n;

    printf("Decrypted Message: %d\n", decrypted);

    return 0;
}