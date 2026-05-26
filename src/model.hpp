#ifndef MODEL_HPP
#define MODEL_HPP
#include <vector>
#include "system.hpp"
#include "flow.hpp"

/**
 * @brief Classe que representa o Modelo/Container principal da simulação.
 * @details Gerencia a execução temporal do simulador, contendo listas de todos os sistemas e fluxos associados.
 */
class Model {
private:
    double time;                     ///< Tempo atual da simulação.
    std::vector<System*> systems;    ///< Vetor de ponteiros contendo todos os sistemas do modelo.
    std::vector<Flow*> flows;        ///< Vetor de ponteiros contendo todos os fluxos do modelo.

public:
    /**
     * @brief Construtor padrão do modelo.
     * @param time Tempo inicial atribuído ao cronômetro do modelo (padrão é 0.0).
     */
    Model(double time = 0.0);

    /**
     * @brief Destrutor da classe Model. Responsável por limpar a memória se necessário.
     */
    virtual ~Model();

    /**
     * @brief Operador de atribuição sobrecarregado da classe Model.
     */
    Model& operator=(const Model& other);

    /**
     * @brief Construtor de cópia da classe Model.
     */
    Model(const Model& other);

    /**
     * @brief Adiciona um Sistema ao modelo.
     * @param s Ponteiro para o objeto System a ser monitorado pelo modelo.
     */
    void add(System* s);

    /**
     * @brief Adiciona um Fluxo ao modelo.
     * @param f Ponteiro para o objeto Flow a ser processado pelo modelo.
     */
    void add(Flow* f);

    /**
     * @brief Executa o laço principal da simulação.
     * @details Incrementa o tempo do passo `start` até o `end`, executando os fluxos e atualizando os sistemas.
     * @param start Tempo de início do loop da simulação.
     * @param end Tempo de término do loop da simulação.
     */
    void run(double start, double end);

    /**
     * @brief Retorna o tempo atual acumulado no relógio da simulação.
     * @return double Tempo atual do modelo.
     */
    double getTime() const;
};
#endif