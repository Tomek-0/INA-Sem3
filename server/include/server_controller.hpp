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

class ServerController {
public:
    ServerController();
    ~ServerController() = default;

    void parse_call(const std::string& message, int client_number);
    void send_call(const std::string& message, int client_numbere);

    void add_game(const Game& game);
    void delete_game(int game_id);
    std::vector<Game> game_list();

private:
    std::unordered_map<int, std::unique_ptr<AbstractCommand>> command_registry_;
    std::vector<Game> current_games_;
    void initialize_commands();
};

#endif // __SERVERCONTROLLER__