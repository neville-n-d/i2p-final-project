
#include <cstdlib>
#include <iostream>
#include <climits>
#include "../state/state.hpp"
#include "./alphabeta.hpp"
/**
 * @brief Randomly get a legal action
 *
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move
 */
double alpha_beta(State *root, int depth, bool state, double alpha, double beta)
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
        for (auto action : actions)
        {
            State *nextState = root->next_state(action);
            double val = alpha_beta(nextState, depth - 1, 0, alpha, beta);
            // std::cout << "val = " << val << " " << std::endl;
            if (val > alpha)
            {
                alpha = val;
            }
            if (alpha >= beta)
            {
                break;
            }
        }
        // std::cout << "max val = " << alpha << " " << std::endl;
        return alpha;
    }
    // MINIMIZING
    else
    {
        auto actions = root->legal_actions;
        for (auto action : actions)
        {
            State *nextState = root->next_state(action);
            double val = alpha_beta(nextState, depth - 1, 1, alpha, beta);
            // std::cout << "val = " << val << " " << std::endl;
            if (val < beta)
            {
                beta = val;
            }
            if (alpha >= beta)
            {
                break;
            }
        }
        // std::cout << "min val = " << beta << " " << std::endl;
        return beta;
    }
}
Move playerColor(int player, State *state, int depth)
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
            double temp = alpha_beta(nextState, depth - 1, false, alpha, beta);
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
            double temp = alpha_beta(nextState, depth - 1, true, alpha, beta);
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
Move Alphabeta::get_move(State *state, int depth)
{
    int player = state->player;
    return playerColor(player, state, depth);
}