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

        // Verificação de entradas inválidas
    if (distance <= 0 || fuel <= 0 || time <= 0) {
        cout << "\n[Erro] Valores invalidos inseridos! (distancia, combustivel e tempo devem ser maiores que 0)\n";
        cout << "=== Fim do programa ===\n";
        return 0;
    }

    // Estrutura "Viagem longa" – usar for para simular paradas (ex: consumo acumulado a cada 50 km)
    cout << "\n=== Simulacao de Viagem Longa ===\n";
    double totalConsumed = 0;
    for (double km = 50; km <= distance; km += 50) {
        totalConsumed += 50 / kmPerLiter;
        cout << "Aos " << km << " km, total consumido: " << totalConsumed << " L\n";
    }

    //Atrasado
    if (avgSpeed > 120) {
        cout << "\nCondicao 'Você está atrasado': A velocidade necessaria (" << avgSpeed 
             << " km/h) e muito alta. Voce chegara atrasado se dirigir com seguranca.\n";
    }

    // Lisozinho
    if (fuel > fuelNeeded * 1.2) {
        cout << "\nCondicao 'Está lisinho': Voce possui combustivel de sobra para uma viagem tranquila.\n";
    }


    cout << "\n=== Fim do programa ===\n";
    return 0;
}