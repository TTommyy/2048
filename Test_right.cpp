#include <iostream>
#include "Table.cpp"

using namespace std;

void show(int *array, int size){
    for(int i =0;i<size;++i){
        cout << array[i];
    }
    cout << endl;
}

int main(){

    int array[4]{1,1,1,1};
    to_right(array,4);
    show(array,4);
    merge_right(array,4);
    show(array,4);
    to_right(array,4);
    show(array,4);

}