#include <stdio.h>
int main() {
    char text[100];
    int k;
    char c;
    printf("Enter text: ");
    scanf("%s", text);
    char plain[100];
    printf("Enter shift: ");
    scanf("%d", &k);
    for (int i = 0; text[i] != '\0'; i++) {
        c = text[i];
        plain[i]=text[i];
        if (c >= 'A' && c <= 'Z')  // Uppercase letters
            text[i] = (c - 'A' + k) % 26 + 'A';
        else if (c >= 'a' && c <= 'z')  // Lowercase letters
            text[i] = (c - 'a' + k) % 26 + 'a';
    }
    printf("Encrypted text: %s\n", text);
    printf("Decrypted text after encryption: %s",plain);
    return 0;
}
