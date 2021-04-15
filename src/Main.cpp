#include "handler/InputHandler.h"
#include <iostream>

void PrintObject(Object obj)
{
	using namespace std;

	cout << "-- object information --" << endl;
	cout << "name:" << obj.name << endl;
	cout << "position:(" << obj.x << "," << obj.y << ")" << endl;
}

void PrintMessage(std::string _msg)
{
	using namespace std;

	cout << _msg << endl;
}

int main(void)
{
	typedef MoveArgs::MoveDirection MD;

	Object object { "obj chan", 10, 10 };
	InputHandler ih;

	ih.object = &object;

	PrintMessage("上の方に移動");
	ih.Move(MD::UP);
	PrintObject(object);

	PrintMessage("左の方に移動");
	ih.Move(MD::LEFT);
	PrintObject(object);

	PrintMessage("前の動作を取消");
	ih.Undo();
	PrintObject(object);

	PrintMessage("前の動作を取消");
	ih.Undo();
	PrintObject(object);

	PrintMessage("前の取り消した動作を再実行");
	ih.Redo();
	PrintObject(object);

	PrintMessage("前の取り消した動作を再実行");
	ih.Redo();
	PrintObject(object);

	return 0;
}
