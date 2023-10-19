#include <exception>


class InvalidBet : public std::exception {

private:
    const char* message;

public:
    InvalidBet(const char* msg);
    const char* what() const noexcept;
};