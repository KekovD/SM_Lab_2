#include <stdio.h>

struct fridge {
    int milk;
    int meat;
    int cheese;
    int cake;
};

int operation(int a) {
    int x = 0, num, res = a;

    printf("1. Put\n");
    printf("2. Take\n");
    printf("3. Other product\n");
    printf("Choice operation:");

    do {
        scanf("%d", &x);
    } while (x < 1 || x > 3);

    if (x == 1) {
        printf("How much to put in: ");
        do {
            scanf("%d", &num);
        } while (num < 0);
        res = a + num;
        a = res;
        return a;
    }

    if (x == 2 && a == 0){
        printf("\nEmpty!");
        return a;
    } else if (x == 2 && a != 0){
        printf("How much to take out: ");
        scanf("%d", &num);
        if (num <= a) {
            res = a - num;
            a = res;
            return a;
        } else {
            printf("Too much");
            return a;
        }
    }

    if (x == 3) return a;
};

int main() {
    char choice = 0;
    struct fridge fr;

    fr.milk = 0;
    fr.meat = 0;
    fr.cake = 0;
    fr.cheese = 0;

    for(;;){
        do {
                printf("Fridge:\n");
                printf("1. Milk: %d L.\n", fr.milk);
                printf("2. Meat: %d kg\n", fr.meat);
                printf("3. Cheese: %d piece\n", fr.cheese);
                printf("4. Cake: %d piece\n", fr.cake);
                printf("Choice (print q to close): ");
                scanf("%c", &choice);
                printf("\n");
        } while (choice < '1' || choice > '4' && choice != 'q');

        if (choice == 'q') break;

        switch (choice) {
            case '1':
                fr.milk=operation(fr.milk);
                break;
            case '2':
                fr.meat=operation(fr.meat);
                break;
            case '3':
                fr.cheese=operation(fr.cheese);
                break;
            case '4':
                fr.cake=operation(fr.cake);
                break;
        }
        printf("\n");
    }

    return 0;
}
