#include "InputHandler.h"
#include <algorithm>

InputHandler::InputHandler()
{
	this->moveDistance = 10;
	this->object = nullptr;
	this->curCmdIdx = 0;
}

void InputHandler::Undo()
{
	if (this->object == nullptr)
	{
		return;
	}

	if (this->curCmdIdx == 0)
	{
		return;
	}

	//　最後の要素取得
	unique_ptr<AbstractCommand> command = move(commands.back());

	//　最後要素の動作取消実行
	command->UnExecute();

	//　コマンドリストから最後要素削除
	commands.pop_back();

	//　動作取消リストに追加
	undoCommands.push_back(move(command));

	//　インデックス更新
	this->curCmdIdx--;
}

void InputHandler::Redo()
{
	if (this->object == nullptr)
	{
		return;
	}

	if (this->undoCommands.empty())
	{
		return;
	}

	//　最後取り消した要素取得
	unique_ptr<AbstractCommand> command = move(undoCommands.back());

	//　最後取り消した要素の再動作実行
	command->Execute();

	// 動作取消リスト最後取り消した要素削除
	undoCommands.pop_back();

	//　コマンドリストに追加
	commands.push_back(move(command));

	//　インデックス更新
	this->curCmdIdx++;
}

void InputHandler::Move(MoveArgs::MoveDirection _direction)
{
	if (this->object == nullptr)
	{
		return;
	}

	MoveArgs args;
	args.direction = _direction;
	args.distance = this->moveDistance;
	unique_ptr<MoveCommand> moveCommand = make_unique<MoveCommand>(this->object, &this->moveCommandReceiver, args);
	moveCommand->Execute();
	commands.push_back(move(moveCommand));
	undoCommands.clear();
	this->curCmdIdx++;
}
