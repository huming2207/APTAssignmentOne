#include "player.h"

void initialisePlayer(Player * player, Position * position, Direction direction)
{
    player->position = *position;
    player->direction = direction;
}

void turnDirection(Player * player, TurnDirection turnDirection)
{
    if(turnDirection == TURN_LEFT)
    {
        switch(player->direction)
        {
            case NORTH: player->direction = WEST; break;
            case WEST: player->direction = SOUTH; break;
            case SOUTH: player->direction = EAST; break;
            case EAST: player->direction = NORTH; break;
        }
    }
    else if(turnDirection == TURN_RIGHT)
    {
        switch(player->direction)
        {
            case NORTH: player->direction = EAST; break;
            case EAST: player->direction = SOUTH; break;
            case SOUTH: player->direction = WEST; break;
            case WEST: player->direction = NORTH; break;
        }
    }
}

Position getNextForwardPosition(const Player * player)
{
    Position position;

    switch(player->direction)
    {
        /* moving north just minus 1 of Y value */
        case NORTH:
        {
            position.x = player->position.x;
            position.y = player->position.y - 1;
            break;
        }

        /* moving north just plus 1 of Y value */
        case SOUTH:
        {
            position.x = player->position.x;
            position.y = player->position.y + 1;
        }

        /* moving north just plus 1 of X value */
        case EAST:
        {
            position.x = player->position.x + 1;
            position.y = player->position.y;
        }

        /* moving north just minus 1 of X value */
        case WEST:
        {
            position.x = player->position.x - 1;
            position.y = player->position.y;
        }

        /* ...it's useless for another default case, just use it to let the clang compiler warnings shut up, lol. */
        default:
        {
            position.x = player->position.x;
            position.y = player->position.y;
        }
    }

    return position;
}

void updatePosition(Player * player, Position position)
{

}

void displayDirection(Direction direction)
{
    /* TODO */
}
