#include <stdio.h>

int main() {
    char text[100];
    int key, choice;

    printf("\n1. Encrypt");
    printf("\n2. Decrypt");
    printf("\nEnter your choice [1 OR 2]: ");
    scanf("%d", &choice);

    printf("\nEnter the message: ");
    scanf("%s", text);

    printf("\nEnter the key: ");
    scanf("%d", &key);

    if (choice == 2)
        key = -key;

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = (text[i] - 'A' + key + 26) % 26 + 'A';
        else if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = (text[i] - 'a' + key + 26) % 26 + 'a';
    }

    printf("\nResult: %s", text);

    return 0;
}
