#ifndef SYSTEM_IMPL_HPP
#define SYSTEM_IMPL_HPP
#include "system.hpp"

class SystemImpl : public System {
private:
    std::string name;
    double value;

public:
    SystemImpl(std::string name = "", double value = 0.0);
    virtual ~SystemImpl();
    SystemImpl(const SystemImpl& other);
    SystemImpl& operator=(const SystemImpl& other);

    std::string getName() const override;
    void setName(const std::string& name) override;
    double getValue() const override;
    void setValue(double value) override;
};

#endif