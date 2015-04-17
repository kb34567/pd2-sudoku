#include "Sudoku.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<math.h>
using namespace std;

Sudoku::Sudoku()
{
    int map[144]=
    {   -1,-1,-1,1,5,7,2,9,6,3,4,8,
        -1,-1,-1,4,8,9,1,7,3,2,5,6,
        -1,-1,-1,2,3,6,4,8,5,1,9,7,
        2,7,8,-1,-1,-1,3,6,4,5,1,9,
        6,3,9,-1,-1,-1,5,1,7,4,8,2,
        1,4,5,-1,-1,-1,9,2,8,7,6,3,
        3,1,7,5,9,8,-1,-1,-1,6,2,4,
        8,5,4,6,7,2,-1,-1,-1,9,3,1,
        9,2,6,3,4,1,-1,-1,-1,8,7,5,
        4,6,1,7,2,3,8,5,9,-1,-1,-1,
        5,9,2,8,6,4,7,3,1,-1,-1,-1,
        7,8,3,9,1,5,6,4,2,-1,-1,-1  };
    for(int i=0;i<144;i++)
    {
        init_map[i]=map[i];
    }
    sign=false;
    sign2=false;
    c=0;
    sum=0;
}


void Sudoku::newques() //經由將以輸入的數獨數字對調產生新數獨
{
    srand((unsigned)time(NULL));
    for(int i=0;i<144;i++)
    {
        change[i]= init_map[i];
    }
    
    
    for(int c=0;c<5;c++) //取5組數字對調
    {
        int j = rand()%9+1;
        int k =rand()%9+1;
        
        int put=100;
        for(int i=0;i<144;i++)
        {
            if( change[i]==j)
                change[i]=put;
            
            if (change[i]==k)
                change[i]=j;
            
            if ( change[i]==put)
                change[i]=k;
        }
    }
}

///////////////////////////////////////////////////////////

//挖洞弄出題目
void Sudoku::GiveQuestion2()
{
    
    for (int i=0;i<144;i++) //建立0到144的數字序列
    {
        num[i] = i;
    }
    
    for (int i=0;i<12;i++)//將輸入的數獨題目寫入
    {
        for (int j=0;j<12;j++)
            in_map[i][j] =  change[i*12+j];
    }
    
    for (int i=0;i<12;i++)//將輸入的數獨題目寫入
    {
        for (int j=0;j<12;j++)
            dig[i][j] = in_map[i][j];
    }
    
    
    int temp; //置換用暫存變數
    for (int i=0;i<144;i++) //將數字序列打亂
    {
        int j = rand()%144;
        temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }
    for (int i=0;i<45;i++) //製造45個洞
    {  if(dig[num[i]/12][num[i]%12] !=-1)
        dig[num[i]/12][num[i]%12] = 0;
    }
    
    
    
    for (int i=0;i<12;i++) //印出題目
    {
        for(int j=0;j<12;j++)
        {
            cout<<dig[i][j]<<" ";//dig是做好有洞洞的題目了
            if (j % 3 == 2)
            {
                cout << "   ";
            }
        }
        cout << endl;
        if (i % 3 == 2)
        {
            cout << endl;
        }
    }
}


///////////////////////////////////////////////////////////


//判斷是不是正確
bool Sudoku::isCorrect1(int n,int key)  //看key入的數有沒有跟題目give_you有的數一樣
{
    //橫向的
    
    for (int i=0; i<12; i++)
    {
        int j=n/12;  //n所在的橫排
        if (give_you[j][i] == key) return false;
    }
    
    
    //縱向的
    
    for (int i=0; i<12; i++)
    {
        int j=n%12;  //n所在的直排
        if (give_you[i][j] == key) return false;
    }
    
    //格子
    
    int x = n/12/3*3;  //九宮格左頂點x座標
    int y = n%12/3*3;  //九宮格左頂點y座標
    
    for (int i=x; i<x+3; i++)
    {
        for (int j=y; j<y+3; j++)
        {
            if (give_you[i][j] == key) return false;
        }
    }
    
    //全對
    
    return true;
}


///////////////////////////////////////////////////////////


//判斷是不是正確
bool Sudoku::isCorrect2(int n,int key)  //看key入的數有沒有跟題目give_you有的數一樣
{
    //橫向的
    
    for (int i=0; i<12; i++)
    {
        int j=n/12;  //n所在的橫排
        if (give_you2[j][i] == key) return false;
    }
    
    
    //縱向的
    
    for (int i=0; i<12; i++)
    {
        int j=n%12;  //n所在的直排
        if (give_you2[i][j] == key) return false;
    }
    
    //格子
    
    int x = n/12/3*3;  //九宮格左頂點x座標
    int y = n%12/3*3;  //九宮格左頂點y座標
    
    for (int i=x; i<x+3; i++)
    {
        for (int j=y; j<y+3; j++)
        {
            if (give_you2[i][j] == key) return false;
        }
    }
    
    //全對
    
    return true;
}

///////////////////////////////////////////////////////////


void Sudoku::ReadIn() //讀入題目
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cin >> ques[i][j]; //ques[][]是要解的題目
            give_you[i][j] = ques[i][j]; //give_you是複製ques
            
        }
    }
}


///////////////////////////////////////////////////////////

void Sudoku::copy_me() //複製一個題目
{
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<12;j++)
        {
            give_you2[i][j]=give_you[i][j];
        }
    }

}

///////////////////////////////////////////////////////////


bool Sudoku::empty () //看是不是所有空格都填對了
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            sum=give_you[i][j]+sum;
        }
    }
    if(sum==504) return true; //有解
    else return false; //無解
}


///////////////////////////////////////////////////////////


int Sudoku::Solve1(int n) //解出題目
{
    if (n>143) //若空格都填完了則停止
    {
        sign = true;
        return 0;
    }
    
    if (give_you[n/12][n%12] != 0) //不等於零就跳到下一個
    {
        Sudoku::Solve1(n+1);
    }
    else //等於零則代數字測試
    {
        for (int i=1; i<=9; i++)
        {
            if ( Sudoku::isCorrect1(n, i) == true) //數字重複就換下一個數字
            {
                give_you[n/12][n%12] = i; //現在這個位置的數＝i
                Sudoku::Solve1(n+1); //填完後下個空格繼續填
                if (sign == true) return 0; //符合則停止
                give_you[n/12][n%12] = 0; //不成功就回去再一次
            }
        }
    }
    return 0;
}

///////////////////////////////////////////////////////////
int Sudoku::Solve2(int n)
{
    if (n<0) //若空格都填完了則停止
    {
        sign2 = true;
        return 0;
    }
    
    if (give_you2[n/12][n%12] != 0) //不等於零就跳到下一個
    {
        Sudoku::Solve2(n-1);
    }
    else //等於零則代數字測試
    {
        for (int i=9; i>=0; i--)
        {
            if ( Sudoku::isCorrect2(n, i) == true) //數字重複就換下一個數字
            {
                give_you2[n/12][n%12] = i; //現在這個位置的數＝i
                Sudoku::Solve2(n-1); //填完後下個空格繼續填
                if (sign2 == true) return 0; //符合則停止
                give_you2[n/12][n%12] = 0; //不成功就回去再一次
            }
        }
    }
    return 0;
}

///////////////////////////////////////////////////////////

void Sudoku::printans()//印出answer

{
    if(Sudoku::empty())     //有唯一解或無限多解
    {
        if(Sudoku::compare()) //一組解
        {
            cout << 1 << endl;
            for (int i=0;i<12;i++)
            {
                for(int j=0;j<12;j++)
                {
                    cout<<give_you[i][j]<<" ";
                    if (j % 3 == 2)
                    {cout << "   ";}
                }
                cout << endl;
                if (i % 3 == 2)
                {cout << endl;}
            }
        }
        else cout << 2 << endl; //好多組解
    }
    else cout << 0 << endl; //無解
}

///////////////////////////////////////////////////////////

bool Sudoku::compare()
{
    int a=0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
       //     cout << give_you[i][j] << give_you2[i][j] <<endl;
             a= abs(give_you2[i][j]-give_you[i][j]);
             c=a+c;
                        
        }
    }
    if(c==0)return true; //剛好一組解
    else return false; //多組解
}


///////////////////////////////////////////////////////////

void Sudoku::Solve()
{
    Sudoku::copy_me(); //先複製一個一樣的題目
    Sudoku::Solve1(0); //解give_you
    Sudoku::Solve2(143); //解give_you2
 //   Sudoku::empty(); //看是否為無解
 //   Sudoku::compare(); //看他們兩個有沒有一樣
    Sudoku::printans(); //印出答案
    
}

///////////////////////////////////////////////////////////

void Sudoku::GiveQuestion()
{
    Sudoku::newques();
    Sudoku::GiveQuestion2();
}


///////////////////////////////////////////////////////////


