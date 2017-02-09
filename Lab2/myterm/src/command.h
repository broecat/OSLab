#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <vector>
class command
{
    public:
    command();
        const bool exit_requested() const {return this->exit_requested_;}
        bool readline();
        void print_usage() const;
        void execute();
        std::vector<std::string> parameters;
    private:
        bool exit_requested_;
        bool is_valid_command_line(const std::string &line) const;
        bool parse_line(const std::string &line);
        
};
#endif