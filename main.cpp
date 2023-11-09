#include "Graph.h"

bool find_hamiltonian_path(int N, int** adj_matrix, std::vector <int> path, int k, bool path_found) {
	if (k == N) {
		path_found = true;
		std::fstream output_stream;
		output_stream.open("output.txt", std::ios::out);
		for (int i = 0; i < N; i++) {
			output_stream << path[i] + 1 << ' ';			
		}
		output_stream.close();
		return path_found;
	}

	for (int i = 0; i < N && !path_found; i++) {		
		if ((k == 0) || ((adj_matrix[i][path[k - 1]] != 0 && find(path.begin(), path.end(), i) == path.end()))) {
			path.push_back(i);
			path_found = find_hamiltonian_path(N, adj_matrix, path, k + 1, path_found);
			path.pop_back();
		}
	}
	return path_found;
}


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
