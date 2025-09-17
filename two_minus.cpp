#include <iostream> 
using namespace std;

int prices[] = {7,1,5,3,6,4};

int main() {
    int max =0 ;
    for (int i = 0; i < sizeof(prices) /sizeof(prices[0]); i++) {
        for (int j = i + 1; j < sizeof(prices)/sizeof(prices[0]); j++) {
            if (prices[j] - prices[i] > max) {
                max = prices[j]-prices[i];
            }
        }
    }
    cout << max;
    return 0;

    
}