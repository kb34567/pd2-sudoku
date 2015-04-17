#include <iostream>
#include <cstdlib>
#include<ctime>
#include<math.h>

using namespace std;

class Sudoku {
public:
    Sudoku();
    int init_map[144];
    bool isCorrect1(int n,int key);
    bool isCorrect2(int n,int key);
    void GiveQuestion2();
    void ReadIn();
    int Solve1(int n);
    int Solve2(int n);
    void printans();
    bool empty ();
    int give_you[12][12];
    void newques();
    int change[144];
    void Solve();
    void GiveQuestion();
    void copy_me();
    bool compare();
    
private:
    int in_map[12][12];
    int num[144];
    int dig[12][12];
    int copy[12][12];
    int ques[12][12];
    int give_you2[12][12];
    bool sign;
    bool sign2;
    int c;
    int sum;
    
};






