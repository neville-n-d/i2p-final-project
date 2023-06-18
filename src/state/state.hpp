#ifndef __STATE_H__
#define __STATE_H__

#include <string>
#include <cstdlib>
#include <vector>
#include <utility>
#include <list>

#include "../config.hpp"

typedef std::pair<size_t, size_t> Point;
typedef std::pair<Point, Point> Move;
class Board
{
public:
  int blackValue[7][BOARD_H][BOARD_W] = {{
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                         },
                                         {
                                             {5, 5, 5, 5, 5},
                                             {0, 0, 0, 0, 0},
                                             {4, 3, 1, 5, 1},
                                             {1, 1, 1, 10, 5},
                                             {0, 0, 0, 0, 0},
                                             {5, 5, 5, 5, 5},
                                         },
                                         {
                                             {0, 0, 0, 0, -1},
                                             {0, 0, 0, 0, 0},
                                             {10, 0, 0, 0, 5},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {15, 0, 0, 0, 0},
                                         },
                                         {
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                         },
                                         {
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                         },
                                         {
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 10, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                         },
                                         {
                                             {0, 5, 10, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                         }};
  int whiteValue[7][BOARD_H][BOARD_W] = {{
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                         },
                                         {
                                             {5, 5, 5, 5, 5},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                         },
                                         {
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                         },
                                         {
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                         },
                                         {
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                         },
                                         {
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                         },
                                         {
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0},
                                         }};

  char board[2][BOARD_H][BOARD_W] = {{
                                         // white
                                         {0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0},
                                         {1, 1, 1, 1, 1},
                                         {2, 3, 4, 5, 6},
                                     },
                                     {
                                         // black
                                         {6, 5, 4, 3, 2},
                                         {1, 1, 1, 1, 1},
                                         {0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0},
                                     }};
};

enum GameState
{
  UNKNOWN = 0,
  WIN,
  DRAW,
  NONE
};

class State
{
public:
  // You may want to add more property for a state
  GameState game_state = UNKNOWN;
  Board board;
  int player = 0;
  std::vector<Move> legal_actions;

  State(){};
  State(int player) : player(player){};
  State(Board board) : board(board){};
  State(Board board, int player) : board(board), player(player){};
  std::list<State> childState;

  int evaluate();
  State *next_state(Move move);
  void get_legal_actions();
  std::string encode_output();
  std::string encode_state();
};

#endif