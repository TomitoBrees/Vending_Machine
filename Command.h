// An abstract Command class that defines the interface for all commands

#ifndef COMMAND_H
#define COMMAND_H

class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

#endif // COMMAND_H