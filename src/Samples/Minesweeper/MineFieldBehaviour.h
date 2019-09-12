//◦ Playrix ◦
#pragma once
#include "Visual/Behaviour/Behaviour.h"
#include "Visual/Component/SpriteComponent.h"

namespace Minesweeper
{
	struct FieldPoint
	{
		int x;
		int y;

		bool operator==(const FieldPoint& other) const
		{
			return x == other.x && y == other.y;
		}

		bool operator<(const FieldPoint& other) const
		{
			return x < other.x || (x == other.x && y < other.y);
		}
	};

	class MineFieldBehaviour : public Visual::Behaviour
	{
		VISUAL_CLASS(Visual::Behaviour)

	public :
		using Ptr = boost::intrusive_ptr<MineFieldBehaviour>;
		using WeakPtr = intrusive_weak_ptr<MineFieldBehaviour>;

		/// @method
		void OpenField();

		/// @method
		void FlagField();

		/// @method
		void OpenAround();

		bool IsOpen() const;

		bool IsFlag() const;

		bool IsMine() const;

		unsigned short GetSouroundingMineCount() const;

		void SetPoint(const FieldPoint& point);

		void SetMine();

		void IncreaseMineCount();

	protected:
		void OnStart() override;

	private :
		/// @property
		Visual::RefWrapper<Visual::SpriteComponent> _sprite;

		bool _open = false;
		bool _flag = false;
		bool _mine = false;
		unsigned short _souroundingMineCount = 0;
		FieldPoint _point;
	};
}