#include <bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    // Função para mesclar duas listas ligadas ordenadas
    ListNode* merge(ListNode* esquerda, ListNode* direita) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (esquerda != nullptr && direita != nullptr) {
            if (esquerda->val < direita->val) {
                temp->next = esquerda;
                temp = temp->next;
                esquerda = esquerda->next;
            } else {
                temp->next = direita;
                temp = temp->next;
                direita = direita->next;
            }
        }
        while (esquerda != nullptr) {
            temp->next = esquerda;
            temp = temp->next;
            esquerda = esquerda->next;
        }
        while (direita != nullptr) {
            temp->next = direita;
            temp = temp->next;
            direita = direita->next;
        }
        return dummy->next;
    }

    // Função de ordenação merge sort para listas ligadas
    ListNode* mergeSort(vector<ListNode*>& lists, int inicio, int fim) {
        if (inicio == fim) 
            return lists[inicio];
        int meio = inicio + (fim - inicio) / 2;
        ListNode* esquerda = mergeSort(lists, inicio, meio);
        ListNode* direita = mergeSort(lists, meio + 1, fim);
        return merge(esquerda, direita);
    }

    // Função principal para mesclar k listas ligadas
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        return mergeSort(lists, 0, lists.size() - 1);
    }
};
