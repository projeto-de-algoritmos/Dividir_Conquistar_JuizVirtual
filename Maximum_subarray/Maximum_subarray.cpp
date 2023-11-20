#include <vector>
#include <climits>   // para INT_MIN
#include <algorithm> // para max

class Solution {
    // Função para combinar as soluções dos subproblemas
    int combinar(std::vector<int>& nums, int baixo, int meio, int alto, int maxEsquerda, int maxDireita) {
        int somaEsquerda = INT_MIN;
        int soma = 0;

        // Calcular a soma máxima no lado esquerdo do meio
        for (int i = meio; i >= baixo; i--) {
            soma += nums[i];
            if (somaEsquerda < soma) {
                somaEsquerda = soma;
            }
        }

        soma = 0;
        int somaDireita = INT_MIN;

        // Calcular a soma máxima no lado direito do meio
        for (int i = meio + 1; i <= alto; i++) {
            soma += nums[i];
            if (somaDireita < soma) {
                somaDireita = soma;
            }
        }

        // Retornar o máximo entre as somas no lado esquerdo, direito e a soma total
        return std::max(maxEsquerda, std::max(maxDireita, somaEsquerda + somaDireita));
    }

    // Função recursiva para dividir e conquistar
    int dividirEConquistar(std::vector<int>& nums, int baixo, int alto) {
        // Caso base: quando baixo é maior ou igual a alto, retorna o elemento único
        if (baixo >= alto) {
            return nums[baixo];
        }

        // Calcular o índice médio
        int meio = (baixo + alto) / 2;

        // Chamar a função recursivamente para a metade esquerda e direita
        int maxEsquerda = dividirEConquistar(nums, baixo, meio);
        int maxDireita = dividirEConquistar(nums, meio + 1, alto);

        // Chamar a função combinar para obter a solução final
        return combinar(nums, baixo, meio, alto, maxEsquerda, maxDireita);
    }

public:
    // Função principal para encontrar a soma máxima do subarray
    int maxSubArray(std::vector<int>& nums) {
        int baixo = 0;
        int alto = nums.size() - 1;

        // Chamar a função dividirEConquistar
        return dividirEConquistar(nums, baixo, alto);
    }
};
