#include <iostream> 
using namespace std;

int nums[] = {2,7,11,15};
int target = 9;
int main() {
    for (int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++) {
        for (int j = i + 1; j < sizeof(nums)/sizeof(nums[0]); j++) {
            if (nums[i] + nums[j] == target) {
                cout << "[" << i << "," << j << "]" << endl;
                break;
            }
        }
    break;
    }
    return 0;
}