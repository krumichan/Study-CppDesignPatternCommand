#include "MoveCommand.h"

/**
 * コンストラクタ
 * @param _object 動作対象
 * @param _receiver Receiver
 * @param _args 引数
 */
MoveCommand::MoveCommand(Object* _object, MoveCommandReceiver* _receiver, MoveArgs _args)
{
	this->mObject = _object;
	this->mReceiver = _receiver;
	this->mArgs = _args;
}

/**
 * コマンド実行
 */
void MoveCommand::Execute()
{
	this->mReceiver->Operation(this->mObject, this->mArgs);
}

/**
 * コマンド実行取消
 */
void MoveCommand::UnExecute()
{
	MoveArgs tmpArgs = this->mArgs;
	tmpArgs.direction = InverseDirection(this->mArgs.direction);
	this->mReceiver->Operation(this->mObject, tmpArgs);
}

/**
 * 移動方向を逆にする。
 */
MoveArgs::MoveDirection MoveCommand::InverseDirection(MoveArgs::MoveDirection _direction)
{
	typedef MoveArgs::MoveDirection MD;

	MD curDirection = _direction;
	MD result;

	switch (curDirection)
	{
	case MD::UP:
		result = MD::DOWN;
		break;

	case MD::DOWN:
		result = MD::UP;
		break;

	case MD::LEFT:
		result = MD::RIGHT;
		break;

	case MD::RIGHT:
		result = MD::LEFT;
		break;
	}

	return result;
}
