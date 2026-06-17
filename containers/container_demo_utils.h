#ifndef __CONTAINER_DEMO_UTILS_H__
#define __CONTAINER_DEMO_UTILS_H__

#include <initializer_list>
#include <iostream>
#include <tuple>
#include <utility>
using namespace std;

template <typename Container>
void InsertContainerItems(
    Container &container,
    initializer_list<pair<typename Container::insert_key_type, typename Container::insert_value_type>> items
) {
    for (const auto &[key, value] : items) {
        container.insert(key, value);
    }
}

template <typename Label, typename Item>
void PrintContainerItem(const Label &label, const Item &item) {
    cout << label << "(" << get<0>(item) << "," << get<1>(item) << ")" << endl;
}

template <typename Label, typename Container>
void PrintContainerLookup(const Label &name, const Container &container, const typename Container::key_type &key) {
    cout << name << "[" << key << "]: " << container.at(key) << endl;
}

template <typename Container>
void PrintContainerItems(const Container &container) {
    cout << "items: ";
    for (const auto &[key, value] : container) {
        cout << "(" << key << "," << value << ") ";
    }
    cout << endl;
}

#endif // __CONTAINER_DEMO_UTILS_H__
