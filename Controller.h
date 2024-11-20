#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "PassMVC.h"
#include "View.h"

class Controller {
private:
    PasswordManager* model;
    View* view;

public:
    Controller(PasswordManager* model, View* view);
    void run();
    void handleAddCredential();
    void handleModifyCredential();
    void handleDeleteCredential();
    void handleDisplayCredentials();
  
};

#endif // CONTROLLER_H
