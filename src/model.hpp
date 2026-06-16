#ifndef MODEL_HPP
#define MODEL_HPP

#include "system.hpp"
#include "flow.hpp"
#include <vector>

/**
 * @brief Interface da classe Model.
 * Define o contrato do motor de simulacao: adicionar/remover Systems e Flows,
 * expor iteradores para percorrer as colecoes e executar o laco de simulacao.
 */
class Model {
public:
    typedef std::vector<System*>::iterator systemIterator;
    typedef std::vector<Flow*>::iterator   flowIterator;

    /**
     * @brief Destrutor virtual puro da interface Model.
     */
    virtual ~Model() {}

    /**
     * @brief Executa o laco de simulacao temporal.
     * @param start Tempo inicial da simulacao.
     * @param final_time Tempo final da simulacao.
     * @param inc Incremento de tempo a cada passo.
     */
    virtual void execute(double start, double final_time, double inc) = 0;

    /**
     * @brief Adiciona um sistema ao modelo.
     * @param s Ponteiro para a interface do sistema.
     */
    virtual void add(System* s) = 0;

    /**
     * @brief Adiciona um fluxo ao modelo.
     * @param f Ponteiro para a interface do fluxo.
     */
    virtual void add(Flow* f) = 0;

    /**
     * @brief Remove um sistema do modelo.
     * @param s Ponteiro para o sistema a ser removido.
     */
    virtual void remove(System* s) = 0;

    /**
     * @brief Remove um fluxo do modelo.
     * @param f Ponteiro para o fluxo a ser removido.
     */
    virtual void remove(Flow* f) = 0;

    /**
     * @brief Retorna o iterador para o inicio da colecao de sistemas.
     */
    virtual systemIterator beginSystems() = 0;

    /**
     * @brief Retorna o iterador para o fim da colecao de sistemas.
     */
    virtual systemIterator endSystems() = 0;

    /**
     * @brief Retorna o iterador para o inicio da colecao de fluxos.
     */
    virtual flowIterator   beginFlows() = 0;

    /**
     * @brief Retorna o iterador para o fim da colecao de fluxos.
     */
    virtual flowIterator   endFlows() = 0;
};

#endif // MODEL_HPP