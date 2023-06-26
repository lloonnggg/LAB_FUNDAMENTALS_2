#include "state.h"

//--------------------------------------------------------TITLE STATE--------------------------------------------------------
void TitleState::handleInput(SDL_Event e) 
{
    // Implement input handling for Start Game button
}
void TitleState::update() 
{
    // Implement any necessary updates, if any
}
void TitleState::render(SDL_Renderer* renderer)
{
    assets->LoadTexture(renderer);
    SDL_RenderCopy(renderer, assets->Background, NULL, NULL);
}
void TitleState::changestate()
{

}
//--------------------------------------------------------TITLE STATE--------------------------------------------------------



//--------------------------------------------------------GAME STATE--------------------------------------------------------
void GameState::handleInput(SDL_Event e) 
{
    player->HandlePlayerInput(e);
}
void GameState::update() 
{
    //HAZARDS
    for (int i = 0; i < maxHazards; i++)
    {
        hazard[i]->HazardY += hazard[i]->HazardVel;
        if (hazard[i]->HazardY >= ScreenHeight)
        {
            hazard[i]->HazardCoordinateGenerator(i);
        }
        //PLAYER BULLET vs OBSTACLE
        if (player->Pbullet.Player_bullet_X < hazard[i]->HazardX + hazard[i]->HazardW &&
            player->Pbullet.Player_bullet_X + player->Pbullet.Player_bullet_W > hazard[i]->HazardX &&
            player->Pbullet.Player_bullet_Y < hazard[i]->HazardY + hazard[i]->HazardH &&
            player->Pbullet.Player_bullet_Y + player->Pbullet.Player_bullet_H > hazard[i]->HazardY)
        {
            //player->Pbullet.Player_bullet_X = 0;
            //player->Pbullet.Player_bullet_Y = 0;
        }
        //PLAYER vs OBSTACLE
        if (player->PlayerX < hazard[i]->HazardX + hazard[i]->HazardW &&
            player->PlayerX + player->PlayerW > hazard[i]->HazardX &&
            player->PlayerY < hazard[i]->HazardY + hazard[i]->HazardH &&
            player->PlayerY + player->PlayerH > hazard[i]->HazardY)
        {
            //Mix_PlayChannel(-1, projectile_hit_sound, 0);
            //quit = true;
        }
    }

    //MOBS
    for (int i = 0; i < maxMobs; i++)
    {
        mob[i]->MobY += mob[i]->MobVel;
        if (mob[i]->MobY >= ScreenHeight)
        {
            mob[i]->MobCoordinateGenerator(i);
        }
        //PLAYER BULLET vs ENEMY
        if (player->Pbullet.Player_bullet_X < mob[i]->MobX + mob[i]->MobW &&
            player->Pbullet.Player_bullet_X + player->Pbullet.Player_bullet_W > mob[i]->MobX &&
            player->Pbullet.Player_bullet_Y < mob[i]->MobY + mob[i]->MobH &&
            player->Pbullet.Player_bullet_Y + player->Pbullet.Player_bullet_H > mob[i]->MobY)
        {
            //BulletX = 0;
            //BulletY = 0;
            //ThreatRect = { Threat[i].x, Threat[i].y, ThreatW, ThreatH };
            //SDL_RenderCopy(renderer, T_explosion, NULL, &ThreatRect);
            //ThreatCoordinateGenerator(i);
            //Mix_PlayChannel(-1, projectile_hit_sound, 0);
            //hit++;
        }

        //PLAYER BULLET vs ENEMY BULLET
        if (player->Pbullet.Player_bullet_X < mob[i]->Ebullet.Enemy_bullet_X + mob[i]->Ebullet.Enemy_bullet_W &&
            player->Pbullet.Player_bullet_X + player->Pbullet.Player_bullet_W > mob[i]->Ebullet.Enemy_bullet_X &&
            player->Pbullet.Player_bullet_Y < mob[i]->Ebullet.Enemy_bullet_Y + mob[i]->Ebullet.Enemy_bullet_H &&
            player->Pbullet.Player_bullet_Y + player->Pbullet.Player_bullet_H > mob[i]->Ebullet.Enemy_bullet_Y)
        {
            //BulletX = 0;
            //BulletY = 0;
            //Threat[i].BulletX = 0;
            //Threat[i].BulletY = 0;
        }

        //PLAYER vs ENEMY BULLET
        if (player->PlayerX < mob[i]->Ebullet.Enemy_bullet_X + mob[i]->Ebullet.Enemy_bullet_W &&
            player->PlayerX + player->PlayerW > mob[i]->Ebullet.Enemy_bullet_X &&
            player->PlayerY < mob[i]->Ebullet.Enemy_bullet_Y + mob[i]->Ebullet.Enemy_bullet_H &&
            player->PlayerY + player->PlayerH > mob[i]->Ebullet.Enemy_bullet_Y)
        {
            //PlayerHP--;
            //Threat[i].BulletX = 0;
            //Threat[i].BulletY = 0;
            //Mix_PlayChannel(-1, projectile_hit_sound, 0);
            //if (PlayerHP == 0)
            //{
            //    quit = true;
            //}

        }

        //PLAYER vs ENEMY
        if (player->PlayerX < mob[i]->MobX + mob[i]->MobW &&
            player->PlayerX + player->PlayerW > mob[i]->MobX &&
            player->PlayerY < mob[i]->MobY + mob[i]->MobH &&
            player->PlayerY + player->PlayerH > mob[i]->MobY)
        {
            //PlayerHP--;
            //ThreatRect = { Threat[i].x, Threat[i].y, ThreatW, ThreatH };
            //SDL_RenderCopy(renderer, T_explosion, NULL, &ThreatRect);
            //ThreatCoordinateGenerator(i);
            //Mix_PlayChannel(-1, projectile_hit_sound, 0);
            //hit++;
            //if (PlayerHP == 0)
            //{
            //    quit = true;
            //}
        }
    }
}
void GameState::render(SDL_Renderer* renderer) 
{
    assets->LoadTexture(renderer);
    assets->PlayerRect->x = player->PlayerX;
    assets->PlayerRect->y = player->PlayerY;
    assets->PlayerRect->w = player->PlayerW;
    assets->PlayerRect->h = player->PlayerH;

    assets->PlayerBulletRect->x = player->PlayerX;
    assets->PlayerBulletRect->y = player->PlayerY;
    assets->PlayerBulletRect->w = player->PlayerW;
    assets->PlayerBulletRect->h = player->PlayerH;
    SDL_RenderCopy(renderer, assets->Background, NULL, NULL);
    SDL_RenderCopy(renderer, assets->Player, NULL, assets->PlayerRect);
    SDL_RenderCopy(renderer, assets->PlayerBullet, NULL, assets->PlayerBulletRect);

    for (int i = 0; i < maxHazards; i++)
    {
        assets->HazardRect[i].x = hazard[i]->HazardX;
        assets->HazardRect[i].x = hazard[i]->HazardY;
        assets->HazardRect[i].x = hazard[i]->HazardW;
        assets->HazardRect[i].x = hazard[i]->HazardH;
        SDL_RenderCopy(renderer, assets->Hazard, NULL, assets->HazardRect);
    }
    for (int i = 0; i < maxMobs; i++)
    {
        assets->EnemyRect[i].x = mob[i]->MobX;
        assets->EnemyRect[i].y = mob[i]->MobY;
        assets->EnemyRect[i].w = mob[i]->MobW;
        assets->EnemyRect[i].h = mob[i]->MobH;
        SDL_RenderCopy(renderer, assets->Enemy, NULL, assets->EnemyRect);
    }
}
void GameState::changestate()
{

}
//--------------------------------------------------------GAME STATE--------------------------------------------------------



//--------------------------------------------------------PAUSE STATE--------------------------------------------------------
void PauseState::handleInput(SDL_Event e) 
{
    // Implement input handling for Resume button
}
void PauseState::update() 
{
    // No game updates when the game is paused
}
void PauseState::render(SDL_Renderer* renderer)
{
    // Render a transparent rectangle over the game state and a Resume button
}
void PauseState::changestate()
{

}
//--------------------------------------------------------PAUSE STATE--------------------------------------------------------



//--------------------------------------------------------LOSE STATE--------------------------------------------------------
void LoseState::handleInput(SDL_Event e) 
{
    // Implement input handling for Main Menu button
}
void LoseState::update() 
{
    // Implement any necessary updates, if any
}
void LoseState::render(SDL_Renderer* renderer)
{
    // Render anything you want but keep it clean
}
void LoseState::changestate()
{

}
//--------------------------------------------------------LOSE STATE--------------------------------------------------------



//--------------------------------------------------------WIN STATE--------------------------------------------------------
void WinState::handleInput(SDL_Event e) 
{
    // Implement input handling for Main Menu button
}
void WinState::update() 
{
    // Implement any necessary updates, if any
}
void WinState::render(SDL_Renderer* renderer)
{
    // Render anything you want but keep it clean
}
void WinState::changestate()
{

}
//--------------------------------------------------------WIN STATE--------------------------------------------------------