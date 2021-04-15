#include "MoveCommandReceiver.h"
#include "MoveArgs.h"
#include <iostream>

using namespace std;

/**
 * コマンドの実際動作を実行する。
 * @param 動作対象
 * @param 動作に必要な引数
 */
void MoveCommandReceiver::Operation(Object* _object, Arguments& _args)
{
	typedef MoveArgs::MoveDirection MD;

	//　引数基底クラスを移動引数クラスにキャスト
	MoveArgs& args = dynamic_cast<MoveArgs&>(_args);
	MD direction = args.direction;
	int distance = args.distance;

	switch (direction)
	{
	case MD::UP:
		this->MoveY(_object, distance);
		break;

	case MD::DOWN:
		this->MoveY(_object, -distance);
		break;

	case MD::LEFT:
		this->MoveX(_object, -distance);
		break;

	case MD::RIGHT:
		this->MoveX(_object, distance);
		break;
	}

}

/**
 * X方向に移動
 * @param 移動対象
 * @param 移動距離
 */
void MoveCommandReceiver::MoveX(Object* _object, int _distance)
{
	_object->x += _distance;
}

/**
 * Y方向に移動
 * @param 移動対象
 * @param 移動距離
 */
void MoveCommandReceiver::MoveY(Object* _object, int _distance)
{
	_object->y += _distance;
}
