#include <iostream>
#include <vector>
#include <fstream>
#include "sstream"

void stream(){
    std::istringstream myStream("1 2 3 4 5 6 7");
    int n ;
    while (myStream){
        myStream>>n;
        if (myStream){
            std::cout <<n<<"\n";
        }
    }
}
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

void printVector(std::vector<int> vector){
    for (std::size_t i = 0; i < vector.size(); i++){
        std::cout << vector[i] << std::endl;
    }
}
std::vector<std::vector<State>> ReadBoardFile(std::string path){
    std::vector<std::vector<State>> board;
    std::vector<State>inputVector;
    std::ifstream myReadFile(path);
    std::string line;
    if(myReadFile.is_open()){
        while(getline(myReadFile, line)){
            std::cout << line<<"\n";
            // on each line call parse line get a vector
            inputVector = ParseLine(line);
            // return a vector of vector
            board.push_back(inputVector);
        }
        myReadFile.close();
    } else std::cout << "Could not open file";
    return board;
}
int main() {
    std::vector<std::vector<State>> newBoard = ReadBoardFile("/home/charity/CLionProjects/starter/grids.txt");
    std::cout << "From stream file"<<"\n";
    printBoard(newBoard);
    return 0;
}
