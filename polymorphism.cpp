// Ejercicio: Sistema de formas geométricas
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Forma 
{
public:
    Forma();

    virtual ~Forma();
    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;

    static int obtenerNumeroFormas();
protected:
    static int numeroFormas;
};

int Forma::numeroFormas = 0;

Forma::Forma()
{
    cout << "Objeto siendo creado..." << endl;
    numeroFormas += 1;
}

Forma::~Forma() 
{
    cout << "Objeto siendo eliminado" << endl;
    numeroFormas -= 1;
}

int Forma::obtenerNumeroFormas()
{
    return numeroFormas;
}

class Circulo : public Forma
{
public:
    explicit Circulo(double r);
    double calcularArea() const override;
    double calcularPerimetro() const override;
protected:
    double radio;
};

Circulo::Circulo(double r) : Forma(), radio(r) {}
 
double Circulo::calcularArea() const
{
    return 3.14159 * radio * radio;
}

double Circulo::calcularPerimetro() const
{
    return 2 * 3.14159 * radio;
}


class Rectangulo : public Forma
{
public:
    Rectangulo(double b, double a);
    double calcularArea() const override;
    double calcularPerimetro() const override;
protected:
    double base, altura;
};

Rectangulo::Rectangulo(double b, double a) : base(b), altura(a) {}

double Rectangulo::calcularArea() const
{
    return base * altura;
}

double Rectangulo::calcularPerimetro() const
{
    return 2 * (base + altura);
}



int main() 
{
    Circulo* c1 = new Circulo(5);
    Rectangulo* r1 = new Rectangulo(8, 4);

    cout << "Numero de formas geométricas: " << Forma::obtenerNumeroFormas() << endl;

    cout << "Área del círculo: " << c1->calcularArea() << endl;
    cout << "Perímetro del círculo: " << c1->calcularPerimetro() << endl;
    
    cout << "Área del rectángulo: " << r1->calcularArea() << endl;
    cout << "Perímetro del rectángulo: " << r1->calcularPerimetro() << endl;

    delete c1;
    delete r1;

    cout << "Numero de formas geométricas: " << Forma::obtenerNumeroFormas() << endl;
}

