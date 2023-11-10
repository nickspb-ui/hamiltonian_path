#include "Graph.h"

int main() {
	int N;
	int** adj_matrix;
	std::ifstream input_stream;
	input_stream.open("input.txt", std::ios::in);
	input_stream >> N;
	adj_matrix = read_graph(N, &input_stream);
	input_stream.close();
	std::vector <int> path;
	bool path_found = find_hamiltonian_path(N, adj_matrix, path, 0, false);
	if (!path_found) {
		std::fstream output_stream;
		output_stream.open("output.txt", std::ios::out);
		output_stream << "0";
		output_stream.close();
	}
	return 0;
}
