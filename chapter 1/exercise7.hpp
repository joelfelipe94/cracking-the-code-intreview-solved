// Write an algorithm such that if an element in an MxN matrix is 0, its entire row
// and column are set to 0.

#include<vector>
using namespace std;

void resetColumnRow(vector< vector<int> > &mat){
    if(mat.empty())
        return;
    // get the matrix dimensions
    auto m = mat.size();
    auto n = mat[0].size();

    // stores the rows to reset
    vector<unsigned int> rows;
    for(auto i=0; i<m; i++)
        for(auto j=0; j<n;j++)
            if(mat[i][j] == 0){
                rows.push_back(i);
                break;
            }
    
    // stores the columns to reset
    vector<unsigned int> columns;
    for(auto j=0; j<n; j++)
        for(auto i=0; i<m;i++)
            if(mat[i][j] == 0){
                columns.push_back(j);
                break;
            }
    // reset the rows
    for(auto &row: rows){
        for(auto j=0; j < n; j++)
            mat[row][j] = 0;
    }
    // reset the columns
    for(auto &column: columns){
        for(auto i=0; i < m; i++)
            mat[i][column] = 0;
    }

}