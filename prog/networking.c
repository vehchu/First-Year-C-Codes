#include <stdio.h>
#include <math.h>

int calculateDelta(int num);
int calculatePrefix(int num);

int main() {
    int num, choice;
    printf("Enter number: ");
    scanf("%d", &num);

    printf("\nWhat will you calculate?\n");
    printf("\t[1] Prefix\n");
    printf("\t[2] Delta\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Prefix: /%d\n", calculatePrefix(num));
            break;
        case 2:
            printf("Delta: %d\n", calculateDelta(num));
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

int calculatePrefix(int num) {
    int pref = 2;
    for (int i = 0; i != 10000000; ++i) {
        pref = pow(2, i) - 2;
        if (pref >= num) {
            pref = 32 - i;
            return pref;
        }
    }
    return pref;
}

int calculateDelta(int num) {
    
    int pref = 2;
    for (int i = 0; i != 10000; i++) {
        if (num <= 8) {
            num = 8 - num;
            pref = pow(2, num);
            if (pref >= num) {
                return pref;
            }
        } else if (num <= 16 && num > 8) {
            num = 16 - num;
            pref = pow(2, num);
            if (pref >= num) {
                return pref;
            }
        } else if (num <= 24 && num > 16) {
            num = 24 - num;
            pref = pow(2, num);
            if (pref >= num) {
                return pref;
            }
        } else if (num <= 32 && num > 24) {
            num = 32 - num;
            pref = pow(2, num);
            if (pref >= num) {
                return pref;
            }
        }
    }
    return pref;
}