#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include <vector>
#include <string>
class System {
private:
    std::string name;
    double value;

public:
    // Construtor e Destrutor
    System(std::string name = "", double value = 0.0);
    virtual ~System();

    System(const System& other);
    System& operator=(const System& other);

    std::string getName() const;
    double getValue() const;
    void setValue(double v);
};
#endif