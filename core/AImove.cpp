//Pairut Dumkuengthanant
//64856070

#include <iostream>
#include "AIthello.hpp"
#include <ics46/factory/DynamicFactory.hpp>
#include "OthelloAI.hpp"
#include "OthelloBoard.hpp"
#include "OthelloCell.hpp"
#include <utility>

#include <vector>

ICS46_DYNAMIC_FACTORY_REGISTER(OthelloAI, pdumkuen::AIthello, "AI_Loser(REQUIRED)");
namespace pdumkuen
{
std::pair<int, int> pdumkuen::AIthello::chooseMove(const OthelloGameState& state)
{

	//std::cout<<"begin turn"<<std::endl;
	int result=0;
	//int x,y;
	//int total=state.blackScore()+state.whiteScore();
	std::pair<int, int> move;
	_w=state.board().width();
	_h=state.board().height();

	int turn;
	std::unique_ptr<OthelloGameState> clone_state;
	clone_state=state.clone();
	if(state.isWhiteTurn())
	{
		turn=0;
	}
	if(state.isBlackTurn())
	{
		turn=1;
	}
	int value=0;
	std::vector<std::pair<int, int>> lst_moves;
	lst_moves=avail_move(clone_state);

	result=search(clone_state, 5, turn);
	for(std::vector<std::pair<int, int>>::const_iterator it=lst_moves.begin();it!=lst_moves.end();it++)
	{

		clone_state=state.clone();
		make_move(clone_state,it->first,it->second);
		value=eval(clone_state, turn);

		//std::cout<<"result: "<<result<<std::endl;
		//std::cout<<"value: "<<value<<std::endl;
		if(result>value)
		{
				//std::cout<<"result is greater"<<std::endl;
				
				if((it->first<3)||(it->first>(_h-3))||(it->second<3)||(it->second>(_w-3)))
				{
					//std::cout<<"1"<<std::endl;
					move=std::make_pair(it->first, it->second);
				}
				
				if((it->first==0)||(it->second==0)||(it->first==_w)||(it->second==_h))
				{
					//std::cout<<"3"<<std::endl;
					move=std::make_pair(it->first, it->second);
				}
				if((it->first==0&&it->second==0)||(it->first==_w&&it->second==_h)||
					(it->first==_w&&it->second==0)||(it->first==0&&it->second==_h))
				{
					//std::cout<<"4 here--------"<<std::endl;
					move=std::make_pair(it->first, it->second);
				}
				
		}
		
			//std::cout<<"value is greater"<<std::endl;
			move=std::make_pair(it->first, it->second);
		

	}
	
	//move=move_result(clone_state, lst_moves,1);
	
	return std::make_pair(move.first,move.second);

}
}