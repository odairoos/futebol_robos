class Atacante : public RoboFutebol {
private:
    int golsFeitos;

public:
    Atacante(int id) : RoboFutebol(id, "Atacante"), golsFeitos(0) {}

    void registrarPartida() override {
        // Implementar lógica para registrar gols feitos
    }

    void getEstatisticas() const override {
        std::cout << "Atacante - Gols Feitos: " << golsFeitos << std::endl;
    }
};
