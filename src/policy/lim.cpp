#include <cstdlib>
#include <iostream>

#include "../state/state.hpp"
#include "./lim.hpp"

/**
 * @brief Randomly get a legal action
 *
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move
 */

int minimax(State *state, int depth, bool mm)
{

    if (!state->legal_actions.size())
        state->get_legal_actions();

    if (depth == 0 || !state->legal_actions.size())
    {
        return state->evaluate();
    }

    auto actions = state->legal_actions;

    State *tmp;
    int val, ret;

    if (mm)
    {
        ret = -1000000;
        for (auto i : actions)
        {
            tmp = state->next_state(i);
            val = minimax(tmp, depth - 1, false);
            if (val > ret)
            {
                ret = val;
            }
        }
    }
    else
    {
        ret = 1000000;
        for (auto i : actions)
        {
            tmp = state->next_state(i);
            val = minimax(tmp, depth - 1, true);
            if (val < ret)
            {
                ret = val;
            }
        }
    }

    return ret;
}

Move two::get_move(State *state, int depth)
{
    if (!state->legal_actions.size())
        state->get_legal_actions();

    auto actions = state->legal_actions;

    int k = depth;
    for (int i = 0; i < depth; i++)
    {
        k = rand() / k;
    }

    State *tmp;
    Move ret; //= actions[k%actions.size()]; // in case all the value is the same(not yet minimax / alpha prune)

    int max;

    if (!state->player)
    {
        max = -1000000;
        for (Move i : actions)
        {

            tmp = state->next_state(i);
            int val = minimax(tmp, depth - 1, false);

            if (val > max)
            {
                max = val;
                ret = i;
            }
        }
    }
    else
    {
        max = 1000000;
        for (Move i : actions)
        {

            tmp = state->next_state(i);
            int val = minimax(tmp, depth - 1, true);

            if (val < max)
            {
                max = val;
                ret = i;
            }
        }
    }

    return ret;
}
