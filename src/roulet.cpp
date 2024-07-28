#include "roulet.h"

Roulette::Roulette(int N){
    this->N = N;
    RegisterMenu();
}
Roulette::~Roulette(){
    
}

//register and login
void Roulette::RegisterMenu(){
    int auth;
    while(true){
        clearSystem();
        std::cout << printColor("=========================================", 37) << std::endl;
        std::cout << setw(35) << right << printColor("ROULETTE", 36) << std::endl;
        std::cout << printColor("=========================================", 37) << std::endl;
        std::cout << endl;
        std::cout << printColor("[1] REGISTER", 32) << std::endl;
        std::cout << printColor("[2] LOGIN", 32) << std::endl;
        std::cout << printColor("[3] FORGOT PASSWORD", 36) << std::endl;
        std::cout << printColor("[4] INSTRUCTIONS", 33) << std::endl;
        std::cout << printColor("[5] EXIT", 31) << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        char select = getch();
        if (!(select < '1' || select > '5'))
        {
            auth = select;
            break;
        }
    }
    regis_log(auth);
}
void Roulette::regis_log(char auth){
    switch(auth){
        case '1':
            registation();
            break;
        case '2':
            login();
            break;
        case '3':
            forgot();
            break;
        case '4':
            Rules("main");
            break;
        case '5':
            exit(0);
    }
}
void Roulette::registation(){
    std::string ruserId, rpassword, rid, rpass;
    system("cls");
    std::cout << "\t\t\t Enter the username : ";
    std::cin >> ruserId;
    std::cout << "\t\t\t Enter the password : ";
    std::cin >> rpassword;

    ofstream f1("data.txt", ios::app);
    f1 << ruserId << " " << rpassword << std::endl;
    system("cls");
    std::cout << "\n\t\t\t Registrationis succesfull! \n";
    Menu();
}
void Roulette::login(){
    int count;
    string userId, password, id, pass;
    system("cls");
    std::cout << "\t\t\t Please enter the username and password : " << std::endl;
    std::cout << "\t\t\t USERNAME ";
    std::cin >> userId;
    std::cout << "\t\t\t PASSWORD ";
    std::cin >> password;

    ifstream input("data.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1)
    {
        std::cout << userId << "\n Your LOGIN is successfull /n Thanks for logging in ! \n";
        Menu();
    }
    else
    {
        std::cout << "\n LOGIN ERROR \n Please check your username and password\n";
        login();
    } 
}
void Roulette::forgot(){
    int option;
    system("cls");
    cout << "\t\t\t You forgot the password? No Worries \n";
    cout << "Press 1 to search your id by username " << std::endl;
    cout << "press 2 to go to the main menu " << std::endl;
    cout << "\t\t\t Enter your choice :";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        std::string suserId, sId, spass;
        std::cout << "\n\t\t\t Enter the username which you remembered :";
        std::cin >> suserId;

        ifstream f2("data.txt");
        while (f2 >> sId >> spass)
        {
            if (sId == suserId)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            std::cout << "\n\n Your account is found \n";
            std::cout << "\n\n Your password is :" << spass;
        }
        else
        {
            std::cout << "\n\t Sorry! your account is not found! \n";
        }

        break;
    }
    case 2:
    {
        RegisterMenu();
    }
    default:
        std::cout << "\t\t\t Wrong choice ! Please try again " << std::endl;
        forgot();
    }
}
void Roulette::Rules(std::string located){
    std::cout<<"\nThe roulette have 4 options for you to make a bet";
    std::cout<<"\n\t*you can bet by the NUMBERS";
    std::cout<<"\n\t*you can bet by the EVEN/ODD";
    std::cout<<"\n\t*you can bet by the color RED/BLACK";
    std::cout<<"\n\t*or you can even bet with MIX OPTION";
    std::cout<<"\nThe more option when you make a bet , the more money you will earn";
    std::cout<<"\nThe minimum for the bet is 20$ , and the maximum is 100000$";
    std::cout<<"\n";
    std::cout<<"\nGood luck !";

    getch();
    // GO TO MAIN MENU
    if (located == "main")
    {
        RegisterMenu();
    }
}

//main menu
void Roulette::Menu(){
    ListPlayer *listPlayer = new ListPlayer();
    this->list = listPlayer;
    int size;
    list->getLength() < 10 ? size = listPlayer->getLength() : size = 9;

    int choice;
    while (true)
    {
        clearSystem();
        std::cout << printColor("=========================================", 37) << std::endl;
        std::cout << setw(35) << right << printColor("ROULETTE", 36) << std::endl;
        std::cout << printColor("=========================================", 37) << std::endl;
        std::cout << endl;
        std::cout << printColor("[1] PLAY", 36) << std::endl;
        std::cout << printColor("[2] PROFILE", 33) << std::endl;
        std::cout << printColor("[3] EXIT", 31) << std::endl;
        std::cout << std::endl;
        char select = getch();
        if (!(select < '1' || select > '3'))
        {
            choice = select;
            break;
        }
    }
    gotoMenu(choice);
}
void Roulette::gotoMenu(char choice){
    switch(choice){
        case '1':
            mainGame();
            break;
        case '2':
            Rules("main");
            break;
        case '3':
            exitMenu();
            break;
    }
}
void Roulette::exitMenu(){
    clearSystem();
    std::cout << printColor("=========================================", 37) << endl;
    std::cout << setw(10) << right << "" << printColor("DO YOU WANT TO EXIT?", 31) << endl;
    std::cout << printColor("[1] YES", 32) << endl;
    std::cout << printColor("[2] NO", 33) << endl;
    std::cout << printColor("=========================================", 37) << endl;

    while (true)
    {
        char select = getch();
        if ((select == '1' || select == '2' || (int)select == 27))
        {
            std::cout << endl;
            if (select == '1')
            {
                RegisterMenu();
            }
            else
            {
                Menu();
            }
        }
    }
}

//save player data
void Roulette::saveInformation(){
        std::string name;
    double money;
    bool saved = false;

    printInformation(name, saved);

    while (true)
    {
        // ESC
        char key = getch();

        if (!saved)
        {
            if ((int)key == 27)
            {
                mainGame();
            }
            // Enter
            if ((int)key == 13)
            {
                if (name == "")
                {
                    name = "Robot";
                }

                Player player(name, money);

                list->AddPlayer(player);

                // IsSaved non call again
                saved = true;
                printInformation(name, saved);
            }
            // Input name
            if (((int)key == 8 || (int)key == 83) && name.size() > 0)
            {
                name.pop_back();
                printInformation(name, saved);
            }
            else
            {
                if (key >= 'a' && key <= 'z' || key >= 'A' && key <= 'Z')
                {
                    if (name.size() <= 10)
                    {
                        name.push_back(key);
                    }
                    printInformation(name, saved);
                }
            }
        }
        else
        {
            printInformation(name, saved);
            if (key == 27)
                break;
            }
        }
}
void Roulette::printInformation(string name, bool saved){
    double money;
    clearSystem();
    std::cout << printColor("=========================================", 37) << std::endl;
    std::cout << setw(12) << "" << printColor("SAVE INFORMATION", 36) << std::endl;
    std::cout << printColor("=========================================", 37) << std::endl;
    std::cout << std::endl;
    std::cout << setw(2) << ""
         << "Enter your name: " << name << "_";
    std::cout << std::endl;
    std::cout << setw(2) << ""
         << "Your Money: " << money;

    std::cout << std::endl;
    std::cout << std::endl;
    if (!saved)
    {
        std::cout << setw(2) << "" << printColor("Press [ENTER] to save", 36) << std::endl;
        std::cout << setw(2) << "" << printColor("Press [ESC] to back the game", 33) << std::endl;
    }
    else
    {
        std::cout << setw(2) << "" << printColor("SAVED", 32) << std::endl;
        std::cout << setw(2) << "" << printColor("Press [ESC] go to menu", 32) << std::endl;
    }
}

//start game
Roulette Roulette::mainGame(){
    int choice;
    while (true)
    {
        clearSystem();
        std::cout << printColor("=========================================", 37) << std::endl;
        std::cout << setw(35) << right << printColor("ROULETTE", 36) << std::endl;
        std::cout << printColor("=========================================", 37) << std::endl;
        std::cout << endl;
        std::cout << printColor("[1] PLAY", 36) << std::endl;
        std::cout << printColor("[2] PROFILE", 33) << std::endl;
        std::cout << printColor("[3] EXIT", 31) << std::endl;
        std::cout << std::endl;
        char select = getch();
        if (!(select < '1' || select > '3'))
        {
            choice = select;
            break;
        }
    }
    switch (choice)
    {
    case '1':
        Bet gametype();
        break;
    case '3':
        exitMenu();
        break;
    }

}