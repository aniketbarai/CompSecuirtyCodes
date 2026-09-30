#include <stdio.h>
#include <string.h>

int main() {
    char text[100], encrypted[100], decrypted[100];
    char matrix[20][20], decrypt[20][20];
    int cols, rows, i, j, k = 0;

    printf("Enter Text: ");
    gets(text);

    printf("Enter Number of Columns: ");
    scanf("%d", &cols);

    // Remove spaces
    int n = 0;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] != ' ')
            text[n++] = text[i];
    }
    text[n] = '\0';

    rows = (n + cols - 1) / cols;

    // Fill row-wise
    k = 0;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (k < n)
                matrix[i][j] = text[k++];
            else
                matrix[i][j] = 'X';
        }
    }

    // Encryption
    k = 0;

    for (j = 0; j < cols; j++) {
        for (i = 0; i < rows; i++) {
            encrypted[k++] = matrix[i][j];
        }
    }

    encrypted[k] = '\0';

    printf("Encrypted Text: %s\n", encrypted);

    // Decryption
    k = 0;

    for (j = 0; j < cols; j++) {
        for (i = 0; i < rows; i++) {
            decrypt[i][j] = encrypted[k++];
        }
    }

    k = 0;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            decrypted[k++] = decrypt[i][j];
        }
    }

    decrypted[k] = '\0';

    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}
