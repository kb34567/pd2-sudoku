#include "Sudoku.h"
#include <iostream>

using namespace std;



//挖洞弄出題目
void Sudoku::GiveQuestion()
{
int init_map [144]=
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
    
 for (int i=0;i<144;i++) //建立0到144的數字序列
    {
        num[i] = i;
    }
    
 for (int i=0;i<12;i++)//將輸入的數獨題目寫入
     {
        for (int j=0;j<12;j++)
            in_map[i][j] = init_map[i*12+j];
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
 for (int i=0;i<35;i++) //製造35個洞
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
bool Sudoku::isCorrect(int n,int key)  //看key入的數有沒有跟題目give_you有的數一樣
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


/*

void Sudoku::readin() //讀入題目
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




*/
/////////////////////////////////
void Sudoku::ReadIn() //讀入題目
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            give_you[i][j] = dig[i][j]; //give_you是複製ques
        }
    }
}
/////////////////////////////////






bool sign=false;

//解出題目

int Sudoku::Solve(int n)
{
        if (n > 143) //都符合則停止
        {
            for (int i=0;i<12;i++) //印出answer
            {
                for(int j=0;j<12;j++)
                {
                    cout<<give_you[i][j]<<" ";
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
            
            return 0;
        }
       
        if (give_you[n/12][n%12] != 0) //不等於零就跳到下一個
        {
            Solve(n+1);
        }
        else //等於零則代數字測試
        {
            for (int i=1; i<=9; i++)
            {
                if ( Sudoku::isCorrect(n, i) == true) //數字重複就換下一個數字
                {
                    give_you[n/12][n%12] = i; //現在這個位置的數＝i
                    Solve(n+1); //填完後下個空格繼續填
                    if (sign == true) return 0; //符合則停止
                    give_you[n/12][n%12] = 0; //不成功就再一次
                }
            }
        }
    return 0;
}






