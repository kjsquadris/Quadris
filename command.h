#ifndef COMMAND_H
#define COMMAND_H

class Command : public CmdInterpreter {
public:
  void execute();
};

#endif