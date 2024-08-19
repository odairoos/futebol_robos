// Interface Robo
// Autor : Odair
// Data: 17 AGO 2024
// Objetivo: Permite a implementacao de componente especifico

class Robo {
public:
    virtual void registrarPartida() = 0;
    virtual std::string getPosicao() const = 0;
    virtual void getEstatisticas() const = 0;
    virtual ~Robo() = default; // Destrutor virtual padrão
};
