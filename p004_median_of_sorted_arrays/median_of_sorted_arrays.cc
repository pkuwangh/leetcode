/*
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 *
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * The median is 2.0
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * The median is (2 + 3)/2 = 2.5
 */

#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <cstdint>
using namespace std;

#define DEBUG_INFO

// linear table
// recursive, each iteration reduce half of one array
class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int length = m + n;

        // resolve two cases for calculating median
        if (length % 2 == 1) {
            return findKthElement(nums1, 0, nums2, 0, length/2);
        } else {
            return (findKthElement(nums1, 0, nums2, 0, length/2-1) +
                    findKthElement(nums1, 0, nums2, 0, length/2)) / 2.0;
        }
    }

    void printMyVector(const vector<int>& A, const int& startIdx) {
        for (uint32_t i = startIdx; i < A.size(); ++i) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    int findKthElement(vector<int>& A, int startIdxA, vector<int>&B, int startIdxB, int k)
    {
#ifdef DEBUG_INFO
        cout << "k=" << k << ", A start=" << startIdxA << ", B start=" << startIdxB << endl;
        cout << "A: ";
        printMyVector(A, startIdxA);
        cout << "B: ";
        printMyVector(B, startIdxB);
#endif
        int lengthA = A.size();
        int lengthB = B.size();

        if (startIdxA >= lengthA) { return B[startIdxB + k]; }
        if (startIdxB >= lengthB) { return A[startIdxA + k]; }
        if (k == 0) { return ((A[startIdxA] < B[startIdxB])? A[startIdxA] : B[startIdxB]); }

        int keyA = startIdxA + (k - 1) / 2;
        int keyB = startIdxB + (k - 1) / 2;
        if (keyA >= lengthA) { keyA = lengthA - 1; }
        if (keyB >= lengthB) { keyB = lengthB - 1; }

#ifdef DEBUG_INFO
        cout << "keyA=" << keyA << ", keyB=" << keyB << endl;
#endif

        if (A.at(keyA) <= B.at(keyB)) {
            int newStartIdxA = keyA + 1;
            int newK = k - (newStartIdxA - startIdxA);
            return findKthElement(A, newStartIdxA, B, startIdxB, newK);
        } else {
            int newStartIdxB = keyB + 1;
            int newK = k - (newStartIdxB - startIdxB);
            return findKthElement(A, startIdxA, B, newStartIdxB, newK);
        }
    }
};

int main()
{
    Solution obj;

    auto getVector = [](vector<int> &vec, const initializer_list<int> &init_list)->vector<int> & {
        vec.clear();
        vec.resize(init_list.size());
        copy(init_list.begin(), init_list.end(), vec.begin());
        return vec;
    };

    vector<int> A;
    vector<int> B;

    cout<<obj.findMedianSortedArrays(getVector(A, {1, 3}), getVector(B, {2})) <<endl<<endl;
    cout<<obj.findMedianSortedArrays(getVector(A, {1, 2}), getVector(B, {3, 4})) <<endl<<endl;
    cout<<obj.findMedianSortedArrays(getVector(A, {1, 2}), getVector(B, {1, 2, 3})) <<endl<<endl;
    cout<<obj.findMedianSortedArrays(getVector(A, {1, 3}), getVector(B, {2, 4})) <<endl<<endl;

    return 0;
}

