#ifndef __CMDMOVE__
#define __CMDMOVE__

#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <cstring>
#include <mutex>
#include <algorithm>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <unordered_map>
#include <memory>
#include <sstream>

#include "abstract_command.hpp"
#include "server_controller.hpp"
#include "game.hpp"

class CmdMove : public AbstractCommand {
public:
    CmdMove(ServerController& controller) : controller(controller) {}

    void execute(const std::vector<std::string>& args, int client_number) {
        Game* game = new Game();

        
        
        int x1 = std::stoi(args[0]);
        int y1 = std::stoi(args[1]);
        int x2 = std::stoi(args[2]);
        int y2 = std::stoi(args[3]);
       

        controller.move(x1, y1);

        controller.send_call("Moved (x1,y1) to (x2,y2)\n", client_number);
    }

private:
    ServerController& controller;
};

#endif // __CMDADDGAME__
