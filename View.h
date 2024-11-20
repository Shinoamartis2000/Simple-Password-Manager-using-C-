#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <vector>
#include <iomanip>
#include "PassMVC.h"

class View {
public:
    void displayMenu();
    void displayAllCredentials(const std::vector<Credential*>& credentials);
    void promptForCredentials(std::string& platform, std::string& nameOrURL, std::string& username, std::string& password);
    void promptForModification(std::string& platform, std::string& nameOrURL, std::string& username, std::string& password);
    void displayMessage(const std::string& message);
};

#endif // VIEW_H
