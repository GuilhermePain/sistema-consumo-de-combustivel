# 🚗 Sistema de Consumo de Combustível

#Link para histórico de desenvolvimento e demais anexos de organograma, análise de requisitos e fluxograma do sistema:
https://trello.com/b/lgtAIFOi/sistema-de-combust%C3%ADvel

## 📘 Descrição
Este programa em **C++** calcula e valida a quantidade de combustível necessária para uma viagem, considerando:

- Distância da viagem (km)  
- Tempo disponível (horas)  
- Combustível disponível (litros)  

O sistema ajusta o consumo de acordo com a velocidade, simula o progresso da viagem e indica se será necessário abastecer.

---

## ⚙️ Funcionalidades

- Cálculo da velocidade média necessária.  
- Ajuste automático do consumo (km/L) com base na velocidade.  
- Verificação da necessidade de abastecimento e cálculo do custo adicional.  
- Simulação de viagem longa (consumo acumulado a cada 50 km).  
- Alertas especiais:
  - 🚨 “Você está atrasado” → velocidade média muito alta (>120 km/h)  
  - ✅ “Está lisinho” → combustível disponível 20% acima do necessário  
- Validação de entradas inválidas (valores ≤ 0).

---

## 🧮 Variáveis Principais

| Variável             | Tipo         | Significado                                                                 |
|---------------------|-------------|---------------------------------------------------------------------------|
| `distance`           | double      | Distância da viagem em km (entrada do usuário, >0)                         |
| `fuel`               | double      | Combustível disponível em litros (entrada do usuário, >0)                 |
| `time`               | double      | Tempo disponível para a viagem em horas (entrada do usuário, >0)          |
| `consumptionBase`    | const double| Consumo base (1L = 20 km de autonomia)                                     |
| `avgSpeed`           | double      | Velocidade média calculada (km/h)                                         |
| `speedFactor`        | double      | Fator usado para ajustar consumo baseado na velocidade                     |
| `adjustedConsumption`| double      | Consumo ajustado pelo fator de velocidade                                  |
| `kmPerLiter`         | double      | Autonomia final do veículo (km/L) após ajuste                               |
| `fuelNeeded`         | double      | Combustível necessário para completar a viagem                             |
| `missingFuel`        | double      | Quantidade de combustível que falta se `fuelNeeded > fuel`                 |
| `fuelPrice`          | double      | Preço do combustível por litro (entrada do usuário se precisar abastecer)  |
| `totalCost`          | double      | Custo total do combustível adicional                                        |
| `totalConsumed`      | double      | Combustível acumulado durante a simulação de viagem longa                   |
| `km`                 | double      | Contador da simulação de viagem longa em incrementos de 50 km               |

---

## 📊 Fórmulas Utilizadas

- Velocidade média (VM):  
  `avgSpeed = distance / time`

- Fator de ajuste do consumo:  
  `speedFactor = avgSpeed / 20`  
  `adjustedConsumption = consumptionBase * pow(0.9, speedFactor)`

- Autonomia ajustada (km/L):  
  `kmPerLiter = 20 * adjustedConsumption`

- Combustível necessário:  
  `fuelNeeded = distance / kmPerLiter`

- Combustível faltante (se houver):  
  `missingFuel = fuelNeeded - fuel`

- Custo do abastecimento adicional:  
  `totalCost = missingFuel * fuelPrice`

- Consumo acumulado durante viagem longa:  
  `totalConsumed += 50 / kmPerLiter` a cada 50 km

---

## 🧠 Lógica do Programa

1. O usuário insere distância, combustível disponível e tempo.  
2. Calcula-se a velocidade média (`avgSpeed`).  
3. Ajusta-se a autonomia (`kmPerLiter`) com base na velocidade.  
4. Calcula-se o combustível necessário (`fuelNeeded`) e compara com o disponível (`fuel`).  
5. Se houver falta, solicita preço do combustível (`fuelPrice`) e calcula custo total (`totalCost`).  
6. Simula a viagem longa, mostrando consumo acumulado (`totalConsumed`) a cada 50 km.  
7. Exibe alertas:
   - “Você está atrasado” → velocidade média > 120 km/h  
   - “Está lisinho” → combustível disponível ≥ 120% do necessário

---

## 📝 Exemplo de Entrada e Saída

**Entrada:**  
- Digite a distancia da viagem (em km): 187
- Digite a quantidade de gasolina disponivel (em litros): 8
- Digite o tempo disponivel para a viagem (em horas): 2
- Digite o preco do combustivel (por litro): 6.20


**Saída:**  
- Para concluir a viagem em 2 horas, voce precisara manter uma velocidade media de 93.50 km/h.
- Consumo ajustado pela velocidade: 13.82 km/L
- Combustivel necessario para a viagem: 13.53 litros
- Voce precisara abastecer aproximadamente 5.53 litros a mais.
- O custo total para completar o tanque sera de R$ 34.27.
- Condicao 'Está lisinho': Voce possui combustivel de sobra para uma viagem tranquila.
---
=== Fim do programa ===


---

## 🧰 Como Executar o Projeto

### ✅ Pré-requisitos
- Ter instalado um compilador **C++** (GCC, Clang ou MSVC).  
- Sistema operacional compatível (Windows, Linux ou macOS).

### 🔧 Compilação
Abra o terminal no diretório do arquivo e execute:

```bash
g++ sistema_consumo.cpp -o sistema_consumo
```
Execução

No Linux/macOS:

```./sistema_consumo```

No Windows:

```sistema_consumo.exe```
