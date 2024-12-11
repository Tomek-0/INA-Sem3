#include "server_controller.hpp"
#include "server.hpp"

#include "cmd_add_game.hpp"
#include "cmd_list_games.hpp"
#include "cmd_join_game.hpp"
#include "cmd_move.hpp"

ServerController::ServerController(Server* server) : server(server) {
    server = server;
    initialize_commands();
}

void ServerController::initialize_commands() {
    command_registry_["create"] = std::make_unique<CmdAddGame>(*this);
    command_registry_["list"] = std::make_unique<CmdListGames>(*this);
    command_registry_["join"] = std::make_unique<CmdJoinGame>(*this);
    command_registry_["move"] = std::make_unique<CmdMove>(*this);
}


std::vector<std::string> parse_stvs(const std::string& message) {
    std::vector<std::string> tokens;
    std::istringstream stream(message);
    std::string token;
    while (stream >> token) { 
        tokens.push_back(token);
    }
    return tokens;
}

void ServerController::parse_call(const std::string& message, int client_number) {
    // Messeage is in format: "command arg1 arg2 ..."
    std::vector<std::string> tokens = parse_stvs(message); 

    if (tokens.empty()) {
        return;
    }

    
    std::string command_name = tokens[0];
    tokens.erase(tokens.begin()); 

    std::cout << "execute " << command_name << std::endl;

    // Szukamy polecenia w rejestrze
    auto it = command_registry_.find(command_name);
    if (it != command_registry_.end()) {
        // Przekazujemy pozostałe tokeny jako argumenty oraz numer klienta
        it->second->execute(tokens, client_number);
    } else {
        std::cerr << "Command not found: " << command_name << std::endl;
    }
}

void ServerController::send_call(const std::string& message, int client_number) {
    server->send_message(message, client_number);
}

void ServerController::add_game(const Game& game) {
    current_games.push_back(game);
}

void ServerController::delete_game(int game_id) {
    current_games.erase(current_games.begin() + game_id);
}

std::vector<Game> ServerController::game_list() {
    return current_games;
}

void ServerController::join_game(int game_id){

    //TODO: Add player to the game
    current_games.at(game_id);
}

void ServerController::move(int x1, int y1, int x2, int y2){

    //TODO: Implemement movement
    
}