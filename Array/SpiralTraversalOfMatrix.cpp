#include <iostream>
#include <vector>
using namespace std;

vector<int> SpiralMatrix(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;

    while (top <= bottom && left <= right) {
        // left → right
        for (int i = left; i <= right; i++){
            ans.push_back(mat[top][i]);
        }
        top++;

        // top → bottom
        for (int i = top; i <= bottom; i++){
            ans.push_back(mat[i][right]);
        }
        right--;

        // right → left
        if (top <= bottom) {
            for (int i = right; i >= left; i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        // bottom → top
        if (left <= right) {
            for (int i = bottom; i >= top; i--){
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    vector<int> ret = SpiralMatrix(mat);
    int m = ret.size();

    cout << "Spiral order: "<<endl;
    for(auto i : ret){
         cout<<i<<" ";
    }

    return 0;
}
