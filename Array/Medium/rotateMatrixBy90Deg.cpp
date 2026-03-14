#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>RotateMatrix(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>>ans(m , vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[j][n-1-i]=matrix[i][j];
        }
    }
    return ans;
}

int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>>matrix(n , vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> rotated = RotateMatrix(matrix);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << rotated[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// optimal approach 


#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>RotateMatrix(vector<vector<int>> matrix){
    int n = matrix.size();

    //   transpose 
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j] , matrix[j][i]);
        }
    }

    // reverse 
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin() , matrix[i].end());
    }
    return matrix; 
}