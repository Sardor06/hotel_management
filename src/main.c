#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define red "\x1b[31m"
#define green "\x1b[32m"
#define reset "\x1b[0m"
#define blue "\x1b[36m"
#define yellow "\x1b[33m"

FILE *f, *Users;

typedef struct Customer {
    char CroomType;
    int Cnumbers;
    int CroomId;
    char Cfull_name[50];
    int Cduration; 
} Customer;

typedef struct Hotel {
    char name[20];
    int numberOfRooms;
    char roomType;
    int capacity;
    double price;
} Hotel;

void Hotel_info_read() {
    f = fopen("../test/Hotel.txt", "a");
    if (f == NULL) {
        // handle error
    }

    Hotel r1;
    printf(yellow "Mehmonxona nomini kiriting: ");
    scanf("%s", r1.name);

    printf("Mehmon xonadagi xonalar soni nechta: ");
    scanf("%d", &r1.numberOfRooms);

    for (int i = 0; i < r1.numberOfRooms; ++i) {
        while (1) {
            printf("Xona turi(B- busnes, S-standart): ");
            scanf(" %c", &r1.roomType); 

            if (r1.roomType == 'B' || r1.roomType == 'S') {
                break;
            } else {
                printf("\nBoshqattan kiriting");
            }
        }

        printf("Necha kishilik xona: ");
        scanf("%d", &r1.capacity);

        if (r1.roomType == 'B') {
            r1.price = 20000;
        } else {
            r1.price = 15000;
        }

        fprintf(f, "%d.%c %d %lf\n", i + 1, r1.roomType, r1.capacity, r1.price);
    }

    fclose(f);
}

void customer_info_read() {
    f = fopen("../test/Hotel.txt", "r+");
    if (f == NULL) {
        // handle error
    }

    Customer c;
    int boolen = 0, size = 1;
    while (1) {
        while (1) {
            printf(blue "Xona turi(B- busnes, S-standart): " reset);
            scanf(" %c", &c.CroomType); 

            if (c.CroomType == 'B' || c.CroomType == 'S') {
                break;
            } else {
                printf(blue "\nBoshqattan kiriting" reset);
            }
        }

        printf(blue "necha kishilik xona: " reset);
        scanf("%d", &c.Cnumbers);
        int xonalar = 1, onlik = 0, plus = 0;
        char a[26];
        fseek(f, 0, SEEK_SET);
        while (fgets(a, 26, f)) {
            size += strlen(a);
            onlik++;
            xonalar++; 
            if (a[2 + plus] == c.CroomType && a[4 + plus] - '0' == c.Cnumbers) {
                c.CroomId = xonalar;
                if (a[22] >= '1' && a[22] <= '9') {
                    size++;
                    boolen = 1;
                    continue;
                }
                boolen = 1;
                break;
            }
            if (onlik == 9) {
                plus++;
            }
            size++;
        }

        if (boolen) {
            if (a[22] >= '1' && a[22] <= '9') {
                printf(red "Ushbu xonalar band!" reset);
                plus = 0;
                onlik = 0;
                continue;
            }
            break;
        } else {
            printf(red "Bunday xona mavjud emas\n" reset);
            size = 0;
            plus = 0;
            onlik = 0;
        }
    }

    char text[50];
    printf(blue "Qancha vaqt turmoqchisiz: " reset);
    scanf("%d", &c.Cduration);
    printf(blue "Ism familyangizni kiriting: " reset);
    scanf("%s", c.Cfull_name);
    printf(blue "ID raqam kiriting: " reset);
    scanf("%s", text);
    fseek(f, size - 6, SEEK_SET);
    fprintf(f, "%s\n", text);
    fclose(f);

    c.Cfull_name[strlen(c.Cfull_name) - 1] = '\0'; 
    Users = fopen("../test/users.txt", "a+");
    if (Users == NULL) {
        // handle error
    }
    fprintf(Users, "%d - xona: %s %d kunga, ID: %s\n", c.CroomId, c.Cfull_name, c.Cduration, text);
    fclose(Users);
}

int main() {
    int breakWhile = 1;
    while (breakWhile) {
        printf(green "1.Mijozlarni yaratish\n2.Hotel yaratish\n3.Hotel ma'lumotlarini ko'rish\n4.Mijozlar ro'yxati\n5.Mijozni o'chirish\n6.Mijoz ma'lumotlarini chqarish\n7.Exit\n" reset);
        int menyu;
        scanf("%d", &menyu);


        switch (menyu) {
            case 1: customer_info_read(); break;
            case 2: Hotel_info_read();    break;
            case 3: printf("None\n");     break;
            case 4: printf("None\n");     break;
            case 5: printf("None\n");     break;
            case 6: printf("None\n");     break;
            case 7: breakWhile = 0;       break;
        }
    }

    return 0;
}
