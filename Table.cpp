#include "Table.h"
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <iomanip>


bool done_left(int*,int);
bool done_right(int*,int);
void to_left(int*,int);
void to_right(int*,int);
void merge_left(int*,int);
void merge_right(int*,int);

int random_int(int);

Table::Table(int size): size{size} {//konstruktor
    table= new int*[size];
    for(int i=0;i<size;++i)
        table[i]=new int[size];
}
Table::~Table(){//destruktor
    for(int i=0;i<size;++i)
        delete[] table[i];
    delete[] table;
}

bool Table::left(){
    int n_move=0;//not moved
    for(int i=0;i<size;++i){
        n_move+=done_left(table[i],size);
        to_left(table[i],size);
        merge_left(table[i],size);
        to_left(table[i],size);
    }

    if(n_move!=size)add();
    return true;
}

bool Table::right(){
    int n_move=0;//not moved
    for(int i=0;i<size;++i){
        n_move+=done_right(table[i],size);
        to_right(table[i],size);
        merge_right(table[i],size);
        to_right(table[i],size);
    }

    
    if(n_move!=size)add();
    return true;
}

bool Table::up(){
    int n_move=0;//not moved
    int ptr[size];
    for(int i=0;i<size;++i){
        for(int w=0; w<size;++w){
            ptr[w]=table[w][i];
        }
        n_move+=done_left(ptr,size);
        to_left(ptr,size);
        merge_left(ptr,size);
        to_left(ptr,size);
        for(int w=0; w<size;++w){
            table[w][i]=ptr[w];
        }
    }

    if(n_move!=size)add();
    return true;    

}

bool Table::down(){
    int n_move=0;//not moved
    int ptr[size];
    for(int i=0;i<size;++i){
        for(int w=0; w<size;++w){
            ptr[w]=table[w][i];
        }
        n_move+=done_right(ptr,size);
        to_right(ptr,size);
        merge_right(ptr,size);
        to_right(ptr,size);
        for(int w=0; w<size;++w){
            table[w][i]=ptr[w];
        }
    }

    if(n_move!=size)add();
    return true;
    
}


bool Table::add(){// dodaje 2 na losowe puste miejsce
    int i=0;
    while(i<size*size){
        int w=random_int(size);
        int k=random_int(size);
        if(table[w][k]==0){
            table[w][k]=2;
            return true;
        }
        i++;
    }
    return false;
}

void Table::show(){
    for(int i=0; i< size; ++i){
        std :: cout << "      |";
        for(int j=0;j<size;j++){
            std::cout << std::setw(4)<< table[i][j] << "|";
        }
        std::cout << std::endl; 

    }
}

int Table::score(){
    int s=0;
    for(int w=0;w<size;++w){
        for(int k=0;k<size;++k) 
            s+=table[w][k];
    }
    return s;
}

int Table::greatest(){
    int s=0;
    for(int w=0;w<size;++w){
        for(int k=0;k<size;++k)
            table[w][k]>s? s=table[w][k]:s=s;
    }
    return s;
}

bool Table::may_move(){
    for(int w=0;w<size;++w){
        for(int k=0;k<size-1;++k){
            if(table[w][k]==table[w][k+1]) return true;
        }
    }

    for(int k=0;k<size;++k){
        for(int w=0;w<size-1;++w){
            if(table[w][k]==table[w+1][k]) return true;
        }
    }

    for(int w=0;w<size;++w){
        for(int k=0;k<size;++k){
            if(table[w][k]==0) return true;
        }
    }
    return false;
}








bool done_left(int *array, int size){// sprawdza czy wszystkie zera sa przeniesione na prawo
    for(int i=0; i<size-1; ++i){
        if(array[i]==0 && array[i+1]!=0)
            return false;
    }
    return true;
}

void to_left(int *array, int size){// przenosi wszystkie zera na prawo
    while (!done_left(array,size)){
        for(int i=0; i<size-1; ++i){
            if(array[i]==0 && array[i+1]!=0){
                array[i]=array[i+1];
                array[i+1]=0;
            }
        }
    }
}

void merge_left(int *array, int size){//scala jednakowe obok siebie w lewo
    for(int i=0;i<size-1;++i){
        if(array[i]==array[i+1]&& array[i]!=0){
            array[i]+=array[i+1];
            array[i+1]=0;
            i++;
        }
    }
}

bool done_right(int *array, int size){// sprawdza czy wszystkie zera sa przeniesione na lewo
    for(int i=size-1; i>0; --i){
        if(array[i]==0 && array[i-1]!=0)
            return false;
    }
    return true;
}

void to_right(int *array, int size){// przenosi wszystkie zera na lewo
    while (!done_right(array,size)){
        for(int i=size-1; i>0; --i){
            if(array[i]==0 && array[i-1]!=0){
                array[i]=array[i-1];
                array[i-1]=0;
            }
        }
    }
}

void merge_right(int *array, int size){//scala jednakowe obok siebie w lewo
    for(int i=size-1;i>0;--i){
        if(array[i]==array[i-1]&& array[i]!=0){
            array[i]+=array[i-1];
            array[i-1]=0;
            i--;
        }
    }
}

int random_int(int limit)//Generator liczb losowych
{
    using namespace std;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0,limit-1);
    return dis(gen);
}