#include <iostream>
#include <limits>
#include <ctime>
using namespace std;
enum levelGame{easy=1, med =2 , hard =3};



int RandomNumber(int From ,int To){
    int number = rand()%(From-To+1)+From;
    return number;
}

int ReadNumber(string message){
    cout<<message;
    int number;
    cin>>number;
    while (cin.fail()){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Invalid Number, Enter a valid one:" << endl;
        cin>>number;  
    }

    return number; 
}

int CheckNumber(int min , int max){
    int number;
    do{
        number = ReadNumber("enter number: ");
        if(number>max||number<min)
            cout<<"plase enter number between "<<min<<","<<max<<endl;
    }while(number>max||number<min);
    return number;
}

bool CheckWin(int userNumber, int randomNumber){
    return userNumber==randomNumber;
}

int InputLevelGame(int numberChoise){
    numberChoise = (levelGame)numberChoise;
    switch (numberChoise)
    {
    case levelGame::hard:
        return RandomNumber(1,100);
    case levelGame::med:
        return RandomNumber(1,50);
    case levelGame::easy:
        return RandomNumber(1,25);
    default:
        return -100;
        break;

    }
}

string Up_Down(int randomNumber, int userNumber){
    if(randomNumber>userNumber){
        return "The Number is UP\n";
    }
    else{
        return "The number is Down\n";
    }
}

void Game(){
    int count = 0;
    cout<<"enter Level Game: \n";
    cout<<"[1]: easy(1,25)\n [2]: med(1,50)\n [3]: hard(1,100)";
    int n =CheckNumber(1,3);
    int randomNumber = InputLevelGame(n);
    int GusessingNumber;
    do{
        count++;
        GusessingNumber = ReadNumber("enter Guessing Number: ");
        if(CheckWin(randomNumber,GusessingNumber)){
            cout<<"Good Job you win"<<endl;
            cout<<"and s is "<<count<<endl;
            break;
        }
        else{

            cout<<Up_Down(randomNumber,GusessingNumber);
            cout<<"Enter Again!\n";
        } 
    }while(1);
}


int main(){
    Game();
}