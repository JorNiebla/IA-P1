/// Clase Board
///
/// @brief clase considerada "cerebro del coche autonomo". Aqui es donde 
/// se desarolla el algoritmo de busqueda A* y las funciones heuristicas
/// Euclidea y Manhattan
///
/// @date 15 Nov 2020
/// 
/// Autores: 
/// Jorge Niebla Núñez <alu0101215457@ull.edu.es>
/// Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// Jaime Pablo Pérez Moro <alu0101278919@ull.edu.es>

#include "board.hpp"
#include <ctime>
#include <chrono>

struct cell;

typedef std::pair<int, int> Pair;
typedef std::pair<double, Pair> pPair;
typedef std::vector<std::vector<cell> > matrixCell;
typedef std::chrono::duration<double> time_taken;

enum hMethod {Manhattan, Euclidean};
enum direction_t {N, E, S, W};

// define vectores de desplazamiento en las 4 direcciones
//                    N   E  S   W
const short i_d[] = { -1, 0, 1,  0};
const short j_d[] = {  0, 1, 0, -1}; 

struct cell {
  int parent_i, parent_j;
  double f, g, h;
};



class GPS {
    Pair start_;
    Pair end_;
    Board map_;

    //int SensorN;
    //int SensorE;
    //int SensorS;
    //int SensorW;

public:

    GPS(const Board&);
    ~GPS();

    Pair get_start();
    Pair get_end();
    Board get_map();

    void set_start(Pair);
    void set_end(Pair);
    void set_board(Board);

    bool isValid(int row, int col); 
    bool isUnBlocked(int, int);
    double CalculateHManhattan(int, int);
    double CalculateHEuclidean(int, int);
    int tracePath(matrixCell&);
    bool AStarSearch(hMethod);

};