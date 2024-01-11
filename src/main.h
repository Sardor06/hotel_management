#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
// ... include any other standard headers used in your main.c ...

// If you have any structs, enums, or macros defined in main.c, include them here
typedef struct Customer {
    // ... structure definition ...
} Customer;

typedef struct Hotel {
    // ... structure definition ...
} Hotel;

// Declare the functions you will test
void Hotel_info_read();
void customer_info_read();

#endif // MAIN_H
