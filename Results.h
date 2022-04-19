#include <string>

class Results{
    int score,greatest;
    std::string name;
    public:
    Results(int,int,std::string);
    void save();
    void read();
};