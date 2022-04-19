#include <iostream>
#include <fstream>
#include "Results.h"
#include <cstdlib>
#include <string>
#include <iomanip>



/*void del_last_line(int size)   
{    
    char file_name[]="res.txt";
    std::fstream file_org;
    std::fstream file_new;  

    file_org.open(file_name,std::ios::in);
    file_new.open("temp.txt",std::ios::app);
    
    int line=1;
    std::string lin;

    while(line<size){
        getline(file_org,lin);
        file_new.write(&lin[0],lin.length());
        file_new << "\n";
        line++;
    }
    remove(file_name);
    file_org.close();

    rename("temp.txt",file_name);
    file_new.close();   
    
}*/


void Results::read(){
    std::fstream file;
    file.open("res.txt",std::ios::in);
    std::string res;
    while(getline(file,res)){
        std::cout << std::setw(20)<< res << std::endl;
    }

}


Results::Results(int score,int greatest,std::string name): score{score},greatest{greatest}, name{name}{};


/*void Results::save(){
    int size=5;
    std::fstream file;
    file.open("res.txt",std::ios::in);
    std::string res;
    for(int i=0;i<size;++i){
        getline(file,res);
    }

    file.close();
    int i_score;

    std::string c_score;
    int j=0;
    while(res[j]!='\0'){
        c_score[j]=res[j];
        j++;
    }
    i_score=stoi(c_score);
    if(i_score<score){
        del_last_line(size);
        file.open("res.txt",std::ios::app);
        file <<  score;
        file << " " << greatest << " ";
        file.write(&name[0],name.length());
        file << "\n";
        file.close();
    }
}*/




void Results::save(){
    int done=0;
    char file_name[]="res.txt";
    std::fstream file_org;
    std::fstream file_new;  

    file_org.open(file_name,std::ios::in);
    file_new.open("temp.txt",std::ios::app);


    std::string lin;

    while(getline(file_org,lin)){

        std::string c_score;
        int j=0;
        while(lin[j]!=' '){
            c_score[j]=lin[j];
            j++;
        }
        int i_score=stoi(c_score);

        if(i_score<score && done==0){
            file_new <<  score;
            file_new << " " << greatest << " ";
            file_new.write(&name[0],name.length());
            file_new << "\n";
            done++;
        }
        file_new.write(&lin[0],lin.length());
        file_new << "\n";
    }

    if(done==0){
        file_new <<  score;
        file_new << " " << greatest << " ";
        file_new.write(&name[0],name.length());
        file_new << "\n";
    }
    remove(file_name);
    file_org.close();

    rename("temp.txt",file_name);
    file_new.close();  
    
}