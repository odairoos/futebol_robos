#include <vector>
#include <iostream>
#include <memory>

class Time {
private:
    std::string nomeTime;
    std::shared_ptr<Goleiro> goleiro;
    std::vector<std::shared_ptr<Zagueiro>> zagueiros;
    std::vector<std::shared_ptr<Atacante>> atacantes;

public:
    Time(const std::string& nome) : nomeTime(nome) {}

    void adicionarRobo(const std::string& posicao, std::shared_ptr<Robo> robo) {
        if (posicao == "goleiro") {
            goleiro = std::dynamic_pointer_cast<Goleiro>(robo);
        } else if (posicao == "zagueiro" && zagueiros.size() < 5) {
            zagueiros.push_back(std::dynamic_pointer_cast<Zagueiro>(robo));
        } else if (posicao == "atacante" && atacantes.size() < 5) {
            atacantes.push_back(std::dynamic_pointer_cast<Atacante>(robo));
        }
    }

    void registrarEstatisticas() const {
        if (goleiro) {
            goleiro->registrarPartida();
            goleiro->getEstatisticas();
        }
        for (const auto& zagueiro : zagueiros) {
            zagueiro->registrarPartida();
            zagueiro->getEstatisticas();
        }
        for (const auto& atacante : atacantes) {
            atacante->registrarPartida();
            atacante->getEstatisticas();
        }
    }
};
