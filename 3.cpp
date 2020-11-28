#include <iostream> 
#include <math.h>

class Figura2D{
    public: 
    float lados[4]; 
    float perimetro; 
    float area;
};
class Cuadrilatero : public Figura2D{
    public:
    float calcularPerimetro(float lados[4]){
        int area,i; 
        perimetro = 0;
        for(i=0;i<4;i++){
            perimetro = perimetro + lados[i];
        }
        return perimetro; 
    }
}; 

Cuadrilatero rectangulo,trapecio, cuadrado;
Figura2D circulo, triangulo;

using namespace std; 

int main(){
    char opcion; 
    int i; 
    menu:
    cout << "CALCULOS DE FIGURAS: " << endl; 
    cout << endl << endl << endl;
    cout << " SELECCIONE UNA FIGURA PARA CALCULAR : " << endl; 
    cout << " 1 RECTANGULO " <<endl;
    cout << " 2 CIRCULO " <<endl;
    cout << " 3 TRAPECIO " <<endl;
    cout << " 4 CUADRADO " <<endl;
    cout << " 5 TRIANGULO " <<endl;
    cin >> opcion;

    //CALCULAR AREA Y PERIMETRO
    switch(opcion){
        case '1':{ //RECTANGULO
            cout << "INGRESE LA BASE DEL RECTANGULO " << endl; 
            cin >> rectangulo.lados[0];
            rectangulo.lados[2] = rectangulo.lados[0]; 
            cout << "INGRESE LA ALTURA DEL RECTANGULO " << endl;
            cin >> rectangulo.lados[1]; 
            rectangulo.lados[3] = rectangulo.lados[1];
            rectangulo.area = rectangulo.lados[0] * rectangulo.lados[1];
            rectangulo.perimetro = rectangulo.calcularPerimetro(rectangulo.lados); 

            cout << " EL AREA DEL RECTANGULO ES : " << rectangulo.area << endl; 
            cout << " EL PERIMETRO DEL RECTANGULO ES : " << rectangulo.perimetro << endl; 
        }break;
        case '2':{ //CIRCULO 
            cout << "INGRESE EL RADIO DEL CIRCULO " << endl; 
            cin >> circulo.lados[0]; // pedir radio
            circulo.area = M_PI * pow(circulo.lados[0],2);
            
            circulo.perimetro = 2 * M_PI * circulo.lados[0]; 

            cout << " EL AREA DEL CIRCULO ES : " << circulo.area << endl; 
            cout << " EL PERIMETRO DEL CIRCULO ES : " << circulo.perimetro << endl;
        }break;
        case '3':{ //TRAPECIO
            int x;
            cout << "INGRESE LA BASE MAYOR DEL TRAPECIO : " << endl; 
            cin >> trapecio.lados[0];
            cout << "INGRESE LA BASE MENOR  DEL TRAPECIO : " << endl; 
            cin >> trapecio.lados[2];
            cout << "INGRESE LA ALTURA DEL TRAPECIO : " << endl; 
            cin >> trapecio.lados[3];
            //calcular area:
            trapecio.area = 0.5 * (trapecio.lados[0]+trapecio.lados[2]) * trapecio.lados[3];
            //calcular perimetro: 
            x = -(0.5) * (trapecio.lados[2]-trapecio.lados[0]); 
            trapecio.lados[1] = sqrt(x*x+pow(trapecio.lados[3],2));
            trapecio.lados[3] = trapecio.lados[1];
            trapecio.perimetro = trapecio.calcularPerimetro(trapecio.lados);

            cout << " EL AREA DEL TRAPECIO ES : " << trapecio.area << endl; 
            cout << " EL PERIMETRO DEL TRAPECIO ES : " << trapecio.perimetro << endl;
        }break;
        case '4':{//CUADRADO
            cout << "INGRESE UN LADO DEL CUADRADO : " << endl;
            cin >> cuadrado.lados[0];
            for(i=1; i<3; i++){
                cuadrado.lados[i] = cuadrado.lados[0];
            }
            cuadrado.area = pow(cuadrado.lados[1],2);
            cuadrado.perimetro = cuadrado.calcularPerimetro(cuadrado.lados);
            cout << " EL AREA DEL CUADRADO ES : " << cuadrado.area << endl; 
            cout << " EL PERIMETRO DEL CUADRADO ES : " << cuadrado.perimetro << endl;
        }break;
        case '5':{ //TRIANGULO 
            cout << "INGRESE EL PRIMER LADO : " << endl;
            cin >> triangulo.lados[0]; 
            cout << "INGRESE EL SEGUNDO LADO : " << endl;
            cin >> triangulo.lados[1]; 
            cout << "INGRESE EL TERCER LADO : " << endl;
            cin >> triangulo.lados[2]; 
            triangulo.perimetro = triangulo.lados[0] + triangulo.lados[1] 
                                    + triangulo.lados[2]; 
            //USANDO FORMULA DE HERON:
            float s = triangulo.perimetro*0.5;
            triangulo.area = sqrt(s*(s-triangulo.lados[0])*(s-triangulo.lados[1])
                                        *(s-triangulo.lados[2]));
            cout << " EL AREA DEL TRIANGULO ES : " << triangulo.area << endl; 
            cout << " EL PERIMETRO DEL TRIANGULO ES : " << triangulo.perimetro << endl;
        }break;
        default:{};
    }
    goto menu; 

    return 0; 
}