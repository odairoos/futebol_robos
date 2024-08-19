class RoboFutebol : public Robo {
protected:
    int idRobo;
    std::string posicao;

public:
    RoboFutebol(int id, const std::string& pos) : idRobo(id), posicao(pos) {}

    std::string getPosicao() const override {
        return posicao;
    }

    virtual void getEstatisticas() const override = 0; // Classe abstrata pura

    virtual void registrarPartida() override = 0; // Classe abstrata pura
};
