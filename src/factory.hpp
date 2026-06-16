#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "system.hpp"
#include "model.hpp"
#include "flow.hpp"
#include <string>

/**
 * @file factory.hpp
 * @brief Funcoes de fabrica para criacao centralizada de objetos do simulador.
 *
 * Expoe estritamente as interfaces abstratas publicas (System, Model, Flow),
 * isolando completamente as classes concretas do conhecimento do cliente.
 */

/**
 * @brief Cria um novo objeto System.
 * @param name Nome descritivo do sistema (padrao: "").
 * @param value Valor inicial do sistema (padrao: 0.0).
 * @return Ponteiro para a interface System.
 */
System* createSystem(std::string name = "", double value = 0.0);

/**
 * @brief Cria um novo objeto Model.
 * @return Ponteiro para a interface Model.
 */
Model* createModel();

/**
 * @brief Cria um novo objeto de fluxo Exponencial.
 * @param name Nome do fluxo.
 * @param origin Ponteiro para o sistema de origem.
 * @param destination Ponteiro para o sistema de destino.
 * @return Ponteiro para a interface Flow.
 */
Flow* createExponentialFlow(std::string name = "", System* origin = nullptr, System* destination = nullptr);

/**
 * @brief Cria um novo objeto de fluxo Logistico.
 * @param name Nome do fluxo.
 * @param origin Ponteiro para o sistema de origem.
 * @param destination Ponteiro para o sistema de destino.
 * @param pMax Limite maximo suportado pelo fluxo logistico.
 * @return Ponteiro para a interface Flow.
 */
Flow* createLogisticFlow(std::string name = "", System* origin = nullptr, System* destination = nullptr, double pMax = 0.0);

#endif // FACTORY_HPP