#pragma once

#include "../template/Object.h"
#include "../movement/move/MoveCommandReceiver.h"
#include "../movement/move/MoveCommand.h"

#include <memory>
#include <list>
using namespace std;

class InputHandler
{
public:
	/**
	 * コンストラクタ
	 */
	InputHandler();

public:
	void Undo();
	void Redo();
	void Move(MoveArgs::MoveDirection);
	void Attack();

private:
	list<unique_ptr<AbstractCommand>> commands;
	list<unique_ptr<AbstractCommand>> undoCommands;
	int curCmdIdx;

public:
	float moveDistance;
	Object* object;

private: ///　移動関連
	MoveCommandReceiver moveCommandReceiver;
};
