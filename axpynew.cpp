#include <iostream>
#include <fstream>
#include <vector>

void disp_matrix(const std::vector<std::vector<int>> &);
void mat_mul(const std::vector<std::vector<int>> &, const std::vector<std::vector<int>> &, std::vector<std::vector<int>> &);

int main()
{
    int rows, cols;
    std::ifstream file("mats1.txt");
    if (!file) {
        std::cerr << "Error opening file" << std::endl;
        return -1;
    }

    // Read dimensions and matrices
    std::vector<std::vector<int>> dims(2, std::vector<int>(2));
    std::vector<std::vector<std::vector<int>>> mats(2);

    for (int i = 0; i < 2; i++) {
        file >> rows >> cols;
        dims[i][0] = rows;
        dims[i][1] = cols;

        // Resize and populate matrix
        std::vector<std::vector<int>> mat(rows, std::vector<int>(cols));
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                file >> mat[r][c];
            }
        }
        mats[i]= mat;
        //mats.push_back(mat);
    }
    file.close();

    // Display matrices
    std::cout << "Matrix 1:" << std::endl;
    disp_matrix(mats[0]);
    std::cout << "Matrix 2:" << std::endl;
    disp_matrix(mats[1]);

    // Check compatibility for multiplication
    if (dims[0][1] != dims[1][0]) {
        std::cout << "Cannot multiply matrices: incompatible dimensions" << std::endl;
        return -1;
    }

    // Perform matrix multiplication
    std::vector<std::vector<int>> mat_res(dims[0][0], std::vector<int>(dims[1][1], 0));
    mat_mul(mats[0], mats[1], mat_res);

    // Display result
    std::cout << "Resultant Matrix:" << std::endl;
    disp_matrix(mat_res);

    return 0;
}

void disp_matrix(const std::vector<std::vector<int>> &mat) {
    for (const auto &row : mat) {
        for (const auto &elem : row) {
            std::cout << elem << "\t";
        }
        std::cout << "\n";
    }
}

void mat_mul(const std::vector<std::vector<int>> &mat1, const std::vector<std::vector<int>> &mat2, std::vector<std::vector<int>> &mat_res) {
    for (size_t i = 0; i < mat1.size(); ++i) {
        for (size_t k = 0; k < mat2[0].size(); ++k) {
            for (size_t j = 0; j < mat1[0].size(); ++j) {
                mat_res[i][k] += mat1[i][j] * mat2[j][k];
            }
        }
    }
}
