// Classe Zagueiro
// Autor : Odair
// Data: 17 AGO 2024
// Objetivo: Permite a implementacao de componente especifico


class Zagueiro : public RoboFutebol {
private:
    int faltasCometidas;

public:
    Zagueiro(int id) : RoboFutebol(id, "Zagueiro"), faltasCometidas(0) {}

    void registrarPartida() override {
        // Implementar lógica para registrar faltas cometidas
    }

    void getEstatisticas() const override {
        std::cout << "Zagueiro - Faltas Cometidas: " << faltasCometidas << std::endl;
    }
};
