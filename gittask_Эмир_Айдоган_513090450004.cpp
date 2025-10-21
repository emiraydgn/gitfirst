int** convert(const int* t, size_t n, const size_t* lns, size_t rows)
{
    size_t total = 0;
    for (size_t i = 0; i < rows; i++)
        total += lns[i];

    if (total > n)
        return nullptr;

    int** arr = new int*[rows];
    size_t index = 0;

    for (size_t i = 0; i < rows; i++) {
        arr[i] = new int[lns[i]];
        for (size_t j = 0; j < lns[i]; j++) {
            arr[i][j] = t[index];
            index++;
        }
    }

    return arr;
}
int main() {
    const int t[] = {5, 5, 5, 5, 6, 6, 7, 7, 7, 7, 8};
    const size_t lns[] = {4, 1, 5, 1};
    size_t n = 11;
    size_t rows = 4;

    int** result = convert(t, n, lns, rows);

    if (result == nullptr) {
        std::cout << "Error!" << std::endl;
        return 1;
    }

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < lns[i]; j++)
            std::cout << result[i][j] << " ";
        std::cout << std::endl;
    }

    for (size_t i = 0; i < rows; i++)
        delete[] result[i];
    delete[] result;

    return 0;
}

