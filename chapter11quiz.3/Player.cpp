#include "Player.h"

void Player::levelUp()
  {
    m_level += 1;
    m_damage += 1;
  }

  //function called hasWon() that returns true if the player has reached level 20.
bool Player::hasWon()
{
  return m_level >= 20;
}
