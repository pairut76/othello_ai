
//Pairut Dumkuengthanant
//64856070

#include <iostream>
#include "OthelloAI.hpp"
#include <vector>
#include <utility>
#include "OthelloCell.hpp"
#include "OthelloBoard.hpp"
#include <list>
#include <vector>
namespace pdumkuen
{
	class AIthello: public OthelloAI
	{
		
		public:
			int _w, _h;
		virtual std::pair<int, int> chooseMove(const OthelloGameState& state);

		
		void print_state(std::unique_ptr<OthelloGameState>& state)
		{
			OthelloCell cell;
			for(int i=0; i<_h;i++)
			{
				for(int j=0;j<_w;j++)
				{
					cell=state->board().cellAt(j,i);
					
					if(cell==OthelloCell::empty)
						std::cout<<" * ";
					if(cell==OthelloCell::black)
						std::cout<<" B ";
					if(cell==OthelloCell::white)
						std::cout<<" W ";
						
				}
				std::cout<<"\n";
			}
		}
		
		int make_move(std::unique_ptr<OthelloGameState>& state, int x, int y)
		{
			if(state->isValidMove(x,y))
			{
				//std::cout<<"made move at: "<<x<<"	"<<y<<std::endl;
				state->makeMove(x,y);
				//std::cout<<"after makemove"<<std::endl;
				//print_state(state);
				if(state->isBlackTurn())
				{
					//std::cout<<"white move: "<<std::endl;
					return state->whiteScore();
				}
				else
				{
					//std::cout<<"black move: "<<std::endl;
					return state->blackScore();
				}
			}
			return -1;
		}
		/*
		std::pair<int, int> move_result(std::unique_ptr<OthelloGameState>& st, std::vector<std::pair<int,int>> moves_test, int boo)
		{
			int x, y;
			int result=0;
			int new_num;
			std::unique_ptr<OthelloGameState> test_state;
			//std::cout<<"starting tests!!"<<std::endl;
			for(std::vector<std::pair<int, int>>::const_iterator it=moves_test.begin();it!=moves_test.end();it++)
			{
				//std::cout<<"test coordinates: "<<it->first<<"	"<<it->second<<std::endl;
				test_state=st->clone();
				new_num=make_move(test_state,(it->first),(it->second));
				if(result==0)
				{
					result=new_num;
				}
				if(boo==1&&result<=new_num)
				{
					x=(it->first);
					y=(it->second);
					result=new_num;

				}
				if(boo==-1&&result>=new_num)
				{
					x=(it->first);
					y=(it->second);
					result=new_num;
				}

			}
			return std::make_pair(x,y);
		}

		std::pair<int, int> dif_move(std::unique_ptr<OthelloGameState>& state, std::vector<std::pair<int,int>> moves_test)
		{
			
			//std::cout<<"starting tests!!"<<std::endl;
			for(std::vector<std::pair<int, int>>::const_iterator it=moves_test.begin();it!=moves_test.end();it++)
			{
				//std::cout<<"test coordinates dif_moves: "<<it->first<<"	"<<it->second<<std::endl;
				if((it->first==0&&it->second==0)||(it->first==_w&&it->second==_h)||
					(it->first==_w&&it->second==0)||(it->first==0&&it->second==_h))
				{
					return std::make_pair(it->first, it->second);
				}
				if((it->first==0)||(it->second==0)||(it->first==_w)||(it->second==_h))
				{
					return std::make_pair(it->first, it->second);
				}
			}
			return std::make_pair(-1,-1);	
		}

		std::pair<int, int> better_moves(std::unique_ptr<OthelloGameState>& state, std::vector<std::pair<int,int>> moves_test)
		{
			
			//std::cout<<"starting tests!!"<<std::endl;
			for(std::vector<std::pair<int, int>>::const_iterator it=moves_test.begin();it!=moves_test.end();it++)
			{
				if(it->first<=3||it->first>=5)
				{
					return std::make_pair(it->first, it->second);
				}
				if(it->second<=3||it->second>=5)
				{
					return std::make_pair(it->first, it->second);
				}

			}
			return std::make_pair(-1,-1);
		}
*/
		std::vector<std::pair<int, int>> avail_move(std::unique_ptr<OthelloGameState>& state)
		{
			std::vector<std::pair<int, int>> list_moves;
			
			for(int i=0; i<_h; i++)
			{
				for(int j=0; j<_w; j++)
				{

					if(state->isValidMove(j,i))
					{
						list_moves.push_back(std::make_pair(j, i));
					}
				}
			}
			return list_moves;
		}
		int eval(std::unique_ptr<OthelloGameState>& state, int turn)
		{
			int result=0;
			OthelloCell cell;
			if(turn==0)
			{
				result=state->whiteScore()-state->blackScore();
			}
			else
			{
				result=state->blackScore()-state->whiteScore();
			}
			for(int i=0; i<_h;i++)
			{
				for(int j=0;j<_w;j++)
				{
					cell=state->board().cellAt(j,i);
					if((i==0&&j==0)||(i==(_h-1)&&j==(_w-1))||(i==(_h-1)&&j==0)||(i==0&&j==(_w-1)))
					{

						if((cell==OthelloCell::white&&turn==0)||(cell==OthelloCell::black&&turn==1))
							result+=8;
						else
							result-=8;
					}

					if((i==0)||(j==0)||(j==(_w-1))||(i==(_h-1)))
					{
						if((cell==OthelloCell::white&&turn==0)||(cell==OthelloCell::black&&turn==1))
							result+=4;
						else
							result-=4;
					}
					if((i<3)||(j<3)||(i>(_h-3)||(j>(_w-3))))
					{
						if((cell==OthelloCell::white&&turn==0)||(cell==OthelloCell::black&&turn==1))
							result+=2;
						else
							result-=2;
					}
				}
			}
			return result;
			
		}
		
		int search(std::unique_ptr<OthelloGameState>& state, int depth, int turn)
		{
			std::vector<std::pair<int, int>> list_moves;
			std::pair<int, int> move;
			int value_min=0;
			int value_max=0;
			int new_num=0;
			std::unique_ptr<OthelloGameState> test_state;
			if( depth==0||state->isGameOver())
			{

				return eval(state, turn);
			}
			else
			{
				//if((state->isWhite()&&test_state->isWite())||state->isBlack()&&test_state->isWhite())
				if((turn==0&&state->isWhiteTurn())||(turn==1&&state->isBlackTurn()))
				{
					//std::cout<<"ai turn: "<<std::endl;
					list_moves=avail_move(state);//creates list of available moves
					for(std::vector<std::pair<int, int>>::const_iterator it=list_moves.begin();it!=list_moves.end();it++)
					{
						
						test_state=state->clone();
						make_move(test_state,it->first,it->second);

						new_num=search(test_state, depth-1, turn);
						if(value_max<new_num)
						{
							value_max=new_num;
						}
					}
					return value_max;
				}
				else
				{
					list_moves=avail_move(state);//creates list of available moves
					for(std::vector<std::pair<int, int>>::const_iterator it=list_moves.begin();it!=list_moves.end();it++)
					{
						test_state=state->clone();
						make_move(test_state,it->first, it->second);
						new_num=search(test_state, depth-1, turn);
						if(value_min>new_num)
						{
							value_min=new_num;
						}
					}
					
				}
				return value_min;
			}
		}

		
	};
}