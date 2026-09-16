#include <stdio.h>
#include <string.h>

int count_character_types(char password[]) {
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_symbol = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        char c = password[i];

        if (c >= 'A' && c <= 'Z') {
            has_uppercase = 1;
        } else if (c >= 'a' && c <= 'z') {
            has_lowercase = 1;
        } else if (c >= '0' && c <= '9') {
            has_digit = 1;
        } else {
            has_symbol = 1;
        }
    }

    int count = 0;

    if (has_uppercase) {
        count++;
    }

    if (has_lowercase) {
        count++;
    }

    if (has_digit) {
        count++;
    }

    if (has_symbol) {
        count++;
    }

    return count;
}

int calculate_strength(char password[]) {
    int length = strlen(password);
    int types = count_character_types(password);

    int strength = length + types;

    if (length >= 8) {
        strength += 2;
    } else if (types >= 3) {
        strength += 2;
    }

    return strength;
}

int is_strong_password(char password[]) {
    int strength = calculate_strength(password);

    if (strength >= 14) {
        return 1;
    }

    return 0;
}

int main(void) {
    char passwords[][20] = {"abc", "password", "Hello7!", "Hello123",
                            "Systems7!"};

    int expected[] = {0, 0, 0, 1, 1};

    for (int i = 0; i < 5; i++) {
        int actual = is_strong_password(passwords[i]);

        printf("Password: %-12s Expected: %s  Actual: %s\n", passwords[i],
               expected[i] ? "Strong" : "Weak", actual ? "Strong" : "Weak");
    }

    return 0;
}