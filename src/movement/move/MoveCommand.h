#pragma once

#include "../../template/AbstractCommand.h"
#include "MoveArgs.h"
#include "MoveCommandReceiver.h"

/**
 * 移動コマンド
 */
class MoveCommand : public AbstractCommand
{
private:
	MoveArgs mArgs;
	MoveCommandReceiver* mReceiver;
public: Object* mObject;

public:
	/**
	 * コンストラクタ
	 * @param 動作対象
	 * @param Receiver
	 * @param 引数
	 */
	MoveCommand(Object*, MoveCommandReceiver*, MoveArgs);

public:
	/**
	 * コマンド実行
	 */
	void Execute() override;

	/**
	 * コマンド実行取消
	 */
	void UnExecute() override;

private:
	/**
	 * 移動方向を逆にする。
	 */
	MoveArgs::MoveDirection InverseDirection(MoveArgs::MoveDirection);
};
