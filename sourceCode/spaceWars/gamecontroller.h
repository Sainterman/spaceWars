#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "ship.h"  //Incluido porque contiene a GraphicChar, GraphicObject y Point
#include "ship2.h"
#include <QList>
#include <sys/time.h>
#include "conio.h"
#include <QPoint>
class gameController
{
private:

    QList<graphicObjects*> _gObjects;
    const static int _FIELD_HEIGHT;
    const static int _FIELD_WIDTH;
    int initGobjects();//inicializo los graphicObjects
    int msTime();//leo el tiempo del sistema en milisegundos
    int paintGame();//pinta el espacio de juego
    int recvUserCmd();
    int checkCollitions();
    int addNewGraphObj();
    int removeDeadObjects();
    QList<int> _Descition;
    ship* _player1;
    ship* _player2;
    ship* _player3;


protected:

public:

    gameController();
    QList<int> pickShip();
    int printUI();//Dibuja la interfaz gráfica
    int run();//corre el juego



};

#endif // GAMECONTROLLER_H
