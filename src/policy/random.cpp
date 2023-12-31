#include <cstdlib>

#include "../state/state.hpp"
#include "./random.hpp"

/**
 * @brief Randomly get a legal action
 *
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move
 */
Move Random::get_move(State *state, int depth)
{
  state->get_legal_actions();

  auto actions = state->legal_actions;
  int k = depth;
  for (int i = 0; i < depth; i++)
  {
    k = 10 / k;
  }
  return actions[k % actions.size()];
}