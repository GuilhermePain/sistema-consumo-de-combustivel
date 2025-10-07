#include <iostream>
#include <iomanip>  // para setprecision
#include <cmath>
#include <limits> // limpar o buffer de entrada

using namespace std;

int main() {

    double distance, fuel, time;  // distância (km), combustível disponível (litros), tempo disponível (horas)
    const double consumptionBase = 1.0;  // consumo base (1L = 20 km como exemplo, ajustável)

    cout << fixed << setprecision(2); // para mostrar 2 casas decimais

    cout << "=== Sistema de Consumo de Combustível ===\n\n";

    cout << "ATENCAO: Por favor, use ponto (.) como separador decimal (ex: 2.5) e nao virgula.\n\n";

    while (true) {
        cout << "Digite a distancia da viagem (em km): ";
        if (cin >> distance) {
            if (distance > 0) {
                // AQUI: Adicione esta linha de volta
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            else {
                cout << "[Erro] O valor da distancia deve ser maior que zero. Tente novamente.\n";
            }
        }
        else {
            cout << "[Erro] Entrada invalida. Por favor, digite um numero. Tente novamente.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    while (true) {
        cout << "Digite a quantidade de gasolina disponivel (em litros): ";
        if (cin >> fuel) {
            if (fuel > 0) {
                // --- CORREÇÃO ADICIONADA AQUI ---
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            else {
                cout << "[Erro] A quantidade de combustivel deve ser maior que zero. Tente novamente.\n";
            }
        }
        else {
            cout << "[Erro] Entrada invalida. Por favor, digite um numero. Tente novamente.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    while (true) {
        cout << "Digite o tempo disponivel para a viagem (em horas): ";
        if (cin >> time) {
            if (time > 0) {
                // --- CORREÇÃO ADICIONADA AQUI ---
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            else {
                cout << "[Erro] O tempo deve ser maior que zero. Tente novamente.\n";
            }
        }
        else {
            cout << "[Erro] Entrada invalida. Por favor, digite um numero. Tente novamente.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Calcula a velocidade média necessária
    double avgSpeed = distance / time;
    cout << "\nPara concluir a viagem em " << time << " horas, voce precisara manter uma velocidade media de "
        << avgSpeed << " km/h.\n";

    // Cálculo do consumo de combustível ajustado à velocidade
    // A cada 20 km/h, o consumo aumenta multiplicando por 0.9 (ou seja, 10% a mais de gasto)
    double speedFactor = avgSpeed / 20.0;
    double adjustedConsumption = consumptionBase * pow(0.9, speedFactor); // cada 20 km/h reduz eficiência
    double kmPerLiter = 20 * adjustedConsumption; // eficiência ajustada

    // Prevenção contra divisão por zero lógica
    if (kmPerLiter < 0.01) {
        cout << "\n[Erro] A velocidade media necessaria e tao alta que o consumo de combustivel e impraticavel.\n";
        cout << "=== Fim do programa ===\n";
        return 0;
    }

    double fuelNeeded = distance / kmPerLiter;

    cout << "\nConsumo ajustado pela velocidade: " << kmPerLiter << " km/L";
    cout << "\nCombustivel necessario para a viagem: " << fuelNeeded << " litros";
    cout << "\nCombustivel disponivel: " << fuel << " litros\n";

    // Verifica se precisa abastecer
    if (fuelNeeded > fuel) {
        double missingFuel = fuelNeeded - fuel;
        cout << "\nVoce precisara abastecer aproximadamente " << missingFuel << " litros a mais.\n";

        double fuelPrice;
        while (true) {
            cout << "Digite o preco do combustivel (por litro): R$ ";
            if (cin >> fuelPrice) {
                if (fuelPrice > 0) {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                else {
                    cout << "[Erro] O preco deve ser maior que zero. Tente novamente.\n";
                }
            }
            else {
                cout << "[Erro] Entrada invalida. Por favor, digite um numero. Tente novamente.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        double totalCost = missingFuel * fuelPrice;
        cout << "O custo total para completar o tanque sera de R$ " << totalCost << ".\n";

    }
    else {
        cout << "\nVoce tem combustivel suficiente para completar a viagem!\n";
    }

    // Estrutura "Viagem longa" – usar for para simular paradas (ex: consumo acumulado a cada 50 km)
    cout << "\n=== Simulacao de Viagem Longa ===\n";
    double totalConsumed = 0;
    for (double km = 50; km <= distance; km += 50) {
        totalConsumed += 50 / kmPerLiter;
        cout << "Aos " << km << " km, total consumido: " << totalConsumed << " L\n";
    }

    // Relatório final para a simulação
    if (distance > totalConsumed * kmPerLiter) {
        cout << "Ao final da viagem de " << distance << " km, o consumo total sera de " << fuelNeeded << " L.\n";
    }

    // "Atrasado" e "Lisozinho"
    if (avgSpeed > 120) {
        cout << "\nCondicao 'Voce esta atrasado': A velocidade necessaria (" << avgSpeed
            << " km/h) e muito alta. Voce chegara atrasado se dirigir com seguranca.\n";
    }

    if (fuel > fuelNeeded * 1.2) {
        cout << "\nCondicao 'Esta lisinho': Voce possui combustivel de sobra para uma viagem tranquila.\n";
    }


    cout << "\n=== Fim do programa ===\n";
    return 0;
}