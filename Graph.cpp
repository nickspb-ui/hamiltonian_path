#include "Graph.h"


int** read_graph(int N, std::ifstream* input_file) {
	int** adj_matrix = new int* [N];
	for (int i = 0; i < N; i++) {
		adj_matrix[i] = new int[N];
		for (int j = 0; j < N; j++) {
			adj_matrix[i][j] = 0;
		}
	}
	char tmp[BUFFER_SIZE], buffer[BUFFER_SIZE];
	int tmp_size, num, vertex = -1;
	while (!input_file->eof()) {
		input_file->getline(buffer, BUFFER_SIZE);
		strcpy_s(tmp, 1, "");
		tmp_size = 0;
		for (int i = 0; i < BUFFER_SIZE; i++) {
			if ((buffer[i] == ' ' || buffer[i] == '\0') && tmp_size != 0) {								
				num = atoi(tmp) - 1;
				adj_matrix[num][vertex] = 1;
				adj_matrix[vertex][num] = 1;
				strcpy_s(tmp, 1, "");
				tmp_size = 0;
			}
			if (isdigit(buffer[i])) {
				tmp[tmp_size] = buffer[i];
				tmp_size++;
			}
			if (buffer[i] == '\0') {
				break;
			}
		}
		vertex++;
	}

	return adj_matrix;
}