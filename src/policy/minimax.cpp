
#include <cstdlib>
#include <iostream>
#include "../state/state.hpp"
#include "./minimax.hpp"

/**
 * @brief Randomly get a legal action
 *
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move
 */
Move Minimax::get_move(State *state, int depth)
{
    if (!state->legal_actions.size())
        state->get_legal_actions();

    int now = -1100;
    int same = 0;
    Move retMove;
    auto actions = state->legal_actions;
    for (auto action : actions)
    {
        State *nextState = state->next_state(action);
        int temp = nextState->evaluate();
        if (temp > now)
        {
            same++;
            now = temp;
            retMove = action;
        }
        else if (temp == now)
        {
            same++;
        }
    }
    if (same >= actions.size())
    {
        int k = depth;
        for (int i = 0; i < depth; i++)
        {
            k = rand() / k;
        }
        retMove = actions[(rand() + depth) % actions.size()];
    }
    return retMove;
}