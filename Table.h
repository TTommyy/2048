//Tablica do gry 2048

class Table{
    int size;
    int**table;
    public:
    Table(int size);//konstruktor
    ~Table();//destruktor

    bool left();//przesuwa
    bool right();
    bool up();
    bool down();

    bool may_move();//sprawdza czy istnieje mozliwy ruch

    int score();//wynik
    int greatest();// najwyzsza

    bool add();//dodaje nowa
    void show();//wyswietla
    };