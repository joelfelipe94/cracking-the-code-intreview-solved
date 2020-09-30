// Given an image represented by an NxN matrix, where each pixel in the image is
// 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
// place?
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void rotateImage(vector< vector<int> > &image){
    auto n = image.size();
    for(int i=0; i < (n+1)/2; i++){
        for(int j=0; j < (n+1)/2; j++){
            auto iTemp = i,jTemp = j;
            auto copia = image[i][j];
            for(auto k = 0; k < 4; k++){
                swap(copia, image[jTemp][n-1-iTemp]);
                swap(iTemp, jTemp);
                jTemp = n-jTemp-1;
            }

        }
    }
}