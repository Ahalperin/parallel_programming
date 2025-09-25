#include <iostream>
#include <cstdint>

using namespace std;

void printMatrix(float V[], const uint32_t x, const uint32_t y)
{
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            if(j>0) cout << ", ";
            cout << V[x*i+j];
        }
        cout << endl;
    }
}

void multMatrix(float A[], const uint32_t ax, const uint32_t ay, float B[], const uint32_t bx, const uint32_t by, float C[])
{
    for(int i=0; i<ax; i++)
    {
        for(int j=0; j<by; j++)
        {
            for(int m=0; m<by; m++)
            {
                float a = A[ax*i+j];
                float b = B[by*m+j];
                C[ay*i+j] += a*b;
            }
        }
    }
}

int main() {
    
    const uint32_t ax = 1;
    const uint32_t ay = 2;
    float A[ax*ay] = 
    {
        1, 2
    };
    const uint32_t bx = 2;
    const uint32_t by = 2;
    float B[bx*by] = 
    {
        2, 4, 
        6, 8
    };

    float C[ay*by] = {0};
    
    printMatrix(A, ax, ay);
    cout << "X" << endl;
    printMatrix(B, bx, by);
    cout << "=" << endl;
    multMatrix(A, ax, ay, B, bx, by, C);
    printMatrix(C, ax, by);
    
    return 0;
}