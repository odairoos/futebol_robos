// Classe Goleiro
// Autor : Odair
// Data: 17 AGO 2024
// Objetivo: Permite a implementacao de componente especifico


class Goleiro : public RoboFutebol {
private:
    int golsSofridos;

public:
    Goleiro(int id) : RoboFutebol(id, "Goleiro"), golsSofridos(0) {}

    void registrarPartida() override {
        // Implementar lógica para registrar gols sofridos
    }

    void getEstatisticas() const override {
        std::cout << "Goleiro - Gols Sofridos: " << golsSofridos << std::endl;
    }
};
