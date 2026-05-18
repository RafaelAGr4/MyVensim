# MyVensim
>Simulador de Dinãmica de Sistema inspirado no Vensim, feito em C++ com arquitetura orientada a objetos.
---

## Visão Geral
**MyVensim** é um simulador de dinâmica de sistemas que modela a evolução temporal de variáveis de estado (**Systems**) conectadas por fluxos (**Flows**). Permite simular fenômenos como crescimento exponencial, crescimento logístico e sistemas complexos com múltiplas interações. Sendo possivel criar outras simulações, pelo fato de serem classes genéricas.

## Estrutura do projeto

- \MyVensim
  +\bin
  + \src
    main.cpp
    mySim.cpp
    mySim.h
  - \test
    - \unit
        main.cpp
        unit_tests.h
        unit_tests.cpp
    - \funcional
        main.cpp
        funcional_tests.h
        funcional_tests.cpp

---

| Classe | Responsabilidade |
|---|---|
| `Model` | Orquestra a simulação; mantém lista de sistemas e fluxos; executa os passos de tempo |
| `System` | Representa uma variável de estado com nome e valor numérico |
| `Flow` | Classe abstrata que define um fluxo entre dois sistemas |
| `FlowExponencial` | Implementação concreta de fluxo com equação exponencial |
