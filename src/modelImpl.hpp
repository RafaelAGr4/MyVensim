#ifndef MODEL_IMPL_HPP
#define MODEL_IMPL_HPP

#include "model.hpp"
#include <vector>

/**
 * @brief Implementacao concreta da interface Model.
 * Armazena as colecoes de Systems e Flows em vetores e implementa
 * o algoritmo de atualizacao simultanea em execute().
 */
class ModelImpl : public Model {
protected:
    double time;                     /**< Tempo atual da simulacao */
    std::vector<System*> systems;    /**< Vetor de ponteiros para os sistemas do modelo */
    std::vector<Flow*>   flows;      /**< Vetor de ponteiros para os fluxos do modelo */
    
    /** * @brief Vetor estatico global para rastrear todos os modelos instanciados.
     * Utilizado para o gerenciamento seguro e exclusao automatica de referencias.
     */
    static std::vector<Model*> models; 

public:
    /**
     * @brief Construtor padrao da classe ModelImpl.
     */
    ModelImpl();

    /**
     * @brief Construtor de copia de ModelImpl.
     */
    ModelImpl(const ModelImpl& obj);

    /**
     * @brief Destrutor da classe ModelImpl.
     * Remove a si mesmo do vetor estatico de controle e limpa as colecoes locais.
     */
    virtual ~ModelImpl();

    /**
     * @brief Operador de atribuicao por copia para ModelImpl.
     */
    ModelImpl& operator=(const ModelImpl& obj);

    void execute(double start, double final_time, double inc) override;
    void add(System* s) override;
    void add(Flow* f) override;
    void remove(System* s) override;
    void remove(Flow* f) override;
    
    systemIterator beginSystems() override;
    systemIterator endSystems() override;
    flowIterator   beginFlows() override;
    flowIterator   endFlows() override;
};

#endif // MODEL_IMPL_HPP