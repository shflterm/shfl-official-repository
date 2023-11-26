//
// Created by 08sih on 2023-11-11.
//

#ifndef APPMGR_H
#define APPMGR_H

#include "commandmgr.h"
#include "utils.h"

#include <vector>
#include <string>

class App {
protected:
    App(const App&new_parent, const string&name);

    string name, description, author;
    string version;
    int apiVersion = -1;

public:
    explicit App(const string&name);

    void loadVersion1(const string&appPath, Json::Value appRoot);

    [[nodiscard]] string getName() const {
        return name;
    }

    [[nodiscard]] string getDescription() const {
        return description;
    }

    [[nodiscard]] string getAuthor() const {
        return author;
    }

    [[nodiscard]] string getVersion() const {
        return version;
    }

    [[nodiscard]] int getApiVersion() const {
        return apiVersion;
    }
};

void loadApp(const string&name);

bool addApp(const string&name);

void unloadAllApps();

vector<string> getApps();

#endif //APPMGR_H
