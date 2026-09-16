#include <stdio.h>

int apply_coupon(int subtotal) {
    int coupon_value = 7;
    int discounted = subtotal - coupon_value;
    return discounted;
}

int add_service_fee(int subtotal) {
    int service_fee = 4;
    int with_fee = subtotal + service_fee;
    return apply_coupon(with_fee);
}

int price_order(int item_price) {
    int quantity = 3;
    int subtotal = item_price * quantity;
    return add_service_fee(subtotal);
}

int checkout(int price) {
    int order_number = 42;
    int total = price_order(price);
    return total;
}

int main(void) {
    int starting_price = 12;
    int final_price = checkout(starting_price);
    printf("Order total: $%d\n", final_price);
    return 0;
}
