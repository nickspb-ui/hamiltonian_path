#pragma once
#include "Source.h"

int** read_graph(int, std::ifstream*); // read graph from file (in adjacency list) to adjacency matrix
bool find_hamiltonian_path(int, int**, std::vector <int>, int, bool);