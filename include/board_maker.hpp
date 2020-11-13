#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <dirent.h> 
#include "board.hpp"

class BoardMakerFrontend {    
    
    public:
    BoardMakerFrontend();
    ~BoardMakerFrontend();


    void Menu();
    void CreateNewMap(std::string);
    void ModifyMap(std::string);
    void IntroducePos(state,Board&);
    void CopyMap(std::string,std::string);
    void Randomize(std::string);
    void ListMaps();

    private:
    bool CheckMap(std::string);
    bool CheckName(std::string);
};


