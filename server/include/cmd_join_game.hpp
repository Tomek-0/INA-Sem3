#ifndef _CMDJOINGAME_
#define _CMDJOINGAME_

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

class CmdJoinGame : public AbstractCommand {
public:
    CmdJoinGame(ServerController& controller) : controller(controller) {}

    void execute(const std::vector<std::string>& args, int game_id) {

        Game* game = new Game();
        //add metod to controller
        controller.join_game(game_id);

        controller.send_call("Joined game\n", game_id);
    }

private:
    ServerController& controller;
};

#endif // _CMDJOINGAME_