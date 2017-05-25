#include "abstractcontroller.h"

AbstractController::AbstractController()
{

}

void AbstractController::setPayer(Player &player)
{
    this->player = &player;
}
