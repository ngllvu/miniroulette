#include "bet.h"

void Bet::gametype(){
    int choice1;
    switch (choice1){
        case '1':
            numbers();
            break;
        case '2':
            even_odd();
            break;
        case '3':
            color();
            break;
        case '4':
            mix();
            break;
        case '5':
            exit(0);
    }
}
void Bet::numbers(){
    int choice2;
    std::cout<<"which number would you like to bet on?";
    std::cin>>choice2;
    if(choice2 == 00){
        number = 37;
    }
    srand(time(NULL));
    random = rand() % (Max - Min + 1) + Min;
    std::cout<<"\nThe ball land on " << random << "\n" << std::endl;
    if(random != choice2){
        std::cout<<"\nYou LOSE !";
        std::cout<<"\nYou just lost " << bet <<"$" << std::endl;
        money -= bet;
    }
    else{
        std::cout<<"\nYou WIN !";
        std::cout<<"\nYou just won " << bet <<"$" << std::endl;
        money += bet;
    }

    cout << "Do you want to stop, yes[Y] or no[N]?";
    cin >> stop;
    if(stop == "Y"){
        gametype();
    }
    else if(stop == "N"){
        numbers();
    }
}

void Bet::even_odd(){
    char *choice3;
    std::cout<<"You choose EVEN or ODD ?";
    std::cin>>choice3;
    srand(time(NULL));
    random = rand() % (Max - Min + 1) + Min;
    std::cout<<"\nThe ball land on " << random << "\n" << std::endl;
    if(choice3 == "e" || choice3 == "E"){
        if(2*(random/2) == random){
            std::cout<<"\nYou WIN !";
            std::cout<<"\nYou just won " << bet << "$" << std::endl;
            money += bet;
        }
        else{
            std::cout<<"\nYou LOSE !";
            std::cout<<"\nYou just lost " << bet << "$" << std::endl;
            money -= bet;
        }
    }
    if(choice3 == "o" || choice3 == "O"){
        if(2*(random/2) == random){
            std::cout<<"\nYou LOSE !";
            std::cout<<"\nYou just lost " << bet << "$" << std::endl;
            money -= bet;
        }
        else{
            std::cout<<"\nYou WIN !";
            std::cout<<"\nYou just won " << bet << "$" << std::endl;
            money += bet;
        }
    }
    cout << "Do you want to stop, yes[Y] or no[N]?";
    cin >> stop;
    if(stop == "Y"){
        gametype();
    }
    else if(stop == "N"){
        even_odd();
    }
}

void Bet::color(){
    char *choice4;
    std::cin>>choice4;
    srand(time(NULL));
    random = rand() % (Max - Min + 1) + Min;
    std::cout<<"\nThe ball land on " << random << std::endl;
    if(choice4 == "b" || choice4 == "B"){
        if (random == 2 || random == 4 || random == 6 || random == 8 || random == 10 || random == 11 || random == 13 || random == 15 || random == 17 || random == 20 || random == 22 || random == 24 || random == 26 || random == 28 || random == 29 || random == 31 || random == 33 || random == 35){
            std::cout<<"\nYou WIN !";
            std::cout<<"\nYou just won " << bet << "$" << std::endl;
            money += bet;
        }
        else{
            std::cout<<"\nYou LOSE !";
            std::cout<<"\nYou just lost " << bet << "$" << std::endl;
            money -= bet;
        }
    }
    if(choice4 == "r" || choice4 == "R"){
        if (random == 2 || random == 4 || random == 6 || random == 8 || random == 10 || random == 11 || random == 13 || random == 15 || random == 17 || random == 20 || random == 22 || random == 24 || random == 26 || random == 28 || random == 29 || random == 31 || random == 33 || random == 35){
            std::cout<<"\nYou LOSE !";
            std::cout<<"\nYou just lost " << bet << "$" << std::endl;
            money -= bet;
        }
        else{
            std::cout<<"\nYou WIN !";
            std::cout<<"\nYou just won " << bet << "$" << std::endl;
            money += bet;
        }
    }
    cout << "Do you want to stop, yes[Y] or no[N]?";
    cin >> stop;
    if(stop == "Y"){
        gametype();
    }
    else if(stop == "N"){
        color();
    }
}

void Bet::mix(){

}

Bet::Bet(){
}
Bet::~Bet(){
}
Bet::Bet(int number, double money, double bet){
    this ->number = number;
    this ->money = money;
    this ->bet = bet;
}