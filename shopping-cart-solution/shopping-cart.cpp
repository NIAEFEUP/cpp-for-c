#include "shopping-cart.h"

void ShoppingCart::add_item(string item, int quantity)
{
    items[item] = quantity;
}

void ShoppingCart::delete_item(string item)
{
    items.erase(item);
}

void ShoppingCart::update_item(string item, int quantity)
{
    items[item] = quantity;
}

bool ShoppingCart::contains_item(string item) const
{
    return items.find(item) != items.end();
}

vector<pair<string, int>> ShoppingCart::get_items() const
{
    vector<pair<string, int>> out;

    for (auto item : items)
    {
        string id = get<0>(item);
        int quantity = get<1>(item);
        out.push_back(make_pair(id, quantity));
    }

    return out;
}
