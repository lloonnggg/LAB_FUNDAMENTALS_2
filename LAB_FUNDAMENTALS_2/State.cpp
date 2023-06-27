#include "state.h"

//--------------------------------------------------------TITLE STATE--------------------------------------------------------
void TitleState::handleInput(SDL_Event e) 
{
    // Implement input handling for Start Game button
}
void TitleState::update(SDL_Event event)
{
    // Implement any necessary updates, if any
}
void TitleState::render(SDL_Renderer* renderer)
{
    assets->LoadTexture(renderer);
    SDL_RenderCopy(renderer, assets->StopScreen, NULL, NULL);
    assets->GameNameRect->x = ScreenWidth / 2 - (assets->GameNameRect->w / 2);
    assets->GameNameRect->y = ScreenHeight / 4;
    assets->GameNameRect->w = 300;
    assets->GameNameRect->h = 100;
    SDL_RenderCopy(renderer, assets->GameName, NULL, assets->GameNameRect);
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
void GameState::update(SDL_Event event)
{
    handleInput(event);
    player->Pbullet.Player_bullet_Y -= player->Pbullet.Player_bullet_Vel;
    if (player->Pbullet.Player_bullet_Y < -40)
    {
        player->GetBulletCoordinate();
    }

    //HAZARDS
    for (int i = 0; i < maxHazards; i++)
    {
        hazard[i].HazardY += hazard[i].HazardVel;
        if (hazard[i].HazardY > ScreenHeight)
        {
            hazard[i].HazardCoordinateGenerator(i);
        }
        //PLAYER BULLET vs OBSTACLE
        if (player->Pbullet.Player_bullet_X < hazard[i].HazardX + hazard[i].HazardW &&
            player->Pbullet.Player_bullet_X + player->Pbullet.Player_bullet_W > hazard[i].HazardX &&
            player->Pbullet.Player_bullet_Y < hazard[i].HazardY + hazard[i].HazardH &&
            player->Pbullet.Player_bullet_Y + player->Pbullet.Player_bullet_H > hazard[i].HazardY)
        {
            //player->Pbullet.Player_bullet_X = 0;
            //player->Pbullet.Player_bullet_Y = 0;
        }
        //PLAYER vs OBSTACLE
        if (player->PlayerX < hazard[i].HazardX + hazard[i].HazardW &&
            player->PlayerX + player->PlayerW > hazard[i].HazardX &&
            player->PlayerY < hazard[i].HazardY + hazard[i].HazardH &&
            player->PlayerY + player->PlayerH > hazard[i].HazardY)
        {
            //Mix_PlayChannel(-1, projectile_hit_sound, 0);
            //quit = true;
        }
    }

    //MOBS
    for (int i = 0; i < maxMobs; i++)
    {
        mob[i].MobY += mob[i].MobVel;
        mob[i].Ebullet.Enemy_bullet_Y += mob[i].Ebullet.Enemy_bullet_Vel;
        if (mob[i].Ebullet.Enemy_bullet_Y > ScreenHeight + 40)
        {
            mob[i].GetEbulletCoordinate();
        }
        if (mob[i].MobY > ScreenHeight)
        {
            mob[i].MobCoordinateGenerator(i);
        }
        //PLAYER BULLET vs ENEMY
        if (player->Pbullet.Player_bullet_X < mob[i].MobX + mob[i].MobW &&
            player->Pbullet.Player_bullet_X + player->Pbullet.Player_bullet_W > mob[i].MobX &&
            player->Pbullet.Player_bullet_Y < mob[i].MobY + mob[i].MobH &&
            player->Pbullet.Player_bullet_Y + player->Pbullet.Player_bullet_H > mob[i].MobY)
        {
            player->GetBulletCoordinate();
            mob[i].MobCoordinateGenerator(i);
        }

        //PLAYER BULLET vs ENEMY BULLET
        if (player->Pbullet.Player_bullet_X < mob[i].Ebullet.Enemy_bullet_X + mob[i].Ebullet.Enemy_bullet_W &&
            player->Pbullet.Player_bullet_X + player->Pbullet.Player_bullet_W > mob[i].Ebullet.Enemy_bullet_X &&
            player->Pbullet.Player_bullet_Y < mob[i].Ebullet.Enemy_bullet_Y + mob[i].Ebullet.Enemy_bullet_H &&
            player->Pbullet.Player_bullet_Y + player->Pbullet.Player_bullet_H > mob[i].Ebullet.Enemy_bullet_Y)
        {
            player->GetBulletCoordinate();
            mob[i].GetEbulletCoordinate();
        }

        //PLAYER vs ENEMY BULLET
        if (player->PlayerX < mob[i].Ebullet.Enemy_bullet_X + mob[i].Ebullet.Enemy_bullet_W &&
            player->PlayerX + player->PlayerW > mob[i].Ebullet.Enemy_bullet_X &&
            player->PlayerY < mob[i].Ebullet.Enemy_bullet_Y + mob[i].Ebullet.Enemy_bullet_H &&
            player->PlayerY + player->PlayerH > mob[i].Ebullet.Enemy_bullet_Y)
        {
            player->PlayerHP--;
        }

        //PLAYER vs ENEMY
        if (player->PlayerX < mob[i].MobX + mob[i].MobW &&
            player->PlayerX + player->PlayerW > mob[i].MobX &&
            player->PlayerY < mob[i].MobY + mob[i].MobH &&
            player->PlayerY + player->PlayerH > mob[i].MobY)
        {
            player->PlayerHP--;
            mob[i].MobCoordinateGenerator(i);
        }
    }
}
void GameState::render(SDL_Renderer* renderer) 
{
    //assets->ScrollingBG(renderer, assets->BackgroundIMG);
    assets->LoadTexture(renderer);

    //--------------------PLAYER--------------------
    assets->PlayerRect->x = player->PlayerX;
    assets->PlayerRect->y = player->PlayerY;
    assets->PlayerRect->w = player->PlayerW;
    assets->PlayerRect->h = player->PlayerH;
    assets->PlayerBulletRect->x = player->Pbullet.Player_bullet_X;
    assets->PlayerBulletRect->y = player->Pbullet.Player_bullet_Y;
    assets->PlayerBulletRect->w = player->Pbullet.Player_bullet_W;
    assets->PlayerBulletRect->h = player->Pbullet.Player_bullet_H;
    SDL_RenderCopy(renderer, assets->Player, NULL, assets->PlayerRect);
    SDL_RenderCopy(renderer, assets->PlayerBullet, NULL, assets->PlayerBulletRect);

    //--------------------HAZARD--------------------
    for (int i = 0; i < maxHazards; i++)
    {
        assets->HazardRect[i].x = hazard[i].HazardX;
        assets->HazardRect[i].x = hazard[i].HazardY;
        assets->HazardRect[i].x = hazard[i].HazardW;
        assets->HazardRect[i].x = hazard[i].HazardH;
        SDL_RenderCopy(renderer, assets->Hazard, NULL, assets->HazardRect);
    }

    //--------------------THREATS--------------------
    for (int i = 0; i < maxMobs; i++)
    {
        assets->EnemyRect[i].x = mob[i].MobX;
        assets->EnemyRect[i].y = mob[i].MobY;
        assets->EnemyRect[i].w = mob[i].MobW;
        assets->EnemyRect[i].h = mob[i].MobH;
        assets->EnemyBulletRect[i].x = mob[i].Ebullet.Enemy_bullet_X;
        assets->EnemyBulletRect[i].y = mob[i].Ebullet.Enemy_bullet_Y;
        assets->EnemyBulletRect[i].w = mob[i].Ebullet.Enemy_bullet_W;
        assets->EnemyBulletRect[i].h = mob[i].Ebullet.Enemy_bullet_H;
        SDL_RenderCopy(renderer, assets->Enemy, NULL, assets->EnemyRect);
        SDL_RenderCopy(renderer, assets->EnemyBullet, NULL, assets->EnemyBulletRect);
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
void PauseState::update(SDL_Event event)
{
    // No game updates when the game is paused
}
void PauseState::render(SDL_Renderer* renderer)
{
    assets->LoadTexture(renderer);
    SDL_RenderCopy(renderer, assets->StopScreen, NULL, NULL);
    assets->GameNameRect->x = ScreenWidth / 2 - (assets->GameNameRect->w / 2);
    assets->GameNameRect->y = ScreenHeight / 4;
    assets->GameNameRect->w = 300;
    assets->GameNameRect->h = 100;
    SDL_RenderCopy(renderer, assets->GameName, NULL, assets->GameNameRect);
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
void LoseState::update(SDL_Event event)
{
    // Implement any necessary updates, if any
}
void LoseState::render(SDL_Renderer* renderer)
{
    assets->LoadTexture(renderer);
    SDL_RenderCopy(renderer, assets->StopScreen, NULL, NULL);
    assets->GameOverRect->x = ScreenWidth / 2 - (assets->GameNameRect->w / 2);
    assets->GameOverRect->y = ScreenHeight / 2 - (assets->GameNameRect->h / 2);
    assets->GameOverRect->w = 300;
    assets->GameOverRect->h = 100;
    SDL_RenderCopy(renderer, assets->GameName, NULL, assets->GameOverRect);
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
void WinState::update(SDL_Event event)
{
    // Implement any necessary updates, if any
}
void WinState::render(SDL_Renderer* renderer)
{
    assets->LoadTexture(renderer);
    SDL_RenderCopy(renderer, assets->StopScreen, NULL, NULL);
    assets->YouWinRect->x = ScreenWidth / 2 - (assets->GameNameRect->w / 2);
    assets->YouWinRect->y = ScreenHeight / 2 - (assets->GameNameRect->h / 2);
    assets->YouWinRect->w = 300;
    assets->YouWinRect->h = 100;
    SDL_RenderCopy(renderer, assets->GameName, NULL, assets->YouWinRect);
}
void WinState::changestate()
{

}
//--------------------------------------------------------WIN STATE--------------------------------------------------------