#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>

using namespace std;
enum levelGame{easy=1, med =2 , hard =3};

int RandomNumber(int From ,int To){
    return rand() % (To - From + 1) + From;
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
    switch ((levelGame)numberChoise)
    {
    case levelGame::hard:
        return RandomNumber(1,100);
    case levelGame::med:
        return RandomNumber(1,50);
    case levelGame::easy:
    default:
        return RandomNumber(1,25);
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
    cout<<"Select Difficulty Level: \n";
    cout<<"[1]: Easy (1-25)\n[2]: Medium (1-50)\n[3]: Hard (1-100)\n";
    int n =CheckNumber(1,3);
    int randomNumber = InputLevelGame(n);
    int GusessingNumber;
    bool won = false;

    while(!won){
        count++;
        GusessingNumber = ReadNumber("Enter your guess: ");
        if(CheckWin(randomNumber,GusessingNumber)){
            cout << "Good Job! You won in " << count << " attempts." << endl;
            won = true;
        }
        else{
            cout<<Up_Down(randomNumber,GusessingNumber);
            cout<<"Try again!\n";
        } 
    }
}


int main(){
    srand((unsigned)time(NULL));
    Game();
}