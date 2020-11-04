#include <vector>
#include <string>
#include <iostream>

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

class BoardMakerFrontend;

enum writemode {file, terminalicons, terminalcords};
enum state {ClearPath, Wall, Obstacle, Car, Finish}; //Un 0 es un espacio, un 1 es un muro, un 2 es obstáculo, un 3 la posición inicial del coche, un 4 la meta.
typedef std::vector<std::vector<state>> MatrixState;


class Board {

    int M_; //Ancho
    int N_; //Alto
    MatrixState MatrixBoard_; 

public:

    Board(); //Constructor por defecto
    Board(int,int); //Pasando M y N
    Board(std::string); //Abrir de fichero
    ~Board();
    
    int GetM() const;
    int GetN() const;
    state GetState(int,int) const;
    void ChangeState(int,int,state);

    void Write(std::ostream &os, writemode) const;
};