#include "word2vec.h"
#include <vector>

int64_t Scalar(const std::vector<int>& a, const std::vector<int>& b) {
    int64_t sum = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        sum += static_cast<int64_t>(a[i]) * b[i];
    std::vector<int> first_vector = vectors[0];
    int64_t maximal = -1;
    for (size_t i = 1; i < words.size(); ++i) {
        int64_t current = Scalar(first_vector, vectors[i]);
        if (current == maximal) {
            closest.push_back(words[i]);
        } else if (current > maximal) {
            maximal = current;
            closest.clear();
            closest.push_back(words[i]);
        }
    }
    return closest;
}
