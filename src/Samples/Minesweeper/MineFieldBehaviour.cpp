//◦ Playrix ◦
#include "MineFieldBehaviour.h"
#include <string.h>

void Minesweeper::MineFieldBehaviour::OnStart()
{
	
}

void Minesweeper::MineFieldBehaviour::OpenField()
{
	if (_flag)
	{
		return;
	}

	std::string id;
	if (_mine)
	{
		id = "Mine";
	}
	else 
	{
		id = "Empty" + std::to_string(_souroundingMineCount);
	}
	(*_sprite.Get()).SetId(id);
}

void Minesweeper::MineFieldBehaviour::FlagField()
{
	if (_open)
	{
		return;
	}

	_flag = !_flag;
	std::string id = _flag ? "Flag" : "Default";
	(*_sprite.Get()).SetId(id);
}

void Minesweeper::MineFieldBehaviour::OpenAround()
{

}

bool Minesweeper::MineFieldBehaviour::IsOpen() const
{
	return _open;
}

bool Minesweeper::MineFieldBehaviour::IsFlag() const
{
	return _flag;
}

bool Minesweeper::MineFieldBehaviour::IsMine() const
{
	return _mine;
}

unsigned short Minesweeper::MineFieldBehaviour::GetSouroundingMineCount() const
{
	return _souroundingMineCount;
}

void Minesweeper::MineFieldBehaviour::SetPoint(const FieldPoint& point)
{
	_point = point;
}

void Minesweeper::MineFieldBehaviour::SetMine()
{
	_mine = true;
}

void Minesweeper::MineFieldBehaviour::IncreaseMineCount()
{
	++_souroundingMineCount;
}


