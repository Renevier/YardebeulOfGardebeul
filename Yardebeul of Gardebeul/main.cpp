#include "Tool.h"
#include "Game.h"
#include "Character.h"
#include "Hero.h"
#include "NPC.h"
#include "Effect.h"
#include "EffectContainer.h"
#include "Effect.h"

//void AfficheStat(Character &_c)
//{
//    _c.DisplayStats();
//}


int main()
{
    //with SFML
    Game game;

    game.Run();

    //without SFML

    //Hero myHero("Toto");

    //myHero.GainExp(201);
    //AfficheStat(myHero);

    //NPC npc("tutu", 2, Behaviour::HELPFULL, 100.0f, 10.f, 10.f);

    //cout << "Effect: ----------------------" << endl;
    //Effect myEffect("Fire ball", false, 10, 3);
    //Effect my_effect("Leech seed", false, -10, 3);

    //myEffect.AffectPlayer();
    //my_effect.AffectPlayer();

    //EffectContainer myEffectConttainer;

    //myEffectConttainer.GetContainer().at(0);
    return 0;
}