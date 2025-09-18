#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
    cout << "Enter number of values: ";
    int vals;
    cin >> vals;
    int valArray[vals];
    int *ptr;
    ptr = valArray;
    int entry; int min; int max; float avg=0;
    for (int i =1; i<=vals; i++){
        cout << "Enter value " << i << ": " ;
        cin >> entry;
        avg = avg + entry;
        *(ptr+(i-1))=entry;
    }
    avg = avg/vals;

    ptr = valArray;
    min = *(ptr);
    max = *(ptr);
    for(int i=1; i<vals; ++i){
        if (*(ptr+i)<min){
            min = *(ptr+i);
        }
        if (*(ptr+i)>max)
            max = *(ptr+i);
    }
    ptr = valArray;
    float summation =0;
    for (int i =1; i<=vals; ++i){
        summation = summation + (((*(ptr+(i-1))))-avg) * (((*(ptr+(i-1))))-avg);
    }
    float SD = sqrt(summation/(vals));
    cout << "Minimum: "<<min<<endl;
    cout << "Maximum: "<<max<<endl;
    cout << "Average: "<<avg<<endl;
    cout << "Standard Deviation: "<<SD<<endl;
    return 0;
}