//◦ Playrix ◦
#include "GameController.h"
#include <Gdb/G_SOCollection.h>

void Minesweeper::GameController::OnStart()
{
	if (_field.size() <= 0)
	{
		return;
	}

	SpawnGrid();
	SetupFields();
}

void Minesweeper::GameController::SpawnGrid()
{

	auto row = 0;
	for (auto i = 0; i < _gridSize; ++i)
	{
		auto col = 0;
		for (auto j = 0; j < _gridSize; ++j)
		{
			auto field = GetScene()->InstantiateToScene(_field);
			auto pos = GetTransform().GetWorldPosition2D();
			auto fieldBehaviour = field.GetRoot().GetBehaviour<MineFieldBehaviour>();
			FieldPoint gridPos = { row, col };

			fieldBehaviour.get()->SetPoint(gridPos);
			_fields[gridPos] = fieldBehaviour;
			pos += {gridPos.x * _fieldSize, gridPos.y * _fieldSize };
			field.GetTransform().SetWorldPosition2D(pos);
			++col;
		}

		++row;
	}
}

void Minesweeper::GameController::SetupFields()
{
	auto minesSet = 0;

	while (minesSet < _mineCount)
	{
		FieldPoint randPoint = { rand() % _gridSize, rand() % _gridSize };
		if (SetMine(randPoint))
		{
			++minesSet;
		}
	}


}

bool Minesweeper::GameController::SetMine(const FieldPoint& point)
{
	if (_fields[point].lock().get()->IsMine())
	{
		return false;
	}

	_fields[point].lock().get()->SetMine();
	for (auto i = -1; i < 2; ++i)
	{
		for (auto j = -1; j < 2; ++j)
		{
			FieldPoint neighbour = { point.x + i, point.y + j };
			if (neighbour.x >= 0 && neighbour.x < _gridSize && neighbour.y >= 0 && neighbour.y < _gridSize)
			{
				_fields[neighbour].lock().get()->IncreaseMineCount();
			}
		}
	}

	return true;
}