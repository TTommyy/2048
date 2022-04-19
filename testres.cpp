#include "Results.cpp"

int main(){
    Results r(10,4,"Person_who_thinks_that_socialism_works");
    r.read();
    r.save();
    r.read();
}