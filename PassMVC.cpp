#include "PassMVC.h"

PasswordManager::PasswordManager(const std::string& file) : filename(file) {
    loadCredentials();
}

void PasswordManager::addCredential(const std::string& platform, const std::string& nameOrURL, const std::string& uname, const std::string& pass) {
    credentials.push_back(std::make_unique<Credential>(platform, nameOrURL, uname, pass));
    saveCredentials();
}

void PasswordManager::modifyCredential(const std::string& platform, const std::string& nameOrURL, const std::string& newUname, const std::string& newPass) {
    for (auto& cred : credentials) {
        if (cred->platform == platform && cred->nameOrURL == nameOrURL) {
            cred->username = newUname;
            cred->password = newPass;
            saveCredentials();
            return;
        }
    }
}

void PasswordManager::deleteCredential(const std::string& platform, const std::string& nameOrURL) {
    for (auto it = credentials.begin(); it != credentials.end(); ++it) {
        if ((*it)->platform == platform && (*it)->nameOrURL == nameOrURL) {
            credentials.erase(it);
            saveCredentials();
            return;
        }
    }
}

void PasswordManager::loadCredentials() {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string platform, nameOrURL, uname, pass;
    while (file >> platform >> nameOrURL >> uname >> pass) {
        credentials.push_back(std::make_unique<Credential>(platform, nameOrURL, uname, pass));
    }
    file.close();
}

void PasswordManager::saveCredentials() {
    std::ofstream file(filename, std::ios::trunc);
    if (!file.is_open()) return;

    for (const auto& cred : credentials) {
        file << cred->platform << " " << cred->nameOrURL << " " << cred->username << " " << cred->password << "\n";
    }
    file.close();
}

std::vector<Credential*> PasswordManager::getAllCredentials() const {
    std::vector<Credential*> credentialPtrs;
    for (const auto& cred : credentials) {
        credentialPtrs.push_back(cred.get());  // Get raw pointer from unique_ptr
    }
    return credentialPtrs;
}
