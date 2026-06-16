#include "systemImpl.hpp"

/**
 * @brief Construtor padrao e parametrizado da classe SystemImpl.
 * Initializa o nome e o valor do sistema com os parâmetros fornecidos.
 */
SystemImpl::SystemImpl(std::string name, double v) : name(name), value(v) {}

/**
 * @brief Construtor de copia de SystemImpl.
 * Copia os atributos name e value do objeto de origem.
 */
SystemImpl::SystemImpl(const SystemImpl& obj) : name(obj.name), value(obj.value) {}

/**
 * @brief Destrutor da classe SystemImpl.
 */
SystemImpl::~SystemImpl() {}

/**
 * @brief Operador de atribuicao por copia para SystemImpl.
 * Garante a copia segura de todos os atributos evitando auto-atribuicao.
 */
SystemImpl& SystemImpl::operator=(const SystemImpl& obj) {
    if (this == &obj) return *this;
    name = obj.name;
    value = obj.value;
    return *this;
}

/**
 * @brief Obtem o nome do sistema.
 * @return string com o nome do sistema.
 */
std::string SystemImpl::getName() const {
    return name;
}

/**
 * @brief Define o nome do sistema.
 * @param name Novo nome do sistema.
 */
void SystemImpl::setName(const std::string name) {
    this->name = name;
}

/**
 * @brief Obtem o valor armazenado no sistema.
 * @return double correspondente ao valor atual.
 */
double SystemImpl::getValue() const {
    return value;
}

/**
 * @brief Define o valor do sistema.
 * @param v Novo valor a ser atribuido.
 */
void SystemImpl::setValue(double v) {
    value = v;
}