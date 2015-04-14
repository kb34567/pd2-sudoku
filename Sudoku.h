#include <iostream>

class Sudoku {
    public:
    
     Sudoku(const int init_map[144]);
     bool isCorrect(int n,int key);
     void GiveQuestion();
     static int Ans;
     void ReadIn();
     int Solve(int n);

    
    private:
     int in_map[12][12];
     int num[144];
     int dig[12][12];
     int copy[12][12];
     int ques[12][12];
     int give_you[12][12];
    
     
        };


