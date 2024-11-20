#ifndef PASSMVC_H
#define PASSMVC_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

class User {
private:
    std::string username;
    std::string password;

public:
    User(std::string user, std::string pass) : username(user), password(pass){}

   };

class Credential {
public:
    std::string platform;
    std::string nameOrURL;
    std::string username;
    std::string password;

    Credential(const std::string& plat, const std::string& nameOrURL, const std::string& uname, const std::string& pass)
        : platform(plat), nameOrURL(nameOrURL), username(uname), password(pass) {}
};

class PasswordManager {
private:
    std::string filename;
    std::vector<std::unique_ptr<Credential>> credentials;  // Stores pointers to Credential objects

public:
    PasswordManager(const std::string& file);
    void addCredential(const std::string& platform, const std::string& nameOrURL, const std::string& uname, const std::string& pass);
    void modifyCredential(const std::string& platform, const std::string& nameOrURL, const std::string& newUname, const std::string& newPass);
    void deleteCredential(const std::string& platform, const std::string& nameOrURL);
    void loadCredentials();
    void saveCredentials();
   std::vector<Credential*> getAllCredentials() const;  // Returns a list of raw pointers to Credential
};

#endif // PASSMVC_H
