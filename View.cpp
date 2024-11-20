#include "View.h"

void View::displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Add Credential\n";
    std::cout << "2. Modify Credential\n";
    std::cout << "3. Delete Credential\n";
    std::cout << "4. Display All Credentials\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

void View::displayAllCredentials(const std::vector<Credential*>& credentials) {
    std::cout << "+-----+----------------+--------------------+--------------------+--------------------+\n";
    std::cout << "| No. |    Platform    |       Name/URL     |      Username      |      Password      |\n";
    std::cout << "+-----+----------------+--------------------+--------------------+--------------------+\n";
    int index = 1;
    for (const auto& cred : credentials) {
        std::cout << "| " << std::setw(3) << index++
            << " | " << std::setw(14) << cred->platform
            << " | " << std::setw(18) << cred->nameOrURL
            << " | " << std::setw(18) << cred->username
            << " | " << std::setw(18) << cred->password << " |\n";
    }
    std::cout << "+-----+----------------+--------------------+--------------------+--------------------+\n";
}

void View::promptForCredentials(std::string& platform, std::string& nameOrURL, std::string& username, std::string& password) {
    std::cout << "Choose platform (Website, Application, Game): ";
    std::getline(std::cin, platform);
    std::cout << "Enter site/app/game name or URL: ";
    std::getline(std::cin, nameOrURL);
    std::cout << "Enter username: ";
    std::getline(std::cin, username);
    std::cout << "Enter password: ";
    std::getline(std::cin, password);
}

void View::promptForModification(std::string& platform, std::string& nameOrURL, std::string& username, std::string& password) {
    std::cout << "Choose platform (Website, Application, Game): ";
    std::getline(std::cin, platform);
    std::cout << "Enter site/app/game name or URL: ";
    std::getline(std::cin, nameOrURL);
    std::cout << "Enter new username: ";
    std::getline(std::cin, username);
    std::cout << "Enter new password: ";
    std::getline(std::cin, password);
}

void View::displayMessage(const std::string& message) {
    std::cout << message << std::endl;
}
