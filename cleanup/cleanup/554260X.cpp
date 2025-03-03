#include <iostream>
#include <algorithm>
using namespace std;
#include "cleanup/debug.h"
int main() {
    int i,n,j,m;
    cin >> n >>m ;
    vector<vector<char>> arr(n, vector<char>(m));
    for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin >> arr[i][j];
            }
    }
    // print(arr);
    for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(arr[i][j]=='S'||arr[i][j]=='.'){
                        if(i-1>=0&&arr[i-1][j]!='#'){
                            cout << "U";
                            arr[i][j]='#';
                        }
                        else if(i+1<n&&arr[i+1][j]!='#'){
                            cout << "D";
                            arr[i][j]='#';
                        }
                        else if(j-1>=0&&arr[i][j-1]!='#'){
                            cout << "L";
                            arr[i][j]='#';
                        }
                        else if(j+1<m&&arr[i][j+1]!='#'){
                            cout << "R";
                            arr[i][j]='#';
                        }
                }
                else if(arr[i][j]=='E'){
                    break;
                }
                }
            }



    return 0;
}