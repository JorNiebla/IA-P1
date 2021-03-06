/// Clase Board
///
/// @brief clase que maneja un tablero de estados. Los estados
/// pueden ser coche, final, obstaculo, casilla libre y camino.
///
/// @date 15 Nov 2020
/// 
/// Autores: 
/// Jorge Niebla Núñez <alu0101215457@ull.edu.es>
/// Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// Jaime Pablo Pérez Moro <alu0101278919@ull.edu.es>

#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

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
enum state {ClearPath, Path, Obstacle, Car, Finish}; //Un 0 es un espacio, un 1 es el camino, un 2 es obstáculo, un 3 la posición inicial del coche, un 4 la meta.
typedef std::vector<std::vector<state>> MatrixState;


class Board {

    bool Valid;
    int M_; //Alto
    int N_; //Ancho
    bool Car_, Finish_;
    MatrixState MatrixBoard_; 

public:

    Board(); //Constructor por defecto
    Board(int,int); //Pasando M y N
    Board(std::string); //Abrir de fichero
    ~Board();
    
    int GetM() const;
    int GetN() const;
    bool GetCar() const;
    bool GetFinish() const;
    void SetCar(bool);
    void SetFinish(bool);
    state GetState(int,int) const;
    void ChangeState(int,int,state);
    void CheckMap();
    void ShuffleMap(int);
    void ClearMap();

    void Write(std::ostream &os, writemode) const;
};


#endif //BOARD_HPP