#include <iostream>
#include <vector>
#include <fstream>
#include "sstream"

enum class State {
    kEmpty,
    kObstacle,
    kClosed
};
std::string CellString(State state){
    switch(state){
        case State::kObstacle: return "⛰️ ";
        default: return "0 ";
    }
}
std::vector<State> ParseLine(std::string line){
    std::vector<State> myVector;
    std::istringstream myStream(line);
    int n;
    char c;
    while (myStream >> n >> c && c == ',') {
        if (n == 0) {
            myVector.push_back(State::kEmpty);
        } else {
            myVector.push_back(State::kObstacle);
        }
    }
    return myVector;
}
void printBoard(std::vector<std::vector<State>> board) {
    for(int i = 0; i < board.size();++i){
        for(int j = 0; j < board[i].size();++j){
            std::cout <<CellString(board[i][j]);
        }
        std::cout <<std::endl;
    }
}

std::vector<std::vector<State>> ReadBoardFile(std::string path){
    std::vector<std::vector<State>> board;
    std::vector<State>inputVector;
    std::ifstream myReadFile(path);
    std::string line;
    if(myReadFile.is_open()){
        while(getline(myReadFile, line)){
            std::cout << line<<std::endl;
            // on each line call parse line to get a vector
            inputVector = ParseLine(line);
            // return a vector of vector
            board.push_back(inputVector);
        }
        myReadFile.close();
    } else std::cout << "Could not open the file"<<std::endl;
    return board;
}
std::vector<std::vector<State>> Search(int start[],int goal[]){
    std::vector<std::vector<State>> board;
    std::cout <<"No path Found"<<std::endl;
    return board;
}
int heuristic(int x1,int y1,int x2,int y2){
    return abs(x2-x1) + abs(y2-y1);
}
void addToOpen(int x,int y,int g,int h,std::vector<std::vector<int>> &open,std::vector<std::vector<State>> &grid){
    std::vector<int> node ={x,y,g,h};
    open.push_back(node);
    //Set the grid value for the x and y coordinates to the enum value kClosed. We have added kClosed to the set of enum values.
    grid[x].push_back(State::kClosed);
    grid[y].push_back(State::kClosed);

}
int main() {
    auto board = ReadBoardFile("/home/charity/CLionProjects/Grids/resources/grids.txt");
    std::cout << "From grids file"<<std::endl;
    printBoard(board);
    int start[2] ={0,0};
    int goal[2] ={4,5};
    std::vector<std::vector<State>> solution = Search(start,goal);
    printBoard(solution);
    int number = heuristic(3,5,2,3);
    std::cout <<number<<std::endl;
    return 0;
}
