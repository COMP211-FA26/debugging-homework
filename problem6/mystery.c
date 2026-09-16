#include <stdio.h>

#define ACTIVE    1
#define VERIFIED  2
#define LOCKED    4
#define STAFF     8

int normalize_username(char username[]) {
    int changes = 0;
    for (int i = 0; username[i] != '\0'; i++) {
        if (username[i] >= 'a' && username[i] <= 'z') {
            username[i] = username[i] - 'a' + 'A';
            changes++;
        }
    }
    return changes;
}

int verification_flags(int flags, int changes) {
    if (changes > 0) {
        flags = flags | VERIFIED;
    }
    return flags;
}

int unlock_after_verification(int flags) {
    return flags ^ LOCKED;
}

int prepare_account(char username[], int flags) {
    int changes = normalize_username(username);
    flags = verification_flags(flags, changes);
    flags = unlock_after_verification(flags);
    return flags;
}

int main(void) {
    char username[] = "cmiller";
    int flags = ACTIVE;

    printf("Before processing: %s, flags=%d\n", username, flags);
    flags = prepare_account(username, flags);
    printf("After processing:  %s, flags=%d\n", username, flags);
    printf("Expected status: ACTIVE and VERIFIED, not LOCKED.\n");
    return 0;
}
