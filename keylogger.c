#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    FILE *fp;
    char input[100];

    fp = fopen("keystrokes.log", "a");

    if (fp == NULL) {
        printf("Error writing to file.");
        return 1;
    }

    time_t now;
    time(&now);

    fprintf(fp, "=== New Session: %s", ctime(&now));

    while (1) {
        printf("Enter text (type EXIT to stop): ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        time(&now);
        fprintf(fp, "[%s] %s\n", ctime(&now), input);
        fflush(fp);

        if (strcmp(input, "EXIT") == 0) {
            time(&now);
            fprintf(fp, "=== Session Closed: %s\n", ctime(&now));
            break;
        }
    }

    fclose(fp);

    return 0;
}
