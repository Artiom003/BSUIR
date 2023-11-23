#pragma once
#include <vector>
#include <iostream>

using namespace std;

namespace Modified_Wirth_structure {

    template <typename T>

    class Node {
    private:
        template <typename T>
        friend class Graph;
        T data;
        vector<int> pairs;

        Node(T data) : data(data) {}

        void add_neighbor_index(int index) {
            for (int i = 0; i < pairs.size(); i++) {
                if (pairs[i] == index) {
                    throw runtime_error("Error");
                }
            }
            pairs.push_back(index);
        }

        void remove_neighbor_index(int index) {
            for (auto it = pairs.begin(); it != pairs.end(); it++) {
                if (*it == index) {
                    pairs.erase(it);
                    break;
                }
            }
        }
    };
}