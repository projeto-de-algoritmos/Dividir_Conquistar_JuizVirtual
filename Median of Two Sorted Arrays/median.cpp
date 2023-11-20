
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Mescla os arrays ordenados em um único arr
        vector<int> arr(nums1.size() + nums2.size());
        
        // Index
        int index1 = 0; 
        int index2 = 0; 
        
        // Mescla os arrays mantendo a ordem ordenada
        for(int i = 0; i < arr.size(); i++) {
            if (index2 != nums2.size() && (index1 == nums1.size() || nums2[index2] < nums1[index1])) {
                arr[i] = nums2[index2++];
            } else {
                arr[i] = nums1[index1++];
            }
        }
        
        // Calcula a mediana do array mesclado
        if (arr.size() % 2 == 1) {
            return arr[arr.size() / 2];
        } else {
            return ((arr[arr.size() / 2]) + (arr[arr.size() / 2 - 1])) / 2.0;
        }
    }
};