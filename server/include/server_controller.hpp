#ifndef __SERVERCONTROLLER__
#define __SERVERCONTROLLER__

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

#include "game.hpp"
#include "abstract_command.hpp"

class Server;

class ServerController {
public:
    ServerController(Server* server);
    ~ServerController() = default;

    void parse_call(const std::string& message, int client_number);
    void send_call(const std::string& message, int client_number);

    void add_game(const Game& game);
    void delete_game(int game_id);
    std::vector<Game> game_list();
    void join_game(int game_id);
    void move(int x1, int y1, int x2, int y2);

private:
    Server* server;
    std::unordered_map<std::string, std::unique_ptr<AbstractCommand>> command_registry_;
    std::vector<Game> current_games;
    void initialize_commands();
};

#endif // __SERVERCONTROLLER__
