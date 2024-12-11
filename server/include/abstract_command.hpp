#ifndef __ABSTRACTCOMMAND__
#define __ABSTRACTCOMMAND__

#include <vector>
#include <string>

class AbstractCommand {
public:
    virtual ~AbstractCommand() = default;
    virtual void execute(const std::vector<std::string>& args, int client_number) = 0;
};

#endif // __ABSTRACTCOMMAND__

