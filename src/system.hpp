#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include <vector>
#include <string>

/**
 * @brief Classe que representa um Sistema (variável de estado) na simulação.
 * @details Armazena um valor numérico que representa o estado atual do sistema e um identificador (nome).
 */
class System {
private:
    std::string name; ///< Nome identificador do sistema.
    double value;     ///< Valor/conteúdo atual do sistema.

public:
    /**
     * @brief Construtor padrão e parametrizado da classe System.
     * @param name Nome do sistema (padrão é vazio "").
     * @param value Valor inicial do sistema (padrão é 0.0).
     */
    System(std::string name = "", double value = 0.0);

    /**
     * @brief Destrutor virtual da classe System.
     */
    virtual ~System();

    /**
     * @brief Construtor de cópia da classe System.
     * @param other Objeto System a ser copiado.
     */
    System(const System& other);

    /**
     * @brief Operador de atribuição sobrecarregado da classe System.
     * @param other Objeto System de onde os dados serão copiados.
     * @return Referência para o próprio objeto System atualizado.
     */
    System& operator=(const System& other);

    /**
     * @brief Retorna o nome do sistema.
     * @return std::string Nome do sistema.
     */
    std::string getName() const;

    /**
     * @brief Retorna o valor atual do sistema.
     * @return double Valor atual do sistema.
     */
    double getValue() const;

    /**
     * @brief Define um novo valor para o sistema.
     * @param v Novo valor numérico a ser atribuído ao sistema.
     */
    void setValue(double v);
};
#endif