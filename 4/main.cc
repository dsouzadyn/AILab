#include <bits/stdc++.h>

using namespace std;

void gen(vector<int> &arr) {
    srand(time(NULL));
    int tile;
    for(int i = 0; i < arr.size(); i++) {
        tile = rand() % arr.size();
        if (i == 0) {
            arr[i] = tile;
        } else {
            for(int j = 0; j < i; j++) {
                if(tile == arr[j]) {
                    tile = rand() % 9;
                    j = -1;
                }
            }
            arr[i] = tile;
        }
    }
}

void print(vector<int> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
        if((i+1) % 3 == 0) cout << endl;
    }
}

void getmisplaced(vector<int> arr) {
    for(int i = 1; i <= 9; i++) {
        if(i != arr[i-1]) cout << "Misplaced: " << i << " -> " << arr[i-1] << endl;
        else cout << "Not misplaced: " << i << " -> " << arr[i-1] << endl;
    }
}

int main(int argc, char *argv[])
{
    vector<int> arr(9);
    gen(arr);
    print(arr);
    getmisplaced(arr);
    return 0;
}
