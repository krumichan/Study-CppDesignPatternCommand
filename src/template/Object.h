#pragma once

#include <string>

/**
 * 全てのオブジェクトの基底クラス
 */
class Object
{
public:
	/**
	 * コンストラクタ
	 */
	Object();

	/**
	 * コンストラクタ
	 */
	Object(std::string);

	/**
	 * コンストラクタ
	 */
	Object(float, float);

	/**
	 * コンストラクタ
	 */
	Object(std::string, float, float);

	/**
	 * デストラクタ
	 */
	virtual ~Object();

public:
	/**
	 * オブジェクト名
	 */
	std::string name;

	/**
	 * X位置
	 */
	float x;

	/**
	 * Y位置
	 */
	float y;
};
