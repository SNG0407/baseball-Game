#include <iostream>
#include <cstring>
#include <time.h>
using namespace std;

int main()
{
    int balls[9] = {};
    int gotBall[3] = {};
    int strike, ball;

    srand((unsigned int)time(0));
    //get 3 random numbers from 1~9

    //creat 9 balls
    for (int i = 0; i < 9; i++) {
        balls[i] = i + 1;
    }
    //suffle
    int suffle, index1, index2;
    for (int i = 0; i < 100; i++) {
        index1 = rand() % 8;
        index2 = rand() & 8;
        suffle = balls[index1];
        balls[index1] = balls[index2];
        balls[index2] = suffle;
    }
    //Get three balls
    for (int i = 0; i < 3; i++) {
        gotBall[i] = balls[i];
        cout << gotBall[i] << " ";
    }

    strike = 0;  ball = 0;
    int guess[3] = {};
    while (true) {
        cout << "\n"<<"1~9까지 숫자 중 3가지를 고르시오 (0 : 게임 종료)" << endl;
        cin >> guess[0]>> guess[1] >> guess[2];
        cout << "입력한 숫자 : " << guess[0] << " ," << guess[1] << " ," << guess[2] << endl;
        //guess balls 이 1~9가 아닌 경우
        if (guess[0] == 0 || guess[1] == 0 || guess[2] == 0 ) { break; }
        for (int i = 0; i < 3; i++) {
            if (guess[i] < 0 || guess[i]>9) {
                cout << "잘못된 숫자를 입력 했습니다. " << endl;
                continue;
            }
            
        }
        if(guess[0]==guess[1] || guess[0] == guess[2] || guess[1] == guess[2]){
            cout << "중복된 숫자를 입력 했습니다. " << endl;
            continue;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (gotBall[i] == guess[j]) {
                    if (i == j) { strike++; }
                    else { ball++; }
                }
            }
        }

        if (strike == 3) {
            cout << "모든 숫자를 맞추었습니다." << endl;
                break;
        }else if (strike == 0 && ball == 0) {
            cout << "Out 입니다." << endl;
        }
        else {
            cout << strike <<"strike ," << ball << "ball" << endl;
            
        }
        strike = 0; ball = 0;
    }
    return 0;
}

