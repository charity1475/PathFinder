#include <iostream>
#include <vector>
#include <fstream>
#include "sstream"
#include<algorithm>

enum class State {
    kEmpty,
    kObstacle,
    kClosed,
    kPath
};
// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
std::string CellString(State state){
    switch(state){
        case State::kObstacle: return "⛰️ ";
        case State::kPath: return "🚗   ";
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
int Heuristic(int x1,int y1,int x2,int y2){
    return abs(x2-x1) + abs(y2-y1);
}
void AddToOpen(int x,int y,int g,int h,std::vector<std::vector<int>> &openList,std::vector<std::vector<State>> &grid){
    std::vector<int> node ={x,y,g,h};
    openList.push_back(node);
    //Set the grid value for the x and y coordinates to the enum value kClosed. We have added kClosed to the set of enum values.
    grid[x][y] = State::kClosed;

}

bool CheckValidCell(int x,int y,std::vector<std::vector<State>> &grid){
    bool on_grid_x =(x>=0 && x<grid.size());
    bool on_grid_y =(y>=0 && y<grid[0].size());
    if(on_grid_x && on_grid_y){
        return grid[x][y] == State::kEmpty;
    }
    return false;
}
bool Compare(const std::vector<int> first,const std::vector<int> second){
    int f1=first[2]+first[3];
    int f2=second[2]+second[3];
    return f1<f2;
}
void CellSort(std::vector<std::vector<int>> *myVector){
    std::sort(myVector->begin(), myVector->end(),Compare);
}

void ExpandNeighbors(std::vector<int> currentNode, int goal[2],
                     std::vector<std::vector<int>>& openList,
                     std::vector<std::vector<State>>& grid){
    int currentX = currentNode[0];
    int currentY = currentNode[1];
    int g = currentNode[2];
    for(int i=0;i<4;++i){
        int nextX = currentX + delta[i][0];
        int nextY = currentY + delta[i][1];
        if (CheckValidCell(nextX,nextY,grid)){
            int h = Heuristic(nextX,nextY,goal[0],goal[1]);
            AddToOpen(nextX,nextY,g+1,h,openList,grid);
        }
    }

}
std::vector<std::vector<State>> Search(std::vector<std::vector<State>>grid,int init[2],int goal[2]){
    std::vector<std::vector<int>> open {};
    //initialize the starting node
    int x = init[0];
    int y = init[1];
    int g = 0;
    int h = Heuristic(x,y,goal[0],goal[1]);
    AddToOpen(x,y,g,h,open,grid);
    while(!open.empty()){
        // sort the open list and get current node
        CellSort(&open);
        std::vector<int> currentNode = open.back();
        open.pop_back();
        x = currentNode[0];
        y = currentNode[1];
        grid[x][y] = State::kPath;
        // check if i reached the goal
        if(x==goal[0] && y==goal[1]){
            return grid;
        }
        // else go to neighbors
        ExpandNeighbors(currentNode,goal,open,grid);

    }
    std::cout << "No path found." << std::endl;
    return std::vector<std::vector<State>> {};
}

int main() {
    auto board = ReadBoardFile("/home/charity/CLionProjects/Grids/resources/grids.txt");
    std::cout << "From grids file"<<std::endl;
    printBoard(board);
    int init[2] = {0, 0};
    int goal[2] = {4, 5};
    std::vector<std::vector<State>>solution = Search(board, init, goal);
    printBoard(solution);
    return 0;
}
