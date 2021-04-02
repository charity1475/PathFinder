#include <iostream>
#include <vector>
#include <fstream>
#include "sstream"

enum class State {
    kEmpty,
    kObstacle
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
int main() {
    auto board = ReadBoardFile("/home/charity/CLionProjects/Grids/grids.txt");
    std::cout << "From grids file"<<std::endl;
    printBoard(board);
    return 0;
}
