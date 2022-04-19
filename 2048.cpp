#include "Table.cpp"
#include <iostream>
#include <iomanip>
#include <time.h>
#include "Results.cpp"
using namespace std;

char manual[]="         A-left\n        D-right\n           W-up\n         S-down\n         Q-quit";


int main(){
    cout << "##############2048###############\n";
    cout << " ####### Touch to play!! ######\n";

    char s=' ';
    char move=' ';
    cin >> s;
    int size=4;
    Table t(size);
    t.add();
    int play=1;
    time_t e = time(NULL);
    while(play){
        system("clear");
        cout << endl;
        cout << setw(14) <<"##############" << " Your score: " << t.score() << " #############" << endl;
        cout << setw(15) <<"##############   Aim: 2048  #############" << endl;
        cout << setw(15) <<"########## Your greatest:  " << t.greatest() << "  ##########"<< endl;
        cout << setw(15) <<"###########   Clock " <<(time(NULL)-e)/60<< ":" <<(time(NULL)-e)%60<< "  ###############"<< endl;
        cout  <<manual << endl;
        t.show();

        if(t.greatest()>=2048) cout << setw(20) << "\nYou have alreday won!! Go for a record now!\n";

        if(t.may_move()){
            cout << "Enter your move: ";
            cin >> move;

            switch(move){
                case 'a':
                case 'A':
                    t.left();
                    break;
                case 'd':
                case 'D':
                    t.right();
                    break;
                case 'w':
                case 'W':
                    t.up();
                    break;
                case 's':
                case 'S':
                    t.down();
                    break;
                case 'q':
                case 'Q':
                    play=0;
                    break;
                default:
                    cout <<"Can't hear you\n";

            }

        }
        else
            play=0;
        
    }

    system("clear");
    cout << setw(20)<< "########## 2048 Final results: ########### \n";
    cout << setw(20)<<"############## Greatest: " << t.greatest()<< "  ##############\n";
    cout << setw(20)<<"############## Score: " << t.score()<< "     ##############\n";
    cout << setw(20)<<"############# Play time  " <<(time(NULL)-e)/60<< ":" <<(time(NULL)-e)%60<< " #############\n"<< endl;

    t.show();
    cout << setw(20)<< "Press to see results table!" << endl;
    char n;
    cin >> n;

    system("clear");
    cout << setw(20)<< "#### Enter your name: " << endl;
    string name;
    cin >> name;
    Results r(t.score(),t.greatest(),name);
    r.save();
    cout << endl;
    r.read();
    cout <<setw(20)<<"\n######### Restart to play again!!#########";
}