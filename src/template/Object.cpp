#include "Object.h"

/**
 * コンストラクタ
 */
Object::Object()
{
	this->name = "empty object";
	this->x = 0.0f;
	this->y = 0.0f;
}

/**
 * コンストラクタ
 */
Object::Object(std::string _name)
{
	this->name = _name;
	this->x = 0.0f;
	this->y = 0.0f;
}

/**
 * コンストラクタ
 */
Object::Object(float _x, float _y)
{
	this->name = "empty object";
	this->x = _x;
	this->y = _y;
}

/**
 * コンストラクタ
 */
Object::Object(std::string _name, float _x, float _y)
{
	this->name = _name;
	this->x = _x;
	this->y = _y;
}

/**
 * デストラクタ
 */
Object::~Object()
{

}
