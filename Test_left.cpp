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
    to_left(array,4);
    show(array,4);
    merge_left(array,4);
    show(array,4);
    to_left(array,4);
    show(array,4);

    Table t(4);
    t.show();
    t.add();
    t.add();
    t.add();
    t.add();
    t.add();
    cout << "###############################\n";
    t.show();
    t.left();
    cout << "###############################\n";
    t.show();
    cout << "###############################\n";
    t.left();
    t.show();
    cout << "###############################\n";
    t.left();
    t.show();
    cout << "###############################\n";
    t.left();
    t.show();
    cout << "###############################\n";
    t.left();
    t.show();
    cout << "###############################\n";
    t.left();
    t.show();
    cout << "###############################\n";
    t.left();
    t.show();


}