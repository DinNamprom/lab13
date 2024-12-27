#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool x[][M]) {
    cout << "------------------------------------------------------------------------";
    for (int j=0;j<N;j++){
        cout << "\n|";
        for (int i=0;i<M;i++){
            if (x[j][i] == 1) {
                cout << "*";
            }else {
                cout << " ";
            }
        }
        cout << "|";
    }
    cout << "\n------------------------------------------------------------------------\n";
}

void updateImage(bool X[][M],int s,int x,int y) {
    for (int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            if (sqrt((pow((j-x),2)+pow((i-y),2))) <= s-1) {
                X[j][i] = 1;
            }
        }
    }
}