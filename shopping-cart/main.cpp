#include "shopping-cart.h"
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> get_items();
unordered_map<string, int> prices = get_items();

int menu();

void list_products();
void list_cart_items(const ShoppingCart &cart);
void add_item(ShoppingCart &cart);
void remove_item(ShoppingCart &cart);
void update_item_quantity(ShoppingCart &cart);
void total_price(const ShoppingCart &cart);

int main(void)
{
    ShoppingCart cart;
    int option;
    while ((option = menu()) >= 0)
    {
        switch (option)
        {
        case 0: // list products
            list_products();
            break;
        case 1: // list cart items
            list_cart_items(cart);
            break;
        case 2: // add item to cart
            add_item(cart);
            break;
        case 3: // remove item from cart
            remove_item(cart);
            break;
        case 4: // update quantity of item
            update_item_quantity(cart);
            break;
        case 5: // get total_price
            total_price(cart);
            break;
        default: // deal with errors
            cout << "Invalid option! Try again\n";
        }
    }
    return 0;
}

int menu()
{
    cout << "Select an action \n"
         << "\t 0 - List products\n"
         << "\t 1 - List items inside your cart\n"
         << "\t 2 - Add item to cart\n"
         << "\t 3 - Remove item from cart\n"
         << "\t 4 - Update quantity of item in your cart\n"
         << "\t 5 - Calculate total price of items in your cart\n"
         << "\t-1 - Exit\n"
         << "Your input: ";
    int action = 6;
    cin >> action;
    cin.ignore(9999, '\n');
    cout << "\n";
    if (action < -1)
        action = 6;
    return action;
}

void list_products()
{
    cout << "Available items:\n";
    for (auto listing : prices)
    {
        cout << "\t" << get<0>(listing) << ": €" << get<1>(listing) << "\n";
    }
    cout << "\n";
}

void list_cart_items(const ShoppingCart &cart)
{
    cout << "Items in your cart:\n";
    vector<pair<string, int>> items = cart.get_items();
    // TODO: complete the function to print the item listing
    // HINT: check documentation for std::vector and std::pair
    // HINT: check the list_products function
}

void add_item(ShoppingCart &cart)
{
    string item;
    int quantity;

    // TODO: deal with user input of the item and quantity
    // HINT: use std::cin and std::cout

    cart.add_item(item, quantity);
    cout << "Item added successfully\n\n";
}

void remove_item(ShoppingCart &cart)
{
    string item;

    // TODO: user input

    cart.delete_item(item);
    cout << "Item removed successfully\n\n";
}

void update_item_quantity(ShoppingCart &cart)
{
    string item;
    int quantity;

    // TODO: user input

    cart.update_item(item, quantity);
    cout << "Item updated successfully\n\n";
}

void total_price(const ShoppingCart &cart)
{
    vector<pair<string, int>> cart_items = cart.get_items();
    int total = 0;

    // TODO: calculate the total price for the cart's items
    // HINT: use the prices hashtable
    // HINT: check the input for std::unordered_map, std::pair, std::vector

    cout << "In total, the items in your cart are worth €" << total << ".\n\n";
}

unordered_map<string, int> get_items()
{
    unordered_map<string, int> items;
    items["laptop"] = 800;
    items["tv"] = 1500;
    items["smartphone"] = 300;
    items["hdmi_cable"] = 20;
    items["headphones"] = 150;
    items["ps5"] = 500;
    items["book"] = 10;
    items["cd"] = 16;
    return items;
}
