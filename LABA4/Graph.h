#pragma once
#include "Node.h"
#include <iterator>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

namespace Modified_Wirth_structure {

    template <typename T>
    class Graph {
    private:
        vector<Node<T>> nodes;
    public:
        typedef typename vector<Node<T>>::iterator nodes_iterator;
        typedef typename vector<Node<T>>::reverse_iterator reverse_nodes_iterator;

        nodes_iterator begin_nodes() {
            return nodes.begin();
        }

        reverse_nodes_iterator reverse_begin_nodes() {
            return nodes.rbegin();
        }

        nodes_iterator end_nodes() {
            return nodes.end();
        }

        reverse_nodes_iterator reverse_end_nodes() {
            return nodes.rend();
        }

        Graph<T> operator=(Graph<T> graph) {
            this->nodes = graph.nodes;
            return *this;
        }

        void add_node(T data) {
            for (int i = 0; i < nodes.size(); i++) {
                if (nodes[i].data == data) {
                    throw runtime_error("Error");
                }
            }
            Node<T> new_node(data);
            nodes.push_back(new_node);
        }

        void add_edge(T data1, T data2) {
            int index1 = -1;
            int index2 = -1;

            for (int i = 0; i < nodes.size(); i++) {
                if (nodes[i].data == data1) {
                    index1 = i;
                }
                if (nodes[i].data == data2) {
                    index2 = i;
                }
            }

            if (index1 != -1 && index2 != -1) {
                nodes[index1].add_neighbor_index(index2);
            }
            else {
                throw runtime_error("Error");
            }
        }

        void remove_edge(T data1, T data2) {
            int index1 = -1;
            int index2 = -1;

            for (int i = 0; i < nodes.size(); i++) {
                if (nodes[i].data == data1) {
                    index1 = i;
                }
                if (nodes[i].data == data2) {
                    index2 = i;
                }
            }

            if (index1 != -1 && index2 != -1) {
                nodes[index1].remove_neighbor_index(index2);
            }
            else {
                throw runtime_error("Error");
            }
        }

        void remove_node(T data) {
            int index = -1;

            for (int i = 0; i < nodes.size(); i++) {
                if (nodes[i].data == data) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                nodes.erase(nodes.begin() + index);

                for (auto& Node : nodes) {
                    for (auto it = Node.pairs.begin(); it != Node.pairs.end(); it++) {
                        if (*it == index) {
                            Node.pairs.erase(it);
                            break;
                        }
                    }
                }
            }
            else {
                throw runtime_error("Error");
            }
        }

        void print_graph() {
            int neighbor_index;
            for (int i = 0; i < nodes.size(); i++) {
                cout << "Node " << nodes[i].data << " is connected to: ";
                for (int j = 0; j < nodes[i].pairs.size(); j++) {
                    neighbor_index = nodes[i].pairs[j];
                    cout << nodes[neighbor_index].data << " ";
                }
                cout << endl;
            }
        }

        bool check_node(T data) {
            for (int i = 0; i < nodes.size(); i++) {
                if (nodes[i].data == data) {
                    return true;
                }
            }
            return false;
        }

        bool check_edge(T data1, T data2) {
            int index1 = -1;
            int index2 = -1;
            for (int i = 0; i < nodes.size(); i++) {
                if (nodes[i].data == data1) {
                    index1 = i;
                }
                if (nodes[i].data == data2) {
                    index2 = i;
                }
            }
            if (index1 != -1 && index2 != -1) {
                for (int i = 0; i < nodes[index1].pairs.size(); i++) {
                    if (nodes[index1].pairs[i] == index2) {
                        return true;
                    }
                }
            }
            else {
                return false;
            }
        }

        int get_number_of_edges() {
            int count = 0;
            for (int i = 0; i < nodes.size(); i++) {
                for (int j = 0; j < nodes[i].pairs.size(); j++) {
                    count++;
                }
            }
            return count;
        }

        size_t get_number_of_nodes() {
            return nodes.size();
        }

        size_t get_node_degree(T data) {
            for (int i = 0; i < nodes.size(); i++) {
                if (nodes[i].data == data) {
                    return nodes[i].pairs.size();
                }
            }
            throw runtime_error("Error");
        }
    };
}