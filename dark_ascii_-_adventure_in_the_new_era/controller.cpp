#include "controller.h"

Controller::Controller(Level lvl, )
{
    player = new Player();
    AllNPC allNPC;
    AllItems allItems;
    level = new Level(lvl);
}

Controller::changeCoords(int newX, int newY)
{
    player.coords.x = newX;
    player.coords.y = newY;
}

Controller::effectByCell(Cell cell)
{
    if (cell.type == TRAP)
    {
        DamageTypes dmg = new DamageTypes();
        dmg.pricking = 5.0;
        //ловушка должна нанести 5 очков колющего урона
        player.takeDamage(dmg);
    }
    else if (cell.type == DOOR)
    {
        //TODO изменить кооординаты текущей комнаты
        //и прописать игроку координаты в новой комнате
    }
    else if (cell.type == OUT)
    {
        Controller::FinishLevel();
    }
}

Controller::dice(int lowBorder, int highBorder)
{
    srand(time(0));
    int x = rand()%100;
    return (x >= lowBorder && x < highBorder);
}
Controller::npcNear(Coords coords)
{
    for (int i = 0; i < allNPC.npcs.size(); i++)
    {   //расстояние до НИПа есть модуль разности координат; 1 - НИП рядом, больше - не рядом
        if ( (abs(allNPC.npcs.get(i).coords.x - coords.x) < 2)
        && (abs(allNPC.npcs.get(i).coords.y - coords.y) < 2) )
        {
            return true;
        }
    }
    return false;
}

Controller::GameTick(int keyCode)
{
    //проверяем, на чём стоим, воздействуем
    //rX, rY - индексы текущей комнаты в level
    effectByCell(level.rooms[rX][rY].cells[player.coords.x + 1][player.coords.y]);

    //анализируем нажатую клавишу
    if (keyCode == KEY_ESC || keyCode = KEY_BACKSPACE) //открыть меню паузы
    {
        Controller::menuPause();
        continue;
    }
    else if (keyCode == KEY_TAB) //открыть инвентарь
    {
        Controller::menuInventory();
    }
    else if (keyCode == KEY_E) //попытка взаимодействовать
    {
        if(npcNear(player.coords))
            Controller::menuInteract();
        else
            Controller::menuInventory();
    }
    else if (keyCode == KEY_UP || keyCode == KEY_W) //попытка пойти вверх
    {   //rX, rY - индексы текущей комнаты в level
        if (level.rooms[rX][rY].cells[player.coords.x][player.coords.y - 1].type != WALL)
        {
            Controller::changeCoords(player.coords.x, player.coords.y - 1);
        }
    }
    else if (keyCode == KEY_LEFT || keyCode == KEY_A) //попытка пойти влево
    {
        if (level.rooms[rX][rY].cells[player.coords.x - 1][player.coords.y].type != WALL)
        {
            Controller::changeCoords(player.coords.x - 1, player.coords.y);
        }
    }
    else if (keyCode == KEY_DOWN || keyCode == KEY_S) //попытка пойти вниз
    {
        if (level.rooms[rX][rY].cells[player.coords.x][player.coords.y + 1].type != WALL)
        {
            Controller::changeCoords(player.coords.x, player.coords.y + 1);
        }
    }
    else if (keyCode == KEY_RIGHT || keyCode == KEY_D) //попытка пойти вправо
    {
        if (level.rooms[rX][rY].cells[player.coords.x + 1][player.coords.y].type != WALL)
        {
            Controller::changeCoords(player.coords.x + 1, player.coords.y);
        }
    }

    if(Controller::dice() == true) //бросок кубиков на шанс вступить в бой
    {
        Controller::menuBattle();
    }
}
