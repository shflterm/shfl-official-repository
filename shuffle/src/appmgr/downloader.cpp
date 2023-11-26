#include "downloader.h"

#include <string>
#include <json/json.h>
#include <filesystem>

#include "console.h"
#include "utils.h"
#include "appmgr.h"
#include "term.h"

using std::to_string, std::filesystem::path, std::filesystem::temp_directory_path, std::filesystem::exists,
        std::filesystem::remove_all, std::filesystem::copy_options;

Json::Value getRepo(const string&repo) {
    Json::Value root;
    Json::Reader reader;
    reader.parse(readTextFromWeb(repo), root, false);

    return root;
}

vector<string> getRepos() {
    vector<string> result;
    Json::Value repos = getShflJson("repos");
    for (const auto&repo: repos) result.push_back(repo.asString());
    return result;
}

bool installApp(string&name) {
    bool installed = false;

    const path localApp = currentWorkspace->currentDirectory() / name;
    if (const path appShfl = localApp / "app.shfl";
        exists(localApp) && exists(appShfl)) {
        name = path(name).filename().string();
        info("Start downloading '" + name + "' from '" + absolute(localApp).parent_path().string() +
             "'...");
        const path targetPath = DOT_SHUFFLE / "apps" / (name + ".shflapp");
        copy(absolute(localApp), absolute(targetPath), copy_options::overwrite_existing | copy_options::recursive);
        success("Load Completed!");
        installed = true;
    }
    else {
        const string downloadTo = temp_directory_path().append("app.shflapp").string();

        info("Downloading Repository information...");
        for (const auto&repoUrl: getRepos()) {
            Json::Value repo = getRepo(repoUrl);

            term << teleport(0, wherey() - 1) << eraseLine;
            string message = R"(Start downloading '{APP}' from '{REPO}'...)";
            message = replace(message, "{APP}", name);
            message = replace(message, "{REPO}", repo["repo"].asString());
            info(message);

            if (const int ver = repo["version"].asInt(); ver == 1) {
                if (const string downloadFrom = replace(repo["download_at"].asString(), "{APP}", name); downloadFile(
                    downloadFrom, downloadTo)) {
                    term << teleport(0, wherey() - 1) << eraseLine;
                    success("Download Completed!");

                    term << teleport(0, wherey() - 1) << eraseLine;
                    extractZip(downloadTo, DOT_SHUFFLE / "apps" / (name + ".shflapp"));
                    term << teleport(0, wherey()) << eraseLine;
                    success("Extracted!");
                    installed = true;
                    break;
                }
            }
            else {
                term << teleport(0, wherey() - 1) << eraseLine;
                warning("Unknown repository version: " + to_string(ver));
            }
        }
    }

    if (!installed) {
        term << teleport(0, wherey() - 1) << eraseLine;
        error("The app could not be found in the repository.");
        return false;
    }

    term << teleport(0, wherey() - 1) << eraseLine;
    info("Adding to config...");

    if (!addApp(name)) {
        term << teleport(0, wherey() - 1) << eraseLine;
        error("Failed to add app. (The app has already been added.)");
        return false;
    }
    else {
        term << teleport(0, wherey() - 1) << eraseLine;
        success("Done!");
        return true;
    }
}

bool removeApp(const string&name) {
    info("Deleting '" + name + "'...");

    if (const path appPath = DOT_SHUFFLE / "apps" / (name + ".shflapp"); exists(appPath)) {
        remove_all(appPath);

        Json::Value json = getShflJson("apps");
        for (int i = 0; i < json.size(); ++i) {
            if (json[i]["name"] == name) {
                json.removeIndex(i, &json[i]);
            }
        }
        setShflJson("apps", json);

        success("Done!");
        return true;
    }
    error("App not found!");
    return false;
}


bool addRepo(const string&url) {
    Json::Value repos = getShflJson("repos");
    repos.append(url);
    setShflJson("repos", repos);
    info("Repository " + url + " added!");
    return true;
}


bool removeRepo(const string&url) {
    Json::Value repos = getShflJson("repos");
    repos.removeMember(url);
    setShflJson("repos", repos);
    info("Repository " + url + " removed!");
    return true;
}
