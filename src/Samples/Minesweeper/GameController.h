//◦ Playrix ◦
#pragma once
#include "Visual/Behaviour/Behaviour.h"
#include "MineFieldBehaviour.h"

namespace Minesweeper
{
	class GameController : public Visual::Behaviour
	{
		VISUAL_CLASS(Visual::Behaviour)

	public :
		/// @property
		float _fieldSize = 22.0;
		/// @property
		int _gridSize = 12;
		/// @property
		int _mineCount = 15;
		/// @property @assetType(SceneObject)
		std::string _field;

	protected:
		void OnStart() override;
		
	private:
		std::map<FieldPoint, MineFieldBehaviour::WeakPtr> _fields;

		void SpawnGrid();
		void SetupFields();
		bool SetMine(const FieldPoint& point);

	};
}