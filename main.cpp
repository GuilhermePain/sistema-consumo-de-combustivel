#include <iostream>
#include <iomanip>  // para setprecision
#include <cmath>

using namespace std;

int main() {
    double distance, fuel, time;  // distância (km), combustível disponível (litros), tempo disponível (horas)
    const double consumptionBase = 1.0;  // consumo base (1L = 20 km como exemplo, ajustável)
    
    cout << fixed << setprecision(2); // para mostrar 2 casas decimais
    
    cout << "=== Sistema de Consumo de Combustível ===\n\n";
    cout << "Digite a distancia da viagem (em km): ";
    cin >> distance;

    cout << "Digite a quantidade de gasolina disponivel (em litros): ";
    cin >> fuel;

    cout << "Digite o tempo disponivel para a viagem (em horas): ";
    cin >> time;

    // Calcula a velocidade média necessária
    double avgSpeed = distance / time;
    cout << "\nPara concluir a viagem em " << time << " horas, voce precisara manter uma velocidade media de "
         << avgSpeed << " km/h.\n";

    // Cálculo do consumo de combustível ajustado à velocidade
    // A cada 20 km/h, o consumo aumenta multiplicando por 0.9 (ou seja, 10% a mais de gasto)
    double speedFactor = avgSpeed / 20.0;
    double adjustedConsumption = consumptionBase * pow(0.9, speedFactor); // cada 20 km/h reduz eficiência
    double kmPerLiter = 20 * adjustedConsumption; // eficiência ajustada
    double fuelNeeded = distance / kmPerLiter;

    cout << "\nConsumo ajustado pela velocidade: " << kmPerLiter << " km/L";
    cout << "\nCombustivel necessario para a viagem: " << fuelNeeded << " litros";
    cout << "\nCombustivel disponivel: " << fuel << " litros\n";

    // Verifica se precisa abastecer
    if (fuelNeeded > fuel) {
        double missingFuel = fuelNeeded - fuel;
        cout << "\nVoce precisara abastecer aproximadamente " << missingFuel << " litros a mais.\n";
        
        double fuelPrice;
        cout << "Digite o preco do combustivel (por litro): R$ ";
        cin >> fuelPrice;

        double totalCost = missingFuel * fuelPrice;
        cout << "O custo total para completar o tanque sera de R$ " << totalCost << ".\n";
    } else {
        cout << "\nVoce tem combustivel suficiente para completar a viagem!\n";
    }

    cout << "\n=== Fim do programa ===\n";
    return 0;
}


// DEV 1 — Estrutura base e entrada de dados

// Tarefas:

//  Criar o arquivo principal main.c ou main.cpp

//  Declarar as variáveis (em inglês):

// float avgSpeed, fuelEfficiency, distance = 187, time, fuelPrice, fuelNeeded, totalCost;

// Usar scanf e printf para entrada e saída:

// printf("Enter average speed (km/h): ");
// scanf("%f", &avgSpeed);

// Calcular:

// time = distance / avgSpeed

// fuelNeeded = distance / fuelEfficiency

// totalCost = fuelNeeded * fuelPrice

// Mostrar os resultados com printf