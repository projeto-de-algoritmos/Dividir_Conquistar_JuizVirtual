#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> distances;

        // Calcula e armazena as distâncias ao quadrado para cada ponto
        for (const auto& point : points) {
            int distanceSquared = point[0] * point[0] + point[1] * point[1];
            distances.push_back({distanceSquared, distances.size()});
        }

        // Usa a função de divisão e conquista para encontrar os k pontos mais próximos
        divideAndConquer(distances, 0, distances.size() - 1, k);

        // Recupera os k pontos mais próximos
        vector<vector<int>> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(points[distances[i].second]);
        }

        return result;
    }

    // Função de divisão e conquista para encontrar os k pontos mais próximos
    void divideAndConquer(vector<pair<int, int>>& distances, int left, int right, int k) {
        if (left < right) {
            int pivotIndex = partition(distances, left, right);

            // Verifica em qual lado do pivô estão os k pontos mais próximos
            if (k < pivotIndex - left + 1) {
                divideAndConquer(distances, left, pivotIndex - 1, k);
            } else if (k > pivotIndex - left + 1) {
                divideAndConquer(distances, pivotIndex + 1, right, k - (pivotIndex - left + 1));
            }
        }
    }

    // Função auxiliar para realizar a partição
    int partition(vector<pair<int, int>>& distances, int left, int right) {
        int pivot = distances[right].first;
        int i = left - 1;

        for (int j = left; j < right; ++j) {
            if (distances[j].first < pivot) {
                ++i;
                swap(distances[i], distances[j]);
            }
        }

        swap(distances[i + 1], distances[right]);
        return i + 1;
    }
};
