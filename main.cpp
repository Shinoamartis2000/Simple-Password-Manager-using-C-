#include "PassMVC.h"
#include "View.h"
#include "Controller.h"

int main() {
    // User login
    std::string username;
    std::string password;
    std::cout << "+-----+----------------+--------------------+--------------------+\n";
    std::cout << "                         WELCOME TO PASSMGMT \n";
    std::cout << "+-----+----------------+--------------------+--------------------+\n";
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;

    // Create a User object and PasswordManager object tied to user's data
    User user(username, password);
    PasswordManager pm(username + "_data.csv");  // Create PasswordManager using username-based file

    PasswordManager* model = new PasswordManager(username + "_data.csv");
    View* view = new View();
    Controller* controller = new Controller(model, view);

    controller->run();

    delete model;

    delete view;
    delete controller;

    return 0;
}

