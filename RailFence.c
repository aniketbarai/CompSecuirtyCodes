#include <stdio.h>
#include <string.h>

int main() {
    char text[100], encrypted[100], decrypted[100];
    int rails, i, j, index = 0;

    printf("Enter Text: ");
    gets(text);

    printf("Enter Number of Rails: ");
    scanf("%d", &rails);

    // Encryption
    index = 0;

    for (i = 0; i < rails; i++) {
        for (j = i; j < strlen(text); j += rails) {
            encrypted[index++] = text[j];
        }
    }

    encrypted[index] = '\0';

    printf("Encrypted Text: %s\n", encrypted);

    // Decryption
    index = 0;

    for (i = 0; i < rails; i++) {
        for (j = i; j < strlen(text); j += rails) {
            decrypted[j] = encrypted[index++];
        }
    }

    decrypted[strlen(text)] = '\0';

    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}