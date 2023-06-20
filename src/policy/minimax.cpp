#include <cstdlib>
#include <iostream>
#include <climits>
#include "../state/state.hpp"
#include "./minimax.hpp"
/**
 * @brief Randomly get a legal action
 *
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move
 */
double minimax(State *root, int depth, bool state, int player)
{

    // cout << "==========" << " DEPTH LEVEL " << depth << " ==========" << endl;

    if (depth <= 0)
    {
        // std::cout << "swc " << root->evaluate() << "dwdw";
        return root->evaluate();
    }

    // MAXIMIZING
    else if (state)
    {
        int low = -1046;
        if (!root->legal_actions.size())
            root->get_legal_actions();
        auto actions = root->legal_actions;
        for (auto action : actions)
        {
            State *nextState = root->next_state(action);
            double val = minimax(nextState, depth - 1, 0, player);
            // std::cout << "val = " << val << " " << std::endl;
            if (val > low)
            {
                low = val;
            }
        }
        // std::cout << "max val = " << alpha << " " << std::endl;
        return low;
    }
    // MINIMIZING
    else
    {
        int high = 1046;
        if (!root->legal_actions.size())
            root->get_legal_actions();
        auto actions = root->legal_actions;
        for (auto action : actions)
        {
            State *nextState = root->next_state(action);
            double val = minimax(nextState, depth - 1, 1, player);
            // std::cout << "val = " << val << " " << std::endl;
            if (val < high)
            {
                high = val;
            }
        }
        // std::cout << "min val = " << beta << " " << std::endl;
        return high;
    }
}
Move playerTurn(int player, State *state, int depth)
{
    if (!state->legal_actions.size())
        state->get_legal_actions();

    int same = 0;
    Move retMove;
    auto actions = state->legal_actions;
    if (player == 0)
    {
        double now = -1046;
        for (auto action : actions)
        {
            State *nextState = state->next_state(action);
            double temp = minimax(nextState, depth - 1, 0, player);
            // std::cout << temp << std::endl;
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
        // if (same >= actions.size())
        // {
        //     int k = depth;
        //     for (int i = 0; i < depth; i++)
        //     {
        //         k = rand() / k;
        //     }
        //     retMove = actions[(rand() + depth) % actions.size()];
        // }
        return retMove;
    }
    else
    {
        double now = 1046;
        for (auto action : actions)
        {
            State *nextState = state->next_state(action);
            double temp = minimax(nextState, depth - 1, 1, player);
            // std::cout << temp << std::endl;
            if (temp < now)
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
        // if (same >= actions.size())
        // {
        //     int k = depth;
        //     for (int i = 0; i < depth; i++)
        //     {
        //         k = rand() / k;
        //     }
        //     retMove = actions[(rand() + depth) % actions.size()];
        // }
        return retMove;
    }
}
Move Minimax::get_move(State *state, int depth)
{
    int player = state->player;
    return playerTurn(player, state, depth);
}