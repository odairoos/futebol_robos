// Classe TIME
// Autor : Odair
// Data: 17 AGO 2024
// Objetivo: Jogo de robo 

#include <vector>
#include <iostream>
#include <memory>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()

class Robo {
public:
    virtual void registrarPartida() = 0;
    virtual std::string getPosicao() const = 0;
    virtual void getEstatisticas() const = 0;
    virtual int getId() const = 0; // Novo método para obter o ID do robô
    virtual ~Robo() = default;
};

class RoboFutebol : public Robo {
protected:
    int idRobo;
    std::string posicao;

public:
    RoboFutebol(int id, const std::string& pos) : idRobo(id), posicao(pos) {}

    int getId() const override {
        return idRobo;
    }

    std::string getPosicao() const override {
        return posicao;
    }

    virtual void getEstatisticas() const override = 0;
    virtual void registrarPartida() override = 0;
};

class Goleiro : public RoboFutebol {
private:
    int golsSofridos;

public:
    Goleiro(int id) : RoboFutebol(id, "Goleiro"), golsSofridos(0) {}

    void registrarPartida() override {
        golsSofridos += rand() % 5; // Simula gols sofridos (0-4 por partida)
    }

    void getEstatisticas() const override {
        std::cout << "Goleiro #" << idRobo << " - Gols Sofridos: " << golsSofridos << std::endl;
    }
};

class Zagueiro : public RoboFutebol {
private:
    int faltasCometidas;

public:
    Zagueiro(int id) : RoboFutebol(id, "Zagueiro"), faltasCometidas(0) {}

    void registrarPartida() override {
        faltasCometidas += rand() % 3; // Simula faltas cometidas (0-2 por partida)
    }

    void getEstatisticas() const override {
        std::cout << "Zagueiro #" << idRobo << " - Faltas Cometidas: " << faltasCometidas << std::endl;
    }
};

class Atacante : public RoboFutebol {
private:
    int golsFeitos;

public:
    Atacante(int id) : RoboFutebol(id, "Atacante"), golsFeitos(0) {}

    void registrarPartida() override {
        golsFeitos += rand() % 3; // Simula gols feitos (0-2 por partida)
    }

    void getEstatisticas() const override {
        std::cout << "Atacante #" << idRobo << " - Gols Feitos: " << golsFeitos << std::endl;
    }
};

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

int main() {
    srand(static_cast<unsigned int>(time(0))); // Inicializa a semente aleatória

    // Criando o time
    Time time("Robôs ITA FC");

    // Criando e adicionando os robôs ao time
    auto goleiro = std::make_shared<Goleiro>(1);
    time.adicionarRobo("goleiro", goleiro);

    for (int i = 2; i <= 6; ++i) {
        auto zagueiro = std::make_shared<Zagueiro>(i);
        time.adicionarRobo("zagueiro", zagueiro);
    }

    for (int i = 7; i <= 11; ++i) {
        auto atacante = std::make_shared<Atacante>(i);
        time.adicionarRobo("atacante", atacante);
    }

    // Simulando 5 partidas
    for (int i = 0; i < 5; ++i) {
        std::cout << "Partida " << i + 1 << std::endl;
        time.registrarEstatisticas();
        std::cout << "------------------------" << std::endl;
    }

    return 0;
}
