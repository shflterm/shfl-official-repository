//
// Created by winch on 5/5/2023.
//

#ifndef SHUFFLE_INCLUDE_COMMANDMGR_H_
#define SHUFFLE_INCLUDE_COMMANDMGR_H_

#include <vector>
#include <string>
#include <memory>
#include <functional>
#include <json/value.h>
#include <string>
#include <map>

class Command;

#include "workspace.h"

using std::pair, std::shared_ptr, std::string, std::vector, std::map;

typedef std::function<string(Workspace*, map<string, string>&)> cmd_t;

string do_nothing(Workspace* ws, map<string, string>&optionValues);

enum OptionType {
    TEXT_T,
    BOOL_T,
    INT_T,
};

class CommandOption {
public:
    string name, description;
    OptionType type;
    vector<string> aliases;

    CommandOption(string name, string description, OptionType type);

    CommandOption(string name, string description, OptionType type, const vector<string>&aliases);
};

class Command {
protected:
    string name;
    string description;
    string usage;
    vector<shared_ptr<Command>> subcommands;
    vector<CommandOption> options;
    vector<string> aliases;
    vector<string> examples;

    cmd_t cmd;

public:
    [[nodiscard]] const string& getName() const;

    [[nodiscard]] const string& getDescription() const;

    [[nodiscard]] const string& getUsage() const;

    [[nodiscard]] const vector<shared_ptr<Command>>& getSubcommands() const;

    [[nodiscard]] const vector<CommandOption>& getOptions() const;

    [[nodiscard]] const vector<string>& getAliases() const;

    [[nodiscard]] const vector<string>& getExamples() const;

    string run(Workspace* ws, map<string, string>&optionValues) const;

    [[nodiscard]] string createHint() const;

    Command(string name, string description, const vector<Command>&subcommands, const vector<CommandOption>&options,
            cmd_t cmd);

    Command(string name, string description, const vector<Command>&subcommands, cmd_t cmd);

    Command(string name, string description, const vector<CommandOption>&options, cmd_t cmd);

    Command(string name, string description, cmd_t cmd);

    explicit Command(string name);

    Command(Json::Value info, const string&libPath);

    shared_ptr<Command> parent;
};

extern vector<shared_ptr<Command>> commands;

shared_ptr<Command> findCommand(const string&name, const vector<shared_ptr<Command>>&DICTIONARY);

shared_ptr<Command> findCommand(const string&name);

#endif //SHUFFLE_INCLUDE_COMMANDMGR_H_
