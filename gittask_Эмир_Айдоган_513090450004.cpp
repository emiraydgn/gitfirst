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

