#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find modular inverse of a under modulo m
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

// Function to decrypt the affine cipher
void decryptAffine(char* ciphertext, int a, int b) {
    int a_inv = modInverse(a, 26);
    if (a_inv == -1) {
        printf("Inverse of a doesn't exist, decryption not possible.\n");
        return;
    }

    for (int i = 0; i < strlen(ciphertext); i++) {
        if (ciphertext[i] != ' ') {
            int y = ciphertext[i] - 'A';
            int x = (a_inv * (y - b + 26)) % 26;
            printf("%c", (x + 'A'));
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    char ciphertext[100];
    int a, b;

    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strcspn(ciphertext, "\n")] = '\0'; // Remove newline character

    printf("Enter the value of a: ");
    scanf("%d", &a);

    printf("Enter the value of b: ");
    scanf("%d", &b);

    printf("Decrypted text: ");
    decryptAffine(ciphertext, a, b);

    return 0;
}
