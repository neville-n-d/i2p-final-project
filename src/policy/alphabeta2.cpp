
#include <cstdlib>
#include <iostream>
#include <climits>
#include "../state/state.hpp"
#include "./alphabeta2.hpp"
using namespace std;
/**
 * @brief Randomly get a legal action
 *
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move
 */
double alpha_beta2(State *root, int depth, bool state, double alpha, double beta)
{

    // cout << "==========" << " DEPTH LEVEL " << depth << " ==========" << endl;
    if (!root->legal_actions.size())
        root->get_legal_actions();
    if (depth <= 0 || !root->legal_actions.size())
    {
        // std::cout << "swc " << root->evaluate() << "dwdw";
        return root->evaluate();
    }

    // MAXIMIZING
    else if (state)
    {
        auto actions = root->legal_actions;
        double val = -1046;
        for (auto action : actions)
        {
            State *nextState = root->next_state(action);
            val = max(val, alpha_beta2(nextState, depth - 1, 0, alpha, beta));
            // std::cout << "val = " << val << " " << std::endl;
            alpha = max(alpha, val);
            if (alpha >= beta)
            {
                break;
            }
        }
        // std::cout << "max val = " << alpha << " " << std::endl;
        return val;
    }
    // MINIMIZING
    else
    {
        auto actions = root->legal_actions;
        double val = 1046;
        for (auto action : actions)
        {
            State *nextState = root->next_state(action);
            val = min(val, alpha_beta2(nextState, depth - 1, 1, alpha, beta));
            // std::cout << "val = " << val << " " << std::endl;
            alpha = min(alpha, val);
            if (alpha >= beta)
            {
                break;
            }
        }
        // std::cout << "max val = " << alpha << " " << std::endl;
        return val;
    }
}
Move playerColor2(int player, State *state, int depth)
{
    if (!state->legal_actions.size())
        state->get_legal_actions();
    double alpha = -1046;
    double beta = 1046;
    Move retMove;
    auto actions = state->legal_actions;
    if (player == 0)
    {
        double now = -1046;
        for (auto action : actions)
        {
            State *nextState = state->next_state(action);
            double temp = alpha_beta2(nextState, depth - 1, false, alpha, beta);
            // std::cout << temp << std::endl;
            if (temp > now)
            {
                alpha = temp;
                now = temp;
                retMove = action;
            }
            if (alpha >= beta)
            {

                break;
            }
        }
        return retMove;
    }
    else
    {
        double now = 1046;
        for (auto action : actions)
        {
            State *nextState = state->next_state(action);
            double temp = alpha_beta2(nextState, depth - 1, true, alpha, beta);
            // std::cout << temp << std::endl;
            if (temp < now)
            {
                beta = temp;
                now = temp;
                retMove = action;
            }
            if (alpha >= beta)
            {
                break;
            }
        }
        return retMove;
    }
}
Move Alphabeta2::get_move(State *state, int depth)
{
    int player = state->player;
    return playerColor2(player, state, depth);
}