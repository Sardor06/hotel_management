#include "../src/main.h" // Adjust the path according to your directory structure

// ... your test functions and main function ...
// Test function for Hotel_info_read
void test_Hotel_info_read() {
    printf("Testing Hotel_info_read function...\n");
    Hotel_info_read(); // Call the function to test
    printf("Hotel_info_read test completed.\n");
}

// Test function for customer_info_read
void test_customer_info_read() {
    printf("Testing customer_info_read function...\n");
    customer_info_read(); // Call the function to test
    printf("customer_info_read test completed.\n");
}

int main() {
    // Call your test functions here
    test_Hotel_info_read();
    test_customer_info_read();

    return 0;
}