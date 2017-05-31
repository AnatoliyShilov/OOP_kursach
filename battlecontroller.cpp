#include "battlecontroller.h"

void BattleController::battle(NPC *enemy, int enemyCount)
{
    int key;
    int aliveEnemy;
    int tab = 0, oAttack = 0, oBattleMode = 0, oTwoHand = 0;
    char iTab[6], iAttack[enemyCount], iBattleMode[4], iTwoHand[3];
    for (int i = 1; i < 3; i++)
        iTwoHand[i] = ' ';
    for (int i = 1; i < 4; i++)
        iBattleMode[i] = ' ';
    for (int i = 1; i < 6; i++)
        iTab[i] = ' ';
    int avoid = 0;
    for (int i = 1; i < enemyCount; i ++)
    {
        iAttack[i] = ' ';
        avoid += enemy[i].getDex();
    }
    bool turn;
    while (true)
    {
        if (player->isDead())
            return;
        aliveEnemy = 0;
        for (int i = 0; i < enemyCount; i++)
            if (enemy[i].isDead())
                aliveEnemy++;
        if (aliveEnemy == enemyCount)
            break;
        player->regenStamina();
        turn = true;
        tab = 0;
        while (turn)
        {
            system("cls");
            iTab[tab] = '>';
            iAttack[oAttack] = '>';
            iBattleMode[oBattleMode] = '>';
            iTwoHand[oTwoHand] = '>';
            std::cout<<"\t\t\t���� �������\n";
            switch (tab)
            {
            case 0:
            case 2:
            case 4:
            case 5:
            {
                std::cout<<"\t�������� ���������� ��� �����\n";
                for (int i = 0; i < enemyCount; i++)
                {
                    std::cout<<"\t"<<iAttack[i]<<" "<<enemy[i].getInfo().name;
                    if (!enemy[i].isDead())
                        std::cout<<" [ "<<enemy[i].getBattleChars().health<<" hp ]\n";
                    else
                        std::cout<<" �����\n";
                }
                break;
            }
            case 1:
            {
                std::cout<<"\t�������� ����� �����\n"
                            "\t"<<iBattleMode[0]<<" �������\n"<<
                            "\t"<<iBattleMode[1]<<" ���������\n"<<
                            "\t"<<iBattleMode[2]<<" �����������\n"<<
                            "\t"<<iBattleMode[3]<<" ������������\n";
                break;
            }
            case 3:
            {
                std::cout<<"\t����� ������ ����� � ��� ����?\n"<<
                           "\t"<<iTwoHand[0]<<" �������� ��������� �����\n"<<
                           "\t"<<iTwoHand[1]<<" ������\n"<<
                           "\t"<<iTwoHand[2]<<" ������\n";
                break;
            }
            }
            std::cout<<iTab[0]<<" ����� "<<
                        iTab[1]<<" ����� ����� "<<
                        iTab[2]<<" ������������ ������� "<<
                        iTab[3]<<" ��������� ����� \n"<<
                        iTab[4]<<" ����� ���� "<<
                        iTab[5]<<" �����\n"<<
                        "��������: "<<player->getBattleChars().health<<
                        " ������������: "<<player->getBattleChars().stamina<<
                        " �������: "<<player->getMedKitCount()<<"\n";
            std::cout<<"������� ������:\n";
            if ((!player->getEquipment().twoHanded[0] && !player->getEquipment().twoHanded[1])
                    || player->getEquipment().twoHanded[0])
            {
                std::cout<<"\t"<<player->getEquipment().weapon[0].getInfo().item.name<<
                           "   ���������: "<<player->getEquipment().weapon[0].getInfo().item.durability<<"\n";
            }
            if ((!player->getEquipment().twoHanded[1] && !player->getEquipment().twoHanded[0])
                    || player->getEquipment().twoHanded[1])
            {
                std::cout<<"\t"<<player->getEquipment().weapon[1].getInfo().item.name<<
                           "   ���������: "<<player->getEquipment().weapon[0].getInfo().item.durability<<"\n";
            }
            std::cout<<"����� �����:   ";
            switch (player->getBattleMod())
            {
            case None:
                std::cout<<"�����\n";
                break;
            case Parry:
                std::cout<<"�����������\n";
                break;
            case Deviation:
                std::cout<<"���������\n";
                break;
            case Protection:
                std::cout<<"������\n";
                break;
            }

            key = Menu::keyDecoder(getch());
            iTab[tab] = ' ';
            if (key == ENTER)
            {
                switch (tab)
                {
                case 0:
                {
                    if (enemy[oAttack].isDead())
                        break;
                    if (!player->isCritical(enemy[oAttack].getDex()))
                        if (!player->is2handed())
                        {
                            enemy[oAttack].takeDamage(player->makeDamage(0));
                            enemy[oAttack].takeDamage(player->makeDamage(1));
                        }
                        else
                            enemy[oAttack].takeDamage(player->makeDamage(0));
                    else
                        if (!player->is2handed())
                        {
                            enemy[oAttack].takeCriticalDamage(player->makeDamage(0));
                            enemy[oAttack].takeCriticalDamage(player->makeDamage(1));
                        }
                        else
                            enemy[oAttack].takeCriticalDamage(player->makeDamage(0));
                    if (enemy[oAttack].isDead())
                        player->addFragments(enemy[oAttack].getFragments());
                    break;
                }
                case 1:
                {
                    player->setBattleMode(BattleMod(oBattleMode));
                    break;
                }
                case 2:
                {
                    player->useMedKit();
                    break;
                }
                case 3:
                {
                    switch (oTwoHand)
                    {
                    case 0:
                    {
                        player->unset2handed();
                        break;
                    }
                    case 1:
                    {
                        player->set2handedW0();
                        break;
                    }
                    case 2:
                    {
                        player->set2handedW1();
                        break;
                    }
                    }

                    break;
                }
                case 4:
                {
                    turn = false;
                    break;
                }
                case 5:
                {
                    turn = false;
                    if (player->isDeviation(avoid))
                        return;
                    break;
                }
                }
                continue;
            }
            iAttack[oAttack] = ' ';
            iBattleMode[oBattleMode] = ' ';
            iTwoHand[oTwoHand] = ' ';
            if (key == RIGHT)
            {
                tab++;
                oAttack = 0;
                oBattleMode = 0;
                oTwoHand = 0;
                if (tab > 5)
                    tab = 0;
                continue;
            }
            if (key == LEFT)
            {
                tab--;
                oAttack = 0;
                oBattleMode = 0;
                oTwoHand = 0;
                if (tab < 0)
                    tab = 5;
                continue;
            }
            if (key == DOWN)
            {
                oAttack++;
                oBattleMode++;
                oTwoHand++;
                if (oAttack > enemyCount - 1)
                    oAttack = 0;
                if (oBattleMode > 3)
                    oBattleMode = 0;
                if (oTwoHand > 2)
                    oTwoHand = 0;
                continue;
            }
            if (key == UP)
            {
                oAttack--;
                oBattleMode--;
                oTwoHand--;
                if (oAttack < 0)
                    oAttack = enemyCount - 1;
                if (oBattleMode < 0)
                    oBattleMode = 3;
                if (oTwoHand < 0)
                    oTwoHand = 2;
            }
        }
        for (int i = 0; i < enemyCount; i++)
        {
            if (!enemy[i].isDead())
            {
                enemy[i].regenStamina();
                if (player->isParry(enemy[i].getDex()))
                {
                    if (!player->is2handed())
                    {
                        enemy[i].takeParryDamage(player->makeDamage(0));
                        enemy[i].takeParryDamage(player->makeDamage(1));
                    }
                    else
                        enemy[i].takeParryDamage(player->makeDamage(0));
                    continue;
                }
                if (player->isDeviation(enemy[i].getDex()))
                    continue;
                if (enemy[i].isCritical(player->getDex()))
                {
                    player->takeCriticalDamage(enemy[i].makeDamage(0));
                    player->takeCriticalDamage(enemy[i].makeDamage(1));
                }
                else
                {
                    player->takeDamage(enemy[i].makeDamage(0));
                    player->takeDamage(enemy[i].makeDamage(1));
                }
            }
        }
    }
    for (int i = 0; i < enemyCount; i++)
    {
        for (Link<Accessory> *ac = enemy[i].openBag()->accessories.getBegin(); ac; ac = ac->Next)
            if (Dice::random(99) < player->getCurrentChars().luck)
                player->add(ac->data);
        for (Link<Armor> *ar = enemy[i].openBag()->armors.getBegin(); ar; ar = ar->Next)
            if (Dice::random(99) < player->getCurrentChars().luck)
                player->add(ar->data);
        for (Link<Weapon> *w = enemy[i].openBag()->weapons.getBegin(); w; w = w->Next)
            if (Dice::random(99) < player->getCurrentChars().luck)
                player->add(w->data);
    }
}

int BattleController::start()
{
    Dice::init();
    if (Dice::random(9))
        return 0;
    Menu::info("", "\t\t\t�� ��� ������!");
    int enemyCount = Dice::random(4) + 1;
    NPC enemy[enemyCount], *temp;
    for (int i = 0; i < enemyCount; i ++)
    {
        temp = npcs->getNPC(Dice::random(npcs->getCount() - 2) + 2);
        enemy[i].setInfo(temp->getInfo());
        for (Link<Accessory> *ac = temp->openBag()->accessories.getBegin(); ac; ac = ac->Next)
            enemy[i].add(ac->data);
        for (Link<Armor> *ar = temp->openBag()->armors.getBegin(); ar; ar = ar->Next)
            enemy[i].add(ar->data);
        for (Link<Weapon> *w = temp->openBag()->weapons.getBegin(); w; w = w->Next)
            enemy[i].add(w->data);
        enemy[i].updateCharsCurrent();
        enemy[i].resetBattleChars();
    }
    battle(enemy, enemyCount);
    return 0;
}

void BattleController::setNPCs(AllNPC &npcs)
{
    this->npcs = &npcs;
}

BattleController::BattleController()
{

}
