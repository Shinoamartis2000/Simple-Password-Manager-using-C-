#include "Controller.h"

Controller::Controller(PasswordManager* model, View* view) : model(model), view(view) {}

void Controller::run() {
    int choice;
    do {
        view->displayMenu();
        std::cin >> choice;
        std::cin.ignore(); // To ignore any leftover newline characters

        switch (choice) {
        case 1: handleAddCredential(); break;
        case 2: handleModifyCredential(); break;
        case 3: handleDeleteCredential(); break;
        case 4: handleDisplayCredentials(); break;
        case 5: view->displayMessage("Exiting Password Manager..."); break;
        default: view->displayMessage("Invalid option. Please try again."); break;
        }
    } while (choice != 5);
}

void Controller::handleAddCredential() {
    std::string platform, nameOrURL, username, password;
    view->promptForCredentials(platform, nameOrURL, username, password);
    model->addCredential(platform, nameOrURL, username, password);
    view->displayMessage("Credential added successfully.");
}

void Controller::handleModifyCredential() {
    std::string platform, nameOrURL, username, password;
    view->promptForModification(platform, nameOrURL, username, password);
    model->modifyCredential(platform, nameOrURL, username, password);
    view->displayMessage("Credential modified successfully.");
}

void Controller::handleDeleteCredential() {
    std::string platform, nameOrURL;
    view->displayMessage("Enter Platform (Website, Application, Game): ");
    std::getline(std::cin, platform);
    view->displayMessage("Enter site/app/game name or URL: ");
    std::cout << "Choose site/app/game name or URL: ";
    std::getline(std::cin, nameOrURL);
    model->deleteCredential(platform, nameOrURL);
    view->displayMessage("Credential deleted successfully.");
}

void Controller::handleDisplayCredentials() {
    auto credentials = model->getAllCredentials();
    view->displayAllCredentials(credentials);
}
