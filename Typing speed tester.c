#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    char sentence[] = "The quick brown fox jumps over the lazy dog.";
    char input[1000];
    time_t start, end;
    int errors = 0;

    printf("Type the following sentence exactly:\n\n\"%s\"\n\n", sentence);
    printf("Press ENTER when ready to start typing...");
    getchar();

    // Record start time
    time(&start);

    printf("\nStart typing:\n");
    fgets(input, sizeof(input), stdin);

    // Record end time
    time(&end);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Count errors
    for (int i = 0; i < strlen(sentence); i++) {
        if (input[i] != sentence[i]) {
            errors++;
        }
    }

    // Calculate time taken in seconds
    double time_taken = difftime(end, start);

    // Calculate words per minute (WPM)
    int words = 0;
    for (int i = 0; i < strlen(input); i++) {
        if ((i == 0 || input[i - 1] == ' ') && input[i] != ' ' && input[i] != '\0') {
            words++;
        }
    }

    double wpm = (words / time_taken) * 60;

    printf("\nTime taken: %.2f seconds\n", time_taken);
    printf("Typing speed: %.2f words per minute (WPM)\n", wpm);
    printf("Errors: %d\n", errors);

    return 0;
}