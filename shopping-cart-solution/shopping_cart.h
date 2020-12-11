#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>

using namespace std;

class ShoppingCart
{
private:
    unordered_map<string, int> items;

public:
    void add_item(string item, int quantity);
    void delete_item(string item);
    void update_item(string item, int quantity);
    bool contains_item(string item) const;
    vector<pair<string, int>> get_items() const;
};
